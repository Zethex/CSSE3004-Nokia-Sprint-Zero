#ifndef SPHERE_H
#define SPHERE_H

#include "face.h"
#include <QGraphicsScene> // fix - may need to move
#include <QGraphicsEmbedScene> // fix - may need to move

class Sphere
{
public:
    Sphere();
    void createSphere(void);
    Face getface(int pos);


private:
    Face faces[500]; // fix - terrible way to do this - add malloc when i have time
    int number_of_faces;
    QVector3D position;
    QVector3D rotation;
    void generateFaces(int n_rows, float L);
    QVector3D cartesian(float x, float y, float z);
    void generateFileTextures(void);

    QGraphicsScene scene[n_filenames]; // fix - most likely need to move to renderer
    int textureId[n_filenames]; // fix - most likely need to move to renderer
    string filenames[] = {"label 1", "label 2", "label3", "label 4", "label 5", "label 6", "label 7", "label 8"}; //fix - remove - only for testing
};

#endif // SPHERE_H
