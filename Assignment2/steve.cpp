//
//  steve.cpp
//  Assignment2
//
//  Created by Omar Ezzat El-Etreby on 11/17/17.
//  Copyright © 2017 Etro. All rights reserved.
//

#include "steve.hpp"

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double steveAngleRot = 0.0;
double steveHeight = 0.0;
bool steveMov = false;
bool steveRotUp = true;
bool frontFlip = false;

void drawSteve() {
    glPushMatrix();
    glRotated(45, 0, 1, 0);
    glTranslated(0 , steveHeight+0.1,0);
    glRotated( -1* steveAngleRot, 0, 0, 1);
    //glTranslated(0, steveHeight, 0);
    //Head
    glPushMatrix();
    glColor3f(1.000, 1.000, 0.878);
    glTranslated(0, 1.5, 0);
    glutSolidCube(0.3);
    //Head - Hair
    glPushMatrix();
    glColor3f(0.545, 0.271, 0.075);
    glTranslated(0, 0.15, 0);
    glScaled(1, 0.25, 1);
    glutSolidCube(0.31);
    glPopMatrix();
    
    //Head - Eyes
    glPushMatrix();
    glTranslated(0, 0.0375, 0);
    glPushMatrix();
    glColor3f(0, 0, 0);
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
    glColor3f(0, 0, 0);
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
    glPopMatrix();
    //Head - Mouth
    glColor3f(1.000, 0.980, 0.804);
    glPushMatrix();
    glTranslated(-0.151, -0.0375, 0.025);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.0375, -0.0125);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    //Head - Beard
    glColor3f(0.804, 0.522, 0.247);
    glPushMatrix();
    glTranslated(-0.151, -0.075, 0.0625);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.1125, 0.0625);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.1125, 0.025);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.1125, -0.0125);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.1125, -0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.075, -0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPopMatrix();
    
    //Body
    glPushMatrix();
    glPushMatrix();
    glColor3f(0.118, 0.565, 1.000);
    glTranslated(0, 1.2, 0);
    glutSolidCube(0.3);
    glPopMatrix();
    //Body - Belt
    glPushMatrix();
    glColor3f(0.118, 0.565, 1.000);
    glTranslated(0, 1.16, 0);
    glutSolidCube(0.3);
    glPopMatrix();
    
    //Body - Hands
    glPushMatrix();
    glColor3f(0.118, 0.565, 1.000);
    glTranslated(0, 1.28, -0.2);
    glScaled(0.5, 0.4, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.000, 1.000, 0.878);
    glTranslated(0, 1.13, -0.2);
    glScaled(0.5, 0.6, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.118, 0.565, 1.000);
    glTranslated(0, 1.28, 0.2);
    glScaled(0.5, 0.4, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.000, 1.000, 0.878);
    glTranslated(0, 1.13, 0.2);
    glScaled(0.5, 0.6, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    
    //Legs
    glPushMatrix();
    glTranslated(0, -0.04, 0);
    //Legs - Left Leg
    glPushMatrix();
    glColor3f(0,0,1);
    glScaled(1, 1, 0.5);
    glTranslated(0, 0.9, -0.155);
    glutSolidCube(0.3);
    glPopMatrix();
    //Legs - Left Foot
    glPushMatrix();
    glTranslated(0, 0.005, 0);
    glPushMatrix();
    glColor3f(	0.439, 0.502, 0.565);
    glScaled(1, 1, 0.5);
    glTranslated(0, 0.7, -0.155);
    glScaled(1, 0.3, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(	0.439, 0.502, 0.565);
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
    glTranslated(0, 0.005, 0);
    glPushMatrix();
    glColor3f(	0.439, 0.502, 0.565);
    glScaled(1, 1, 0.5);
    glTranslated(0, 0.7, 0.155);
    glScaled(1, 0.3, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(	0.439, 0.502, 0.565);
    glScaled(1, 1, 0.5);
    glTranslated(-0.17, 0.7, 0.155);
    glScaled(0.2, 0.3, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix();
    glPopMatrix();
}

void movSteve() {
    if(steveMov){
        if(frontFlip){
            steveAngleRot-=1;
            if(steveAngleRot<=-360){
                steveAngleRot = 0.0;
            }
            
            if(steveRotUp) {
                steveHeight+=0.01;
                if(steveHeight>=1.8) {
                    steveRotUp = false;
                }
            } else {
                steveHeight-=0.01;
                if(steveHeight<=0.0) {
                    steveRotUp = true;
                    frontFlip = false;
                }
            }
        } else {
            steveAngleRot+=1;
            if(steveAngleRot>=360){
                steveAngleRot = 0.0;
            }
            
            if(steveRotUp) {
                steveHeight+=0.01;
                if(steveHeight>=1.8) {
                    steveRotUp = false;
                }
            } else {
                steveHeight-=0.01;
                if(steveHeight<=0.0) {
                    steveRotUp = true;
                    frontFlip = true;
                    steveAngleRot = 0.0;
                }
            }
        }
    }
}
