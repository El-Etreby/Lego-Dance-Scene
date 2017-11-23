//
//  joker.cpp
//  Assignment2
//
//  Created by Omar Ezzat El-Etreby on 11/17/17.
//  Copyright © 2017 Etro. All rights reserved.
//

#include "joker.hpp"

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

bool jokerHandsUp1 = false;
bool jokerHandsUp2 = true;
double jokerHandCount = 0.0;
bool jokerMov1 = false;
double jokerAngleRot = 0.0;
bool jokerMov2 = false;
double jokerTrans = 0.0;
double jokerTransRight = 0.0;
bool jokerUp = true;
bool jokerRight = false;
bool jokerBool = false;
void drawJoker(){
    glPushMatrix();
    glRotated(45, 0, 1, 0);
    glTranslated(0, jokerTrans, -1* jokerTransRight);
    //Head
    glPushMatrix();
    glRotated(jokerAngleRot, 0, 1, 0);
    glColor3f(1, 1, 1);
    glTranslated(0.01, 1.5, 0);
    glutSolidCube(0.3);
    //Head - Hair
    glPushMatrix();
    glColor3f(0.000, 0.502, 0.000);
    glTranslated(0, 0.15, 0);
    glScaled(1, 0.25, 1);
    glutSolidCube(0.31);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.502, 0.000);
    glTranslated(-0.151, 0.095, 0.0965);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.502, 0.000);
    glTranslated(-0.151, 0.095, 0.134);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.000, 0.502, 0.000);
    glTranslated(-0.151, 0.075, 0.134);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    //Head - Eyes
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(-0.151, 0, -0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslated(-0.151, 0, -0.0875);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(-0.151, 0.0375, -0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(-0.151, 0.0375, -0.0875);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    //Right Eye
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(-0.151, 0, 0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslated(-0.151, 0, 0.0875);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(-0.151, 0.0375, 0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(-0.151, 0.0375, 0.0875);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    //Head - Mouth
    glColor3f(1.000, 0, 0);
    glPushMatrix();
    glTranslated(-0.151, -0.0375, -0.125);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.075, -0.0875);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.1125, -0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.1125, -0.0125);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.1125, 0.025);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.1125, 0.05);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.0375, 0.125);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.151, -0.075, 0.0875);
    glScaled(0.01, 1, 1);
    glutSolidCube(0.0375);
    glPopMatrix();
    glPopMatrix();
    
    //Body
    glPushMatrix();
    glColor3f(0.502, 0.000, 0.502);
    glTranslated(0, 1.33, 0);
    glScaled(1, 0.15, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.502, 0.000, 0.502);
    glTranslated(0, 1.16, 0);
    glutSolidCube(0.3);
    glPopMatrix();
    //Shirt
    glPushMatrix();
    glColor3f(0.000, 0.502, 0.000);
    glTranslated(-0.151, 1.17, 0);
    glScaled(0.01, 1.15, 0.4);
    glutSolidCube(0.3);
    glPopMatrix();
    //Cravate
    glPushMatrix();
    glColor3f(1.000, 1.000, 0.000);
    glTranslated(-0.152, 1.35, 0);
    glRotated(90, 1, 0, 0);
    glScaled(0.02, 1, 1);
    glutSolidCone(0.06, 0.15, 100, 100);
    glPopMatrix();
    //Sphere
    glPushMatrix();
    glColor3f(0.000, 0.502, 0.000);
    glTranslated(-0.152, 1.32, 0);
    glutSolidSphere(0.03, 100, 100);
    glPopMatrix();
    //Back Suit
    glPushMatrix();
    glColor3f(0.502, 0.000, 0.502);
    glTranslated(0.151, 1.015, 0.08);
    glRotated(90, 1, 0, 0);
    glScaled(0.01, 1, 1);
    glutSolidCone(0.075, 0.2, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.502, 0.000, 0.502);
    glTranslated(0.151, 1.015, -0.08);
    glRotated(90, 1, 0, 0);
    glScaled(0.01, 1, 1);
    glutSolidCone(0.075, 0.2, 100, 100);
    glPopMatrix();
    
    
    //Hands
    //Left Hand
    glPushMatrix();
    glTranslated(0, -0.015, 0);
    if(!jokerHandsUp1 && jokerMov1){
        glTranslated(-1.3, 1.215, 0);
        glRotated(-90, 0, 0, 1);
    }
    glPushMatrix();
    glColor3f(0.502, 0.000, 0.502);
    glTranslated(0, 1.35, -0.2);
    glScaled(0.5, 0.15, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.502, 0.000, 0.502);
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
    if(!jokerHandsUp2 && jokerMov1){
        glTranslated(-1.3, 1.215, 0);
        glRotated(-90, 0, 0, 1);
    }
    glPushMatrix();
    glColor3f(0.502, 0.000, 0.502);
    glTranslated(0, 1.35, 0.2);
    glScaled(0.5, 0.15, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.502, 0.000, 0.502);
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
    glTranslated(0, -0.04, 0);
    //Legs - Left Leg
    glPushMatrix();
    glColor3f(0.294, 0.000, 0.510);
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
    glColor3f(0.294, 0.000, 0.510);
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

void movJoker1() {
    if(jokerMov1){
        if(jokerBool){
            if(jokerRight){
                jokerTransRight+=0.01;
                if(jokerTransRight>=0.4){
                    jokerRight = false;
                }
            } else {
                jokerTransRight-=0.01;
                if(jokerTransRight<=0.0){
                    jokerRight = true;
                    jokerTransRight = 0.0;
                    jokerBool = false;
                }
            }
        } else {
            if(jokerUp){
                jokerTrans+=0.01;
                if(jokerTrans>=0.4){
                    jokerUp = false;
                }
            } else {
                jokerTrans-=0.01;
                if(jokerTrans<=0.0){
                    jokerUp = true;
                    jokerRight = true;
                    jokerBool = true;
                    jokerTrans = 0.0;
                }
            }
        }
        
            if(jokerHandsUp1)
            {
                jokerHandCount--;
                if(jokerHandCount<=0.0){
                    jokerHandsUp1 = false;
                    jokerHandsUp2 = true;
                }
            } else {
                jokerHandCount++;
                if(jokerHandCount>=50.0){
                    jokerHandsUp1 = true;
                    jokerHandsUp2 = false;
                }
            }
        }
    }

void movJoker2() {
    if(jokerMov2){
        jokerAngleRot+=1;
        if(jokerAngleRot>=360)
            jokerAngleRot=0.0;
    }
}
