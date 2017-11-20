//
//  creeper.hpp
//  Assignment2
//
//  Created by Omar Ezzat El-Etreby on 11/17/17.
//  Copyright © 2017 Etro. All rights reserved.
//

#ifndef creeper_hpp
#define creeper_hpp

#include <stdio.h>

extern bool creeperMov;
extern double creeperSpeed;
extern bool creeperMovUp;
extern double creeperAngleRot;

void drawCreeper();
void movCreeper();

#endif /* creeper_hpp */
