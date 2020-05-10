//
// Created by serge on 20.12.2019.
//

#ifndef HW14_BMP_H
#define HW14_BMP_H

#pragma pack(push, 1)

typedef struct
{
    unsigned short Type;
    unsigned long Size;
    unsigned short Reserved1;
    unsigned short Reserved2;
    unsigned long Offset;
} BITMAPFILEHEADER;

typedef struct
{
    unsigned long Size;
    long Width;
    long Height;
    unsigned short Planes;
    unsigned short BitCount;
    unsigned long Compression;
    unsigned long SizeImage;
    long XPelsPerMeter;
    long YPelsPerMeter;
    unsigned long ClrUsed;
    unsigned long ClrImportant;
} BITMAPINFOHEADER;

typedef struct
{
    BITMAPFILEHEADER* fileHeader;
    BITMAPINFOHEADER* infoHeader;
    unsigned char* offset;
    int** imageData;
} BMP;

typedef struct
{
    unsigned bit0: 1;
    unsigned bit1: 1;
    unsigned bit2: 1;
    unsigned bit3: 1;
    unsigned bit4: 1;
    unsigned bit5: 1;
    unsigned bit6: 1;
    unsigned bit7: 1;
} BYTE;

union BITTOBYTE
{
    char buffer;
    BYTE bits;
};

#pragma pack(pop)

BMP* bmpRead(FILE* inputBMP);
void bmpWrite(BMP* image, char* path);
BMP* bmpCreate(int** currentState, BMP* startImage);

#endif //HW14_BMP_H
