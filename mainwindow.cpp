#include "mainwindow.h"
//#include "ui_mainwindow.h"

#include "renderer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)//,
    //ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    renderer = new Renderer();
    setCentralWidget(renderer);
    renderer->initRenderThread();

    QVector3D *a = new QVector3D(0, 0, 0);
    QVector3D *b = new QVector3D(6, 6, 6);
    renderer->drawLine(*a, *b);
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
