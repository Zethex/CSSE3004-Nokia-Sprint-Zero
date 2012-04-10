#include "renderthread.h"
#include "renderer.h"
#ifdef __APPLE__
    #include <glu.h>
#endif
#ifdef WIN32
    #include <GL/glu.h>
#endif
#include <stdio.h>

#include <QLabel>
#include <math.h>

RenderThread::RenderThread(Renderer *parent) :
    QThread(),
    renderer(parent)
{
    doRendering = true;
    doResize = false;
    FrameCounter = 0;
}

void RenderThread::resizeViewport(const QSize &size)
{
    w = size.width();
    h = size.height();
    doResize = true;
}

void RenderThread::stop()
{
    doRendering = false;
}

void RenderThread::run()
{
    renderer->makeCurrent();
    GLInit();

    while (doRendering)
    {
        if (doResize)
        {
            GLResize(w, h);
            doResize = false;
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        paintGL();

        FrameCounter++;
        renderer->swapBuffers();

        msleep(16); // wait 16ms => about 60 FPS
    }
}

void RenderThread::GLInit()
{
    glClearColor(0.05f, 0.05f, 0.1f, 0.0f);
}

void RenderThread::GLResize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(45.0, ((GLfloat)width)/((GLfloat)height), 0.1f, 1000.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void RenderThread::paintGL()
{

}
