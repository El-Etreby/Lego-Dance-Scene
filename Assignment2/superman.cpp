//
//  superman.cpp
//  Assignment2
//
//  Created by Omar Ezzat El-Etreby on 11/17/17.
//  Copyright © 2017 Etro. All rights reserved.
//

#include "superman.hpp"

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float superX = 0;
float superY = 0;
float t = 1;
bool supermanMov = false;
double supermanCapeCount = 0.0;
bool supermanCapeUp = true;

void drawSuperman(){
    glPushMatrix();
    glTranslated(0, 0, 0.7);
    //Head
    glPushMatrix();
    glColor3f(1.000, 1.000, 0.878);
    glTranslated(0, 1.5, 0);
    glutSolidCube(0.3);
    //Head - Hair
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(0, 0.15, 0);
    glScaled(1, 0.25, 1);
    glutSolidCube(0.31);
    glPopMatrix();
    //Head - Eyes
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(-0.151, 0, -0.05);
    glScaled(1, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslated(-0.151, 0, -0.0875);
    glScaled(1, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(-0.151, 0.0375, -0.05);
    glScaled(1, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(-0.151, 0.0375, -0.0875);
    glScaled(1, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    //Right Eye
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(-0.151, 0, 0.05);
    glScaled(1, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslated(-0.151, 0, 0.0875);
    glScaled(1, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(-0.151, 0.0375, 0.05);
    glScaled(1, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(-0.151, 0.0375, 0.0875);
    glScaled(1, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    //Head - Mouth
    glColor3f(1.000, 0.980, 0.804);
    glPushMatrix();
    glTranslated(-0.151, -0.075, 0.025);
    glScaled(0, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.075, -0.0125);
    glScaled(0, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPopMatrix();
    
    //Body
    glPushMatrix();
    glColor3f(1.000, 0.000, 0.000);
    glTranslated(0, 1.33, 0);
    glScaled(1, 0.15, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0, 1.000);
    glTranslated(0, 1.16, 0);
    glutSolidCube(0.3);
    glPopMatrix();
    //Body - Belt
    glPushMatrix();
    glColor3f(1.000, 1.000, 0.000);
    glTranslated(-0.151, 1.0325, 0);
    glScaled(0.01, 0.15, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    
    //Cape
    glPushMatrix();
    glColor3f(1,0, 0);
    if(supermanCapeCount > 0.0 && supermanCapeUp) {
        glTranslated(0.26, 1.21, 0);
        glRotated(45, 0, 0, 1);
    } else {
        glTranslated(0.15, 1.15, 0);

    }
    glScaled(0.01, 1.2, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    
    //Hands
    //Left Hand
    glPushMatrix();
    glTranslated(0, -0.015, 0);
    glPushMatrix();
    glColor3f(1.000, 0.000, 0.000);
    glTranslated(0, 1.35, -0.2);
    glScaled(0.5, 0.15, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.000, 1.000);
    glTranslated(0, 1.24, -0.2);
    glScaled(0.5, 0.55, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.000, 1.000, 0.878);
    glTranslated(0, 1.12, -0.2);
    glScaled(0.5, 0.25, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPopMatrix();
    
    //Right Hand
    glPushMatrix();
    glTranslated(0, -0.015, 0);
    glTranslated(0, 1.35, 0);
    glRotated(180, 0, 0, 1);
    glTranslated(0, -1.35, 0);
    //    glTranslated(0.35, 0, 0);
    glPushMatrix();
    glColor3f(1.000, 0.000, 0.000);
    glTranslated(0, 1.35, 0.2);
    glScaled(0.5, 0.15, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.000, 1.000);
    glTranslated(0, 1.24, 0.2);
    glScaled(0.5, 0.55, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.000, 1.000, 0.878);
    glTranslated(0, 1.12, 0.2);
    glScaled(0.5, 0.25, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPopMatrix();
    
    //Legs
    glPushMatrix();
    glTranslated(0, -0.035, 0);
    //Legs - Left Leg
    glPushMatrix();
    glColor3f(0,0,1);
    glScaled(1, 1, 0.5);
    glTranslated(0, 0.9, -0.155);
    glutSolidCube(0.3);
    glPopMatrix();
    //Legs - Left Foot
    glPushMatrix();
    glColor3f(1,0,0);
    glScaled(1, 1, 0.5);
    glTranslated(0, 0.7, -0.155);
    glScaled(1, 0.3, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0,0);
    glScaled(1, 1, 0.5);
    glTranslated(-0.17, 0.7, -0.155);
    glScaled(0.2, 0.3, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    //Legs - Right Leg
    glPushMatrix();
    glColor3f(0,0,1);
    glScaled(1, 1, 0.5);
    glTranslated(0, 0.9, 0.155);
    glutSolidCube(0.3);
    glPopMatrix();
    //Legs - Right Foot
    glPushMatrix();
    glColor3f(1,0,0);
    glScaled(1, 1, 0.5);
    glTranslated(0, 0.7, 0.155);
    glScaled(1, 0.3, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0,0);
    glScaled(1, 1, 0.5);
    glTranslated(-0.17, 0.7, 0.155);
    glScaled(0.2, 0.3, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    //Legs - Cone
    glPushMatrix();
    glColor3f(1.000, 0.000, 0.000);
    glTranslated(-0.151, 1.05, 0);
    glRotated(90, 1, 0, 0);
    glScaled(0.01, 1, 1);
    glutSolidCone(0.15, 0.15, 100, 100);
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix();
}

void bezier(float t, int* p0,int* p1,int* p2,int* p3)
{
    //    int res[2];
    superX=(pow((1-t),3)*p0[0]+3*t*pow((1-t),2)*p1[0]+3*pow(t,2)*(1-t)*p2[0]+pow(t,3)*p3[0])*0.25; //0.35
    superY=(pow((1-t),3)*p0[1]+3*t*pow((1-t),2)*p1[1]+3*pow(t,2)*(1-t)*p2[1]+pow(t,3)*p3[1])*0.1;
    //    return res;
}

void movSuperman(){
    if(supermanMov){
        if(supermanCapeUp){
            supermanCapeCount--;
            if(supermanCapeCount<=0.0) {
                supermanCapeUp = false;
            }
        } else {
            supermanCapeCount++;
            if(supermanCapeCount>=50) {
                supermanCapeUp = true;
            }
        }
        
        if(t>0){
            t-=0.005;
        }else{
            t=1;
        }
    }
}
