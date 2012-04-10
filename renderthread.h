#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H

#include <QThread>

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
    bool doRendering, doResize;
    int w, h, FrameCounter;

    Renderer *renderer;
};

#endif // RENDERTHREAD_H
