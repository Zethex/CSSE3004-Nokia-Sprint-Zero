#include "renderer.h"

Renderer::Renderer(QWidget *parent) :
    QGLWidget(parent),
    renderThread(this)
{
    setAutoBufferSwap(false);
}

void Renderer::initRenderThread(void)
{
    doneCurrent();
    renderThread.start();
}

void Renderer::stopRenderThread(void)
{
    renderThread.stop();
    renderThread.wait();
}

void Renderer::resizeEvent(QResizeEvent *evt)
{
    renderThread.resizeViewport(evt->size());
}

void Renderer::paintEvent(QPaintEvent *evt)
{
    // Do Nothing. Let The Thread Do The Work
}

void Renderer::closeEvent(QCloseEvent *evt)
{
    stopRenderThread();
    QGLWidget::closeEvent(evt);
}
