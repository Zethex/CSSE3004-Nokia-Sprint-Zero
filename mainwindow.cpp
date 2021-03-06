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
