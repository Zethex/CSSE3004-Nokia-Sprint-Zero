#ifndef SPHERE_H
#define SPHERE_H

#include "face.h"

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
};

#endif // SPHERE_H
