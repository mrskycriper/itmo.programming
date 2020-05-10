//
// Created by serge on 22.12.2019.
//

#ifndef HW14_GAME_H
#define HW14_GAME_H

#include "bmp.h"

#pragma pack(push, 1)

typedef struct
{
    int** previousState;
    int** currentState;
    BMP* startImage;
    int dumpFrequency;
    int numberOfSteps;
    char* outputDirectory;
    int currentGeneration;
} GAME;

#pragma pack(pop)

int** createField(BMP* startImage);
int checkNeighbours(int** previousState, int i, int j, int height, int width);
void gameOfLife(GAME* game);

#endif //HW14_GAME_H
