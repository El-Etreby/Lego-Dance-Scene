//
//  batman.cpp
//  Assignment2
//
//  Created by Omar Ezzat El-Etreby on 11/17/17.
//  Copyright © 2017 Etro. All rights reserved.
//

#include "batman.hpp"

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

bool batmanMov1 = false;
bool batmanHandsUp = false;
double batmanHandsUpCount1 = 0.0;
bool batmanEjectHands = false;
double batmanEjectSpeed = 0.0;
bool batmanEjectUp = false;


bool batmanMov2 = false;
bool batmanCapeUp = true;
double batmanCapeCount = 0.0;
bool batmanHandsUp1 = true;
double batmanHandsUpCount = 0.0;
double batmanSpeed = 0.0;
bool batmanMovUp = true;


void drawBatman(){
    glPushMatrix();
    glRotated(45, 0, 1, 0);
    glTranslated(0, batmanSpeed, 0);
    //Head
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(0, 1.5, 0);
    glutSolidCube(0.3);
    //Head - Cones
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(0.1, 0.15, 0.085);
    glRotated(-90, 1, 0, 0);
    glutSolidCone(0.02, 0.2, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.1, 0.15, -0.085);
    glRotated(-90, 1, 0, 0);
    glutSolidCone(0.02, 0.2, 100, 100);
    glPopMatrix();
    //Head - Eyes
    glPushMatrix();
    glColor3f(1, 1, 1);
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
    //Right Eye
    glPushMatrix();
    glColor3f(1, 1, 1);
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
    
    //Head - Mouth
    glPushMatrix();
    glColor3f(1.000, 1.000, 0.878);
    glTranslated(-0.151, -0.1, 0);
    glScaled(0.01, 0.25, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    glPopMatrix();
    
    //Body
    glPushMatrix();
    glColor3f(0.000, 0.000, 0.000);
    glTranslated(0, 1.33, 0);
    glScaled(1, 0.15, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(	0.439, 0.502, 0.565);
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
    glColor3f(0,0, 0);
    
    if(batmanMov2) {
        if(batmanCapeCount > 0.0 && batmanCapeUp) {
            //glTranslated(0.26, 1.21, 0);
            glTranslated(0.15, 1.15, 0);
            glRotated(-45, 0, 0, 1);
        } else {
            glTranslated(0.26, 1.21, 0);
            
        }
    } else {
        glTranslated(0.26, 1.21, 0);
    }
    
    glRotated(45, 0, 0, 1);
    glScaled(0.01, 1.2, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    
    //Hands
    //Hands - Left Hand
    
    
    glPushMatrix();
    glTranslated(0, -0.015, 0);
    if(batmanHandsUp1 && batmanMov2){
        glTranslated(0, 1.35, 0);
        glRotated(180, 0, 0, 1);
        glTranslated(0, -1.35, 0);
    }
    if(batmanHandsUp && batmanMov1) {
        glTranslated(0, 2.615, 0);
        glRotated(180, 0, 0, 1);
        //batmanEjectHands = true;
        
    }
    glPushMatrix();
    glColor3f(0.000, 0.000, 0.000);
    glTranslated(0, 1.35, -0.2);
    glScaled(0.5, 0.15, 0.5);
    
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(	0.439, 0.502, 0.565);
    glTranslated(0, 1.24, -0.2);
    glScaled(0.5, 0.55, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(0, 1.12, -0.2);
    glScaled(0.5, 0.25, 0.5);
    if(batmanEjectHands && batmanHandsUp && batmanMov1){
        glTranslated(0, -1*batmanEjectSpeed, 0);
    }
    glutSolidCube(0.3);
    glPopMatrix();
    glPopMatrix();
    //Hands - Right Hand
    glPushMatrix();
    glTranslated(0, -0.015, 0);
    if(batmanHandsUp && batmanMov1) {
        glTranslated(0, 2.615, 0);
        glRotated(-180, 0, 0, 1);
        //batmanEjectHands = true;
    }
    if(batmanHandsUp1 && batmanMov2){
        glTranslated(0, 1.35, 0);
        glRotated(180, 0, 0, 1);
        glTranslated(0, -1.35, 0);
    }
    glPushMatrix();
    glColor3f(0.000, 0.000, 0.000);
    glTranslated(0, 1.35, 0.2);
    glScaled(0.5, 0.15, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.439, 0.502, 0.565);
    glTranslated(0, 1.24, 0.2);
    glScaled(0.5, 0.55, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(0, 1.12, 0.2);
    glScaled(0.5, 0.25, 0.5);
    if(batmanEjectHands && batmanHandsUp && batmanMov1){
        glTranslated(0, -1*batmanEjectSpeed, 0);
    }
    glutSolidCube(0.3);
    glPopMatrix();
    glPopMatrix();
    
    //Legs 0.439, 0.502, 0.565
    //Legs
    glPushMatrix();
    glTranslated(0, -0.035, 0);
    //Legs - Left Leg
    glPushMatrix();
    glColor3f(0.439, 0.502, 0.565);
    glScaled(1, 1, 0.5);
    glTranslated(0, 0.9, -0.155);
    glutSolidCube(0.3);
    glPopMatrix();
    //Legs - Left Foot
    glPushMatrix();
    glTranslated(0, 0.005, 0);
    glPushMatrix();
    glColor3f(0,0,0);
    glScaled(1, 1, 0.5);
    glTranslated(0, 0.7, -0.155);
    glScaled(1, 0.3, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
    glScaled(1, 1, 0.5);
    glTranslated(-0.17, 0.7, -0.155);
    glScaled(0.2, 0.3, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    glPopMatrix();
    //Legs - Right Leg
    glPushMatrix();
    glColor3f(0.439, 0.502, 0.565);
    glScaled(1, 1, 0.5);
    glTranslated(0, 0.9, 0.155);
    glutSolidCube(0.3);
    glPopMatrix();
    //Legs - Right Foot
    glPushMatrix();
    glTranslated(0, 0.005, 0);
    glPushMatrix();
    glColor3f(0,0,0);
    glScaled(1, 1, 0.5);
    glTranslated(0, 0.7, 0.155);
    glScaled(1, 0.3, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
    glScaled(1, 1, 0.5);
    glTranslated(-0.17, 0.7, 0.155);
    glScaled(0.2, 0.3, 1);
    glutSolidCube(0.3);
    glPopMatrix();
    glPopMatrix();
    //Legs - Cone
    glPushMatrix();
    glColor3f(0.000, 0.000, 0.000);
    glTranslated(-0.151, 1.05, 0);
    glRotated(90, 1, 0, 0);
    glScaled(0.01, 1, 1);
    glutSolidCone(0.15, 0.15, 100, 100);
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix();
    
}

void movBatman1() {
    if(batmanMov1){
        if(batmanHandsUp){
            if (batmanEjectHands) {
                if(batmanEjectUp){
                    batmanEjectSpeed+=0.05;
                    if(batmanEjectSpeed >= 1){
                        batmanEjectUp = false;
                    }
                } else {
                    batmanEjectSpeed-=0.05;
                    if(batmanEjectSpeed <= 0.0){
                        batmanEjectHands = false;
                    }
                }
            } else {
                batmanHandsUpCount1-=1;
                if(batmanHandsUpCount1<=0.0){
                    batmanHandsUp = false;
                    batmanHandsUpCount1 = 0.0;
                    batmanEjectHands = false;
                    batmanEjectSpeed = 0.0;
                    batmanEjectUp = false;
                }
            }
        } else {
            batmanHandsUpCount1+=1;
            if(batmanHandsUpCount1>=20){
                batmanHandsUp = true;
                batmanEjectUp = true;
                batmanEjectHands = true;
            }
        }
        
    }
}

void movBatman2() {
    if(batmanMov2){
        if(batmanCapeUp){
            batmanCapeCount--;
            if(batmanCapeCount<=0.0) {
                batmanCapeUp = false;
            }
        } else {
            batmanCapeCount++;
            if(batmanCapeCount>=50) {
                batmanCapeUp = true;
            }
        }
        
        if(batmanHandsUp1){
            if(batmanMovUp){
                batmanSpeed+=0.01;
                if(batmanSpeed>=0.8){
                    batmanMovUp = false;
                }
            } else {
                batmanSpeed-=0.01;
                if(batmanSpeed<=0.0){
                    batmanMovUp = true;
                    batmanHandsUp1 = false;
                    batmanCapeUp = true;
                    batmanCapeCount = 0.0;
                    batmanSpeed = 0.0;
                    batmanMovUp = true;
                }
            }
        } else {
            batmanHandsUpCount+=1;
            if(batmanHandsUpCount>20){
             batmanHandsUp1 = true;
             batmanHandsUpCount = 0.0;
            }
        }
    }
}
