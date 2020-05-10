//
// Created by serge on 22.12.2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

int** createField(BMP* startImage)
{
    int** field = calloc(startImage->infoHeader->Width, sizeof(int));
    for (int i = 0; i < startImage->infoHeader->Width; ++i)
    {
        field[i] = calloc(startImage->infoHeader->Height, sizeof(int));
    }
    return field;
}

int checkNeighbours(int** previousState, int i, int j, int height, int width)
{
    int counter = 0;
    if (i + 1 < height && previousState[i + 1][j] == 1)
        counter++;
    if (j + 1 < width && previousState[i][j + 1] == 1)
        counter++;
    if (i > 0 && previousState[i - 1][j] == 1)
        counter++;
    if (j > 0 && previousState[i][j - 1] == 1)
        counter++;
    if (i + 1 < height && j + 1 < width && previousState[i + 1][j + 1] == 1)
        counter++;
    if (i - 1 > 0 && j - 1 > 0 && previousState[i - 1][j - 1] == 1)
        counter++;
    if (i + 1 < height && j - 1 > 0 && previousState[i + 1][j - 1] == 1)
        counter++;
    if (i - 1 > 0 && j + 1 < width && previousState[i - 1][j + 1] == 1)
        counter++;
    return counter;
}

void gameOfLife(GAME* game)
{
    game->previousState = createField(game->startImage);
    game->currentState = createField(game->startImage);
    game->previousState = game->startImage->imageData;
    while (game->currentGeneration < game->numberOfSteps)
    {

        for (int i = 0; i < game->startImage->infoHeader->Height; ++i)
        {
            for (int j = 0; j < game->startImage->infoHeader->Width; ++j)
            {
                if (checkNeighbours(game->previousState, i, j, game->startImage->infoHeader->Height, game->startImage->infoHeader->Width) == 3)
                {
                    game->currentState[i][j] = 1;
                }
                else if (checkNeighbours(game->previousState, i, j, game->startImage->infoHeader->Height, game->startImage->infoHeader->Width) == 2 && game->previousState[i][j] == 1)
                {
                    game->currentState[i][j] = 1;
                }
                else
                {
                    game->currentState[i][j] = 0;
                }
            }
        }
        if (game->currentGeneration % game->dumpFrequency == 0) {
            BMP *currentState = bmpCreate(game->currentState, game->startImage);
            char path[200];
            strcpy(path, game->outputDirectory);
            char generationNumber[50];
            itoa(game->currentGeneration + 1, generationNumber, 10);
            strcat(path, "/");
            strcat(path, generationNumber);
            strcat(path, ".bmp\0");
            bmpWrite(currentState, path);
        }
        game->previousState = game->currentState;
        game->currentState = createField(game->startImage);
        game->currentGeneration++;
    }
}