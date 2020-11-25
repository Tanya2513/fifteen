//
//  game.h
//  fifteen
//
//  Created by Tatyana on 24.11.2020.
//

#ifndef game_h
#define game_h

#include <stdio.h>


#endif /* game_h */

int * findInField(int width, int height, int arrField[width][height], int needle);

int isInField(int width, int height, int arrField[width][height], int needle);

void randomFill(int width, int height, int arrField[width][height]);

int isPossibleToWin(int width, int height, int arrField[width][height]);

void makeMove(int width, int height, int arrField[width][height]);

int isFinishPosition(int width, int height, int arrField[width][height]);

void runGame(void);
