#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H

#include <QThread>
#include <sphere.h>
#include <QGraphicsScene> // fix - may need to move
#include <QList>
#include <QVector3D>
//#include <qgraphicsembedscene.h>
#include <string>

class Renderer;
class QSize;

using namespace std;

class RenderThread : public QThread
{
    Q_OBJECT

public:
    explicit RenderThread(Renderer *parent = 0);
    void resizeViewport(const QSize &size);
    void run(void);
    void stop(void);
	void doZoom(int delta);
    void addToSphereList(Sphere);
    void addToLineList(QList<QVector3D>);
    QVector3D getLineCoordsVector(int index);
    void removeSphere(Sphere sphere);
    void addNewRelatedTags(vector<string>);
    void clearLines();
    void clearSpheres();
    void setCurrentTagName(string current_tag_name);

protected:
    void GLInit(void);
    void GLResize(int width, int height);
    void paintGL(void);
    
signals:
    
public slots:

private:
    bool doRendering, doResize, doRefresh;
    int w, h, FrameCounter, zoom, R;
    Renderer *renderer;

    QList<QList<QVector3D> > *lines;
    QList<Sphere> *spheres;

    //QGraphicsScene scene[500]; // fix - most likely need to move to renderer
    int textureId[500]; // fix - most likely need to move to renderer
    //QGraphicsEmbedScene *test_scene;

    std::vector<string> related_tag_names;

    std::string current_tag_name;
};

#endif // RENDERTHREAD_H
