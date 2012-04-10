#include "face.h"

Face::Face()
{

}

void Face::setv(int v, float x, float y, float z)
{
    QVector3D* vector = new QVector3D(x, y, z);
    vertices[v] = *vector;
}

QVector3D Face::getv(int v)
{
    return vertices[v];
}

void Face::setposition(float x, float y, float z)
{
    QVector3D* position_pointer = new QVector3D(x, y, z); // fix - less dodgy way of doing this?
    position = *position_pointer;
}

QVector3D Face::getposition()
{
    return position; // fix - should this return a new qvector object?
}
