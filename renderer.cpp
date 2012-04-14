#include "renderer.h"

Renderer::Renderer(QWidget *parent) :
    QGLWidget(parent),
    renderThread(this)
{
    setAutoBufferSwap(false);
    setFocusPolicy(Qt::StrongFocus);
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

void Renderer::keyPressEvent(QKeyEvent *evt)
{
    printf("EVENT");
    int key = evt->key();
    if (key == Qt::Key_1){
        emit labelClicked(1);
        printf("KEY 1");
    }
}

void Renderer::addNewRelatedTags(vector<string> tags){
    renderThread.addNewRelatedTags(tags);
    drawLines(tags.size());
}

void Renderer::drawLine(QVector3D s, QVector3D e)
{
    QList<QVector3D> points;
    points.append(s);
    points.append(e);
    this->renderThread.addToLineList(points);
}

void Renderer::drawLines(int n_lines)
{
    QVector3D* origin = new QVector3D(0,0,0);
    for (int i=0; i<n_lines; i++){
        QList<QVector3D> points;
        points.append(*origin);
        points.append(this->renderThread.getLineCoordsVector(i));
        this->renderThread.addToLineList(points);
    }
}

void Renderer::drawSphere(Sphere sphere)
{
    this->renderThread.addToSphereList(sphere);
}

void Renderer::wheelEvent(QWheelEvent *evt)
{
    int delta = evt->delta();
    renderThread.doZoom(0.01*delta);
}

