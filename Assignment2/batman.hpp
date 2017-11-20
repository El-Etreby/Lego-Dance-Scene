//
//  batman.hpp
//  Assignment2
//
//  Created by Omar Ezzat El-Etreby on 11/17/17.
//  Copyright © 2017 Etro. All rights reserved.
//

#ifndef batman_hpp
#define batman_hpp

#include <stdio.h>

extern bool batmanMov1;
extern bool batmanHandsUp;
extern bool batmanEjectHands;
extern double batmanEjectSpeed;
extern bool batmanEjectUp;
extern double batmanHandsUpCount1;
extern bool batmanMov2;
extern bool batmanCapeUp;
extern double batmanCapeCount;
extern bool batmanHandsUp1;
extern double batmanHandsUpCount;
extern double batmanSpeed;
extern bool batmanMovUp;

void drawBatman();
void movBatman1();
void movBatman2();

#endif /* batman_hpp */
