//
//  creeper.cpp
//  Assignment2
//
//  Created by Omar Ezzat El-Etreby on 11/17/17.
//  Copyright © 2017 Etro. All rights reserved.
//

#include "creeper.hpp"

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

bool creeperMov = false;
bool creeperMovUp = true;
double creeperSpeed = 0.0;
double creeperAngleRot = 0.0;

void drawCreeper()
{
    //Head
    glPushMatrix();
    glRotated(45, 0, 1, 0);
    glPushMatrix();
    glRotated(creeperAngleRot, 0, 1, 0);
    glPushMatrix();
    glRotated(-90, 0, 1, 0);
    glPushMatrix();
    glColor3f(	0, 1, 0);
    glTranslated(0, 1.55, 0);
    glutSolidCube(0.4);
    glPopMatrix();
    //Eyes
    //Left Eye
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.21, 1.55, -0.025);
    glTranslated(0, 0.1, -0.1);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.21, 1.55, -0.025);
    glTranslated(0, 0.1, -0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.21, 1.55, -0.025);
    glTranslated(0, 0.05, -0.1);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0, 0.000);
    glTranslated(-0.21, 1.55, -0.025);
    glTranslated(0, 0.05, -0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    //Right Eye
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.21, 1.55, 0.025);
    glTranslated(0, 0.1, 0.1);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.21, 1.55, 0.025);
    glTranslated(0, 0.1, 0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.21, 1.55, 0.025);
    glTranslated(0, 0.05, 0.1);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0, 0.000);
    glTranslated(-0.21, 1.55, 0.025);
    glTranslated(0, 0.05, 0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    //Left
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.21, 1.55, -0.025);
    glTranslated(0, 0, 0);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0, 0.000);
    glTranslated(-0.21, 1.55, -0.025);
    glTranslated(0, -0.05, 0);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0, 0.000);
    glTranslated(-0.21, 1.55, -0.025);
    glTranslated(0, -0.1, 0);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0, 0.000);
    glTranslated(-0.21, 1.55, -0.025);
    glTranslated(0, -0.1, -0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.21, 1.55, -0.025);
    glTranslated(0, -0.05, -0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.21, 1.55, -0.025);
    glTranslated(0, -0.15, -0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    //Right
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.21, 1.55, 0.025);
    glTranslated(0, 0, 0);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0, 0.000);
    glTranslated(-0.21, 1.55, 0.025);
    glTranslated(0, -0.05, 0);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0, 0.000);
    glTranslated(-0.21, 1.55, 0.025);
    glTranslated(0, -0.1, 0);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0, 0.000);
    glTranslated(-0.21, 1.55, 0.025);
    glTranslated(0, -0.1, 0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.21, 1.55, 0.025);
    glTranslated(0, -0.05, 0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.21, 1.55, 0.025);
    glTranslated(0, -0.15, 0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.05);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    
    //Body
    glPushMatrix();
    glColor3f(	0, 1, 0);
    glTranslated(0, 1.15, 0);
    glScaled(4, 4, 2);
    glutSolidCube(0.1);
    glPopMatrix();
    
    //Legs
    //Left Leg
    glPushMatrix();
    glTranslated(0, creeperSpeed, 0);
    glPushMatrix();
    glColor3f(	0, 1, 0);
    glTranslated(-0.11, 0.8, -0.2);
    glScaled(2, 3, 2);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0);
    //glTranslated(-0.211, 0.685, -0.2);
    glRotated(-90, 0, 1, 0);
    glTranslated(-0.31, 0.68, 0.11);
    glScaled(0.01, 1, 2);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.11, 0.64, -0.2);
    glScaled(2, 0, 2);
    glutSolidCube(0.1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(	0, 1, 0);
    glTranslated(0.11, 0.8, -0.2);
    glScaled(2, 3, 2);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0);
    glRotated(-90, 0, 1, 0);
    glTranslated(-0.31, 0.68, -0.11);
    glScaled(0.01, 1, 2);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(0.11, 0.64, -0.2);
    glScaled(2, 0, 2);
    glutSolidCube(0.1);
    glPopMatrix();
    
    //Right Leg
    glPushMatrix();
    glColor3f(	0, 1, 0);
    glTranslated(-0.11, 0.8, 0.2);
    glScaled(2, 3, 2);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0);
    //glTranslated(-0.211, 0.685, -0.2);
    glRotated(-90, 0, 1, 0);
    glTranslated(0.09, 0.68, 0.11);
    glScaled(0.01, 1, 2);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(-0.11, 0.64, 0.2);
    glScaled(2, 0, 2);
    glutSolidCube(0.1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(	0, 1, 0);
    glTranslated(0.11, 0.8, 0.2);
    glScaled(2, 3, 2);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0);
    glRotated(-90, 0, 1, 0);
    glTranslated(0.09, 0.68, -0.11);
    glScaled(0.01, 1, 2);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.392, 0.000);
    glTranslated(0.11, 0.64, 0.2);
    glScaled(2, 0, 2);
    glutSolidCube(0.1);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void movCreeper() {
    if(creeperMov) {
        creeperAngleRot+=1;
        if(creeperAngleRot>=360)
            creeperAngleRot=0.0;
        
        if(!creeperMovUp) {
            creeperSpeed-=0.005;
            if(creeperSpeed <= 0.0) {
                creeperMovUp = true;
                creeperSpeed = 0.0;
            }
        } else {
            creeperSpeed+=0.005;
            if(creeperSpeed >= 0.4) {
                creeperMovUp = false;
            }
        }
    }
}
