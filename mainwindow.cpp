#include "mainwindow.h"
//#include "ui_mainwindow.h"

#include "renderer.h"

MainWindow::MainWindow(QWidget *parent, Renderer *rend) :
    QMainWindow(parent)//,
    //ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    this->renderer = rend;
    setCentralWidget(renderer);

    renderer->initRenderThread();
    // This would take place in the controller
    QVector3D *pa = new QVector3D(0, 0, 0);
    QVector3D *pb = new QVector3D(6, 6, 6);
    renderer->drawLine(*pa, *pb);

    Sphere sphere;
    sphere.createSphere();
    renderer->drawSphere(sphere);
}

MainWindow::~MainWindow()
{
    delete renderer;
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *evt)
{
    renderer->stopRenderThread();
    QMainWindow::closeEvent(evt);
}
