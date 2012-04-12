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
#include <stdio.h>
#include <string>
#include <iostream>
#include "sphere.h"


RenderThread::RenderThread(Renderer *parent) :
    QThread(),
    renderer(parent)
{
    doRendering = true;
    doResize = false;
    doRefresh = true;
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

        if (doRefresh){
            centralSphere.createSphere(); // send file names through here
            doRefresh = false;
        }
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
    glTranslatef(0.0f, 0.0f, -25.0f);            // move 5 units into the screen
    glRotatef(FrameCounter*0.5,0,1,0.0f);     // rotate y-axis

    // draw labels
    int R = centralSphere.getRadius();

    glColor3f(1,1,1);
    renderer->renderText(0,R*2,R, "TAG 1");

    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, R*2, R);
    glEnd( );

    renderer->renderText(0,-R*2,R*2, "TAG 2");

    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0,-R*2,R*2);
    glEnd( );

    renderer->renderText(-R*2,R*2,0, "TAG 3");

    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-R*2,R*2,0);
    glEnd( );

    renderer->renderText(R*2,-R*2,0, "TAG 4");

    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(R*2,-R*2,0);
    glEnd( );

    renderer->renderText(0,R*0.7,-R*2, "TAG 5");

    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0,R*0.7,-R*2);
    glEnd( );

    renderer->renderText(0,-R*0.2,R*2, "TAG 6");

    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0,-R*0.2,R*2);
    glEnd( );

    renderer->renderText(-R,-R*2,-R, "TAG 7");

    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-R,-R*2,-R);
    glEnd( );

    // draw central sphere
    int number_of_faces = centralSphere.getNumberOfFaces();

    /* not currently working - for drawing labels
    const std::string filenames[8] = {"label 1", "label 2", "label3", "label 4", "label 5", "label 6", "label 7", "label 8"}; //fix - remove - only for testing
    int n_filenames = 8; // fix - this will eventually be passed from controller
    */

    for (int i=0; i<=number_of_faces; i++){
        /* not currently working - for drawing labels
        if (i<n_filenames){
            scene[i].addText(filenames[i], );
            textureId[i] = scene[i].renderToTexture();
        }
        */

        QVector3D* vp = new QVector3D();
        QVector3D v = *vp;
        Face face = centralSphere.getface(i);
        glBegin(GL_QUADS);
            /* not currently working - for drawing labels
            if (i<n_filenames){
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, textureId[i]);
            }
            */

            glColor3f(0.,0.,1.);
            v = face.getv(1);
            //printf("[%f, %f, %f]", v.x(), v.y(), v.z());
            //printf("\n");
            glVertex3f(v.x(), v.z(), v.y());

            glColor3f(1.,0.,0.);
            v = face.getv(2);
            //printf("[%f, %f, %f]", v.x(), v.y(), v.z());
            //printf("\n");
            glVertex3f(v.x(), v.z(), v.y());

            glColor3f(0.,0.,1.);
            v = face.getv(3);
            //printf("[%f, %f, %f]", v.x(), v.y(), v.z());
            //printf("\n");
            glVertex3f(v.x(), v.z(), v.y());

            glColor3f(1.,0.,0.);
            v = face.getv(4);
            //printf("[%f, %f, %f]", v.x(), v.y(), v.z());
           // printf("\n");
            glVertex3f(v.x(), v.z(), v.y());
            //printf("\n\n");

            /* not currently working - for drawing labels
            if (i<n_filenames){
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, 0);
            }
            */
        glEnd();
    }


}
