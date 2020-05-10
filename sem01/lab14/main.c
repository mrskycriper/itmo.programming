#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>

#include "bmp.h"
#include "game.h"

int main(int argc, char* argv[])
{
    if (argc < 7)
    {
        printf("Not Enough Arguments!");
        return 1;
    }
    if (argc > 9)
    {
        printf("To Many Arguments!");
        return 1;
    }

    GAME* game = malloc(sizeof(GAME));
    FILE* inputBMP;
    if (strcmp(argv[1], "--input") == 0)
    {
        inputBMP = fopen(argv[2], "rb");
    }
    else
    {
        printf("Incorrect input file name");
        return 1;
    }

    if (strcmp(argv[3], "--output") == 0)
    {
        game->outputDirectory = malloc(sizeof(argv[4]));
        strcpy(game->outputDirectory, argv[4]);
    }
    else
    {
        printf("Incorrect output directory name");
        return 1;
    }
    mkdir(game->outputDirectory);
    game->dumpFrequency = 1;
    game->numberOfSteps = 100;

    if (strcmp(argv[5], "--max_iter") == 0)
    {
        game->numberOfSteps = atoi(argv[6]);
    }
    else if (strcmp(argv[5], "--dump_freq") == 0)
    {
        game->dumpFrequency = atoi(argv[6]);
    }

    if (strcmp(argv[7], "--dump_freq") == 0)
    {
        game->dumpFrequency = atoi(argv[8]);
    }

    game->startImage = bmpRead(inputBMP);
    game->currentGeneration = 0;

    gameOfLife(game);

    //bmpWrite(game->startImage, "new.bmp");

//    int** tmp = createField(game->startImage);
//    tmp[0][1] = 1;
//    tmp[1][1] = 1;
//    tmp[1][0] = 1;
//    printf("%d", checkNeighbours(tmp, 0, 0, game->startImage->infoHeader->Height, game->startImage->infoHeader->Width));
    //BMP* TMP = bmpCreate(tmp, game->startImage);

//    bmpWrite(TMP, "smth.bmp");

    fclose(inputBMP);
    return 0;
}