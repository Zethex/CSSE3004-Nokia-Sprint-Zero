#include "sphere.h"
#include <GL/GLU.h>
#include <stdio.h>

#include <math.h>
#define PI 3.141592653589793238462643383

Sphere::Sphere()
{
}

Face Sphere::getface(int pos){
    return faces[pos]; // fix - return new face object?
}

void Sphere::createSphere(void){
    generateFaces(7, 1.0);
    //generateFileTextures(); // fix - can play around with rendering a QML scene (in this case containing only a label) as a texture
}

void Sphere::generateFaces(int n_rows, float L){
    int face = 0;
    float dphi = (PI/2.0) /n_rows;
    float R = L/(2*sin(dphi/2));
    float phi = dphi;
    for (int i=-n_rows+1; i <= 4; i++){
        float edge_phi_up = phi + dphi/2;
        float edge_phi_down = phi - dphi/2;
        float r;
        if (i==0){
            r = R;
        } else if (i<=0){
            r = R*sin(edge_phi_up);
        } else {
            r = R*sin(PI - edge_phi_down);
        }

        float n_squares = floor(2*PI*r/L);
        float dtheta = (2*PI)/n_squares;
        float theta = 0;
        //printf("R %f || r %f", R, r);
        //printf("\n\n");
        for (int j=0; j< n_squares; j++){
           // printf("r %f || theta %f || phi up %f || phi down %f", r, theta, edge_phi_up, edge_phi_down);
            QVector3D v1, v2, v3, v4, center;
            float phi_top, phi_bottom;
            if (i<=0){
                phi_top = edge_phi_up;
                phi_bottom = edge_phi_down;
            } else {
                phi_top = edge_phi_down;
                phi_bottom = edge_phi_up;
            }
            v1 = cartesian(R, theta + dtheta/2, phi_top);
            v2 = cartesian(R, theta - dtheta/2, phi_top);
            v3 = cartesian(R, theta - dtheta/2, phi_bottom);
            v4 = cartesian(R, theta + dtheta/2, phi_bottom);
            center = cartesian(R, theta, phi);
            faces[face].setposition(center.x(), center.y(), center.z());
            faces[face].setv(1, (float)v1.x(), (float)v1.y(), (float)v1.z());
            faces[face].setv(2, (float)v2.x(), (float)v2.y(), (float)v2.z());
            faces[face].setv(3, (float)v3.x(), (float)v3.y(), (float)v3.z());
            faces[face].setv(4, (float)v4.x(), (float)v4.y(), (float)v4.z());
            theta += dtheta;
            face++;
        }
        phi += dphi;
    }
    number_of_faces = face;
}

void Sphere::generateFileTextures(void){ // fix - probably need to do this in rendering section - scope
    int n_filenames = filenames.length();
    for (int i=0; i<n_filenames; i++){
        scene[i].addText(filenames[i]);
        textureId[i] = scene[i].renderToTexture();
        // fix - if don't need to move this function, add texture id to face object here
    }

    // TO RENDER
    /**
     painter.glActiveTexture(GL_TEXTURE0);
     glBindTexture(GL_TEXTURE_2D, textureId);
     ... // draw the 3D object
     painter.glActiveTexture(GL_TEXTURE0);
     glBindTexture(GL_TEXTURE_2D, 0);
    **/
}

QVector3D Sphere::cartesian(float r, float theta, float phi){
    float x = r*sin(phi)*cos(theta);
    float y = r*sin(phi)*sin(theta);
    float z = r*cos(phi);
    QVector3D* vector = new QVector3D(x, y, z);
    return *vector;
}
