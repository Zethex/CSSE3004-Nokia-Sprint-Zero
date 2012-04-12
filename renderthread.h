#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H

#include <QThread>
#include <sphere.h>
#include <QGraphicsScene> // fix - may need to move

class Renderer;
class QSize;

class RenderThread : public QThread
{
    Q_OBJECT

public:
    explicit RenderThread(Renderer *parent = 0);
    void resizeViewport(const QSize &size);
    void run(void);
    void stop(void);

protected:
    void GLInit(void);
    void GLResize(int width, int height);
    void paintGL(void);
    
signals:
    
public slots:

private:
    bool doRendering, doResize, doRefresh;
    int w, h, FrameCounter;
    Sphere centralSphere;
    Renderer *renderer;

    QGraphicsScene scene[500]; // fix - most likely need to move to renderer
    int textureId[500]; // fix - most likely need to move to renderer
};

#endif // RENDERTHREAD_H
