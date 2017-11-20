//
//  superman.hpp
//  Assignment2
//
//  Created by Omar Ezzat El-Etreby on 11/17/17.
//  Copyright © 2017 Etro. All rights reserved.
//

#ifndef superman_hpp
#define superman_hpp

#include <stdio.h>


extern int side;
extern float superX;
extern float superY;
extern float t;
extern double supermanCapeCount;
extern bool supermanCapeUp;
extern bool supermanMov;

void bezier(float t, int* p0,int* p1,int* p2,int* p3);
void drawSuperman();
void movSuperman();

#endif /* superman_hpp */
