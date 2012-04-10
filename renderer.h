#ifndef RENDERER_H
#define RENDERER_H

#include <QtOpenGL>
#include <QGLWidget>
#include "renderthread.h"

class Renderer : public QGLWidget
{
    Q_OBJECT

public:
    explicit Renderer(QWidget *parent = 0);

    void initRenderThread(void);
    void stopRenderThread(void);
    
signals:
    
public slots:

protected:
    void closeEvent(QCloseEvent *);
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);

    RenderThread renderThread;
};

#endif // RENDERER_H
