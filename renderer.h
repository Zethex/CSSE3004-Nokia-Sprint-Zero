#ifndef RENDERER_H
#define RENDERER_H

#include <QtOpenGL>
#include <QGLWidget>
#include <QVector3D>
#include <QList>
#include "renderthread.h"

class Renderer : public QGLWidget
{
    Q_OBJECT

public:
    explicit Renderer(QWidget *parent = 0);

    void initRenderThread(void);
    void stopRenderThread(void);

    void drawLine(QVector3D s, QVector3D e);
    void drawSphere(Sphere sphere);
    void drawLines(int n_lines);

    void removeSphere(Sphere sphere);

    void clearLines();
    void clearSpheres();
    
signals:
    
public slots:

protected:
    void closeEvent(QCloseEvent *);
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);
	void wheelEvent(QWheelEvent *);
    void keyPressEvent(QKeyEvent *evt);
	
    RenderThread renderThread;
};

#endif // RENDERER_H
