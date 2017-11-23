//
//  joker.hpp
//  Assignment2
//
//  Created by Omar Ezzat El-Etreby on 11/17/17.
//  Copyright © 2017 Etro. All rights reserved.
//

#ifndef joker_hpp
#define joker_hpp

#include <stdio.h>

extern bool jokerHandsUp1;
extern bool jokerHandsUp2;
extern bool jokerMov1;
extern double jokerAngleRot;
extern bool jokerMov2;
extern double jokerHandCount;
extern double jokerTrans;
extern double jokerTransRight;
extern bool jokerUp;
extern bool jokerRight;
extern bool jokerBool;

void drawJoker();
void movJoker1();
void movJoker2();

#endif /* joker_hpp */
