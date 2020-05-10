//
// Created by serge on 20.12.2019.
//
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

void bmpWrite(BMP* image, char* path)
{
    FILE* output = fopen(path, "wb");
    fwrite(image->fileHeader, sizeof(BITMAPFILEHEADER), 1, output);
    fwrite(image->infoHeader, sizeof(BITMAPINFOHEADER), 1, output);
    fwrite(image->offset, image->fileHeader->Offset - (sizeof(BITMAPFILEHEADER)) - sizeof(BITMAPINFOHEADER), 1, output);
    if (image->infoHeader->Width % 32 == 0)
    {
        union BITTOBYTE bitToByte;
        for (int i = 0; i < image->infoHeader->Height; ++i)
        {
            for (int j = 0; j < (image->infoHeader->Width / 8); ++j)
            {
                bitToByte.bits.bit7 = image->imageData[j * 8 + 0][i];
                bitToByte.bits.bit6 = image->imageData[j * 8 + 1][i];
                bitToByte.bits.bit5 = image->imageData[j * 8 + 2][i];
                bitToByte.bits.bit4 = image->imageData[j * 8 + 3][i];
                bitToByte.bits.bit3 = image->imageData[j * 8 + 4][i];
                bitToByte.bits.bit2 = image->imageData[j * 8 + 5][i];
                bitToByte.bits.bit1 = image->imageData[j * 8 + 6][i];
                bitToByte.bits.bit0 = image->imageData[j * 8 + 7][i];
                fprintf(output, "%c", bitToByte.buffer);
            }
        }
    }
    else
    {
        union BITTOBYTE bitToByte;
        for (int i = 0; i < image->infoHeader->Height; ++i)
        {
            for (int j = 0; j < ((image->infoHeader->Width / 32) + 1) * 4; ++j)
            {
                if (j * 8 + 0 < image->infoHeader->Width)
                    bitToByte.bits.bit7 = image->imageData[j * 8 + 0][i];
                else
                    bitToByte.bits.bit7 = 0;

                if (j * 8 + 1 < image->infoHeader->Width)
                    bitToByte.bits.bit6 = image->imageData[j * 8 + 1][i];
                else
                    bitToByte.bits.bit6 = 0;

                if (j * 8 + 2 < image->infoHeader->Width)
                    bitToByte.bits.bit5 = image->imageData[j * 8 + 2][i];
                else
                    bitToByte.bits.bit5 = 0;

                if (j * 8 + 3 < image->infoHeader->Width)
                    bitToByte.bits.bit4 = image->imageData[j * 8 + 3][i];
                else
                    bitToByte.bits.bit4 = 0;

                if (j * 8 + 4 < image->infoHeader->Width)
                    bitToByte.bits.bit3 = image->imageData[j * 8 + 4][i];
                else
                    bitToByte.bits.bit3 = 0;

                if (j * 8 + 5 < image->infoHeader->Width)
                    bitToByte.bits.bit2 = image->imageData[j * 8 + 5][i];
                else
                    bitToByte.bits.bit2 = 0;

                if (j * 8 + 6 < image->infoHeader->Width)
                    bitToByte.bits.bit1 = image->imageData[j * 8 + 6][i];
                else
                    bitToByte.bits.bit1 = 0;

                if (j * 8 + 7 < image->infoHeader->Width)
                    bitToByte.bits.bit0 = image->imageData[j * 8 + 7][i];
                else
                    bitToByte.bits.bit0 = 0;

                fprintf(output, "%c", bitToByte.buffer);
            }
        }
    }
    fclose(output);
}

BMP* bmpRead(FILE* inputBMP)
{
    BMP* startImage = malloc(sizeof(BMP));
    startImage->fileHeader = malloc(sizeof(BITMAPFILEHEADER));
    startImage->infoHeader = malloc(sizeof(BITMAPINFOHEADER));
    fread(startImage->fileHeader, sizeof(BITMAPFILEHEADER), 1, inputBMP);
    fread(startImage->infoHeader, sizeof(BITMAPINFOHEADER), 1, inputBMP);
    startImage->offset = malloc(startImage->fileHeader->Offset - (sizeof(BITMAPFILEHEADER)) - sizeof(BITMAPINFOHEADER));
    fread(startImage->offset, startImage->fileHeader->Offset - (sizeof(BITMAPFILEHEADER)) - sizeof(BITMAPINFOHEADER), 1 , inputBMP);

    startImage->imageData = malloc(sizeof(int) * startImage->infoHeader->Width);
    for (int i = 0; i < startImage->infoHeader->Width; ++i)
    {
        startImage->imageData[i] = malloc(sizeof(int) * startImage->infoHeader->Height);
    }

    union BITTOBYTE bitToByte;

    fseek(inputBMP, startImage->fileHeader->Offset, SEEK_SET);

    if (startImage->infoHeader->Width % 32 == 0)
    {
        for (int i = 0; i < startImage->infoHeader->Height; ++i)
        {
            for (int j = 0; j < (startImage->infoHeader->Width / 8); ++j)
            {
                fscanf(inputBMP, "%c", &bitToByte.buffer);
                startImage->imageData[j * 8 + 0][i] = bitToByte.bits.bit7;
                startImage->imageData[j * 8 + 1][i] = bitToByte.bits.bit6;
                startImage->imageData[j * 8 + 2][i] = bitToByte.bits.bit5;
                startImage->imageData[j * 8 + 3][i] = bitToByte.bits.bit4;
                startImage->imageData[j * 8 + 4][i] = bitToByte.bits.bit3;
                startImage->imageData[j * 8 + 5][i] = bitToByte.bits.bit2;
                startImage->imageData[j * 8 + 6][i] = bitToByte.bits.bit1;
                startImage->imageData[j * 8 + 7][i] = bitToByte.bits.bit0;
            }
        }
    }
    else
    {
        for (int i = 0; i < startImage->infoHeader->Height; ++i)
        {
            for (int j = 0; j < ((startImage->infoHeader->Width / 32) + 1) * 4; ++j)
            {

                fscanf(inputBMP, "%c", &bitToByte.buffer);
                if (j * 8 + 0 < startImage->infoHeader->Width)
                    startImage->imageData[j * 8 + 0][i] = bitToByte.bits.bit7;

                if (j * 8 + 1 < startImage->infoHeader->Width)
                    startImage->imageData[j * 8 + 1][i] = bitToByte.bits.bit6;

                if (j * 8 + 2 < startImage->infoHeader->Width)
                    startImage->imageData[j * 8 + 2][i] = bitToByte.bits.bit5;

                if (j * 8 + 3 < startImage->infoHeader->Width)
                    startImage->imageData[j * 8 + 3][i] = bitToByte.bits.bit4;

                if (j * 8 + 4 < startImage->infoHeader->Width)
                    startImage->imageData[j * 8 + 4][i] = bitToByte.bits.bit3;

                if (j * 8 + 5 < startImage->infoHeader->Width)
                    startImage->imageData[j * 8 + 5][i] = bitToByte.bits.bit2;

                if (j * 8 + 6 < startImage->infoHeader->Width)
                    startImage->imageData[j * 8 + 6][i] = bitToByte.bits.bit1;

                if (j * 8 + 7 < startImage->infoHeader->Width)
                    startImage->imageData[j * 8 + 7][i] = bitToByte.bits.bit0;
            }
        }
    }
    return startImage;
}

BMP* bmpCreate(int** currentState, BMP* startImage)
{
    BMP* bmp = startImage;
    bmp->imageData = currentState;
    return bmp;
}
