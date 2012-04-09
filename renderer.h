#ifndef RENDERER_H
#define RENDERER_H

#include <QtOpenGL>
#include <QGLWidget>

class Renderer : public QGLWidget
{
    Q_OBJECT



public:
    Renderer(QWidget *parent);

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    
signals:
    
public slots:
    
};

#endif // RENDERER_H
