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
