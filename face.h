#ifndef FACE_H
#define FACE_H

#include <QVector3D>

class Face
{
public:
    Face();
    QVector3D getv(int v);
    void setv(int v, float x, float y, float z);
    QVector3D getposition(void);
    void setposition(float x, float y, float z);

private:
    QVector3D vertices[4];
    QVector3D position;
};

#endif // FACE_H
