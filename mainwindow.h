#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Renderer;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0, Renderer *rend = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *evt);

private:
    Ui::MainWindow *ui;
    Renderer *renderer;
    
signals:
    
public slots:
    
};

#endif // MAINWINDOW_H
