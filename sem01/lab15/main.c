#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* createArchive(char* archiveName, int fileCount)
{
    FILE* archive = fopen(archiveName, "wb");
    fwrite("ARCHIVE", sizeof(char), 7, archive);
    fwrite(&fileCount, sizeof(int), 1, archive);
    return archive;
}

int addFileToArchive(FILE* archive, char* fileName)
{
    FILE* inputFile = fopen(fileName, "rb");
    if (inputFile == NULL)
    {
        printf("Error when opening file %s\n", fileName);
        return 1;
    }

    // Запись имени файла
    for (unsigned long i = 0; i < strlen(fileName); ++i)
    {
        char buffer = *(fileName + i);
        fwrite(&buffer, sizeof(char), 1, archive);
    }

    // Отделяет название файла
    unsigned char flagByte = 0xFF;
    fwrite(&flagByte, sizeof(char), 1, archive);
    // Место под длину файла
    char zeroByte = 0x0;
    long pointerOnPlaceForSize = ftell(archive);
    fwrite(&zeroByte, sizeof(unsigned long long), 1, archive);

    unsigned long long bytesWritten = 0;
    char buffer;
    while (fread(&buffer, sizeof(char), 1, inputFile) != 0)
    {
        fwrite(&buffer, sizeof(char), 1, archive);
        bytesWritten += 1;
    }

    long fileEnd = ftell(archive);
    fseek(archive, pointerOnPlaceForSize, SEEK_SET);
    fwrite(&bytesWritten, sizeof(unsigned long long), 1, archive);
    fseek(archive, fileEnd, SEEK_SET);
    return 0;
}

void extractArchive(char* archiveName)
{
    FILE* archive = fopen(archiveName, "rb");
    char* buffer = calloc(1, sizeof(char) * 7);
    fread(buffer, sizeof(char), 7, archive);
    if (strcmp(buffer, "ARCHIVE") != 0)
    {
        printf("Archive is corrupted\n");
        return;
    }

    int fileCount = 0;
    fread(&fileCount, sizeof(int), 1, archive);

    unsigned long long offset;
    char* bufferName;
    unsigned char bufferByte;

    FILE* outputFile;
    unsigned long long fileSize;
    for (int i = 0; i < fileCount; ++i)
    {
        bufferName = calloc(1, sizeof(char));
        *bufferName = '\0';
        bufferByte = 0;

        fread(&bufferByte, sizeof(char), 1, archive);
        offset = 1;
        while (bufferByte != 0xFF)
        {
            realloc(bufferName, offset);
            *(bufferName + offset - 1) = bufferByte;
            fread(&bufferByte, sizeof(char), 1, archive);
            offset++;
        }
        *(bufferName + offset - 1) = '\0';

        outputFile = fopen((const char*)bufferName, "wb");
        free(bufferName);
        fileSize = 0;
        fread(&fileSize, sizeof(unsigned long long), 1, archive);
        for (unsigned long long j = 0; j < fileSize; ++j)
        {
            fread(&bufferByte, sizeof(char), 1, archive);
            fwrite(&bufferByte, sizeof(char), 1, outputFile);
        }
        fclose(outputFile);
    }
}

void printList(char* archiveName)
{
    FILE* archive = fopen(archiveName, "rb");
    char* buffer = calloc(1, sizeof(char) * 7);
    fread(buffer, sizeof(char), 7, archive);
    if (strcmp(buffer, "ARCHIVE") != 0)
    {
        printf("Archive is corrupted\n");
        return;
    }
    printf("List of files:\n");
    int number_of_files = 0;
    fread(&number_of_files, sizeof(int), 1, archive);

    unsigned long long offset;
    char* bufferName;
    unsigned char bufferByte;

    for (int i = 0; i < number_of_files; ++i)
    {
        bufferName = calloc(1, sizeof(char));
        *bufferName = '\0';
        bufferByte = 0;

        fread(&bufferByte, sizeof(char), 1, archive);
        offset = 1;
        while (bufferByte != 0xFF)
        {
            realloc(bufferName, offset);
            *(bufferName + offset - 1) = bufferByte;
            fread(&bufferByte, sizeof(char), 1, archive);
            offset++;
        }
        *(bufferName + offset - 1) = '\0';

        printf("%s\n", bufferName);
        free(bufferName);

        // Пропуск данных
        unsigned long long fileSize = 0;
        fread(&fileSize, sizeof(unsigned long long), 1, archive);
        fseek(archive, fileSize, SEEK_CUR);
    }
}

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        printf("Wrong arguments !\nTry one of this:\n1) --file <archive name> --create <list_of_files>\n2)  --file <archive name> --list\n3) --file <archive name> --extract");
    }
    char* archiveName;
    if (strcmp(argv[1], "--file") == 0)
    {
        archiveName = malloc(sizeof(argv[2]));
        strcpy(archiveName, argv[2]);
    }
    else
    {
        printf("Wrong arguments !\nTry one of this:\n1) --file <archive_name> --create <list_of_files>\n2)  --file <archive_name> --list\n3) --file <archive_name> --extract");
        return 1;
    }
    if (strcmp(argv[3], "--extract") == 0)
    {
        extractArchive(archiveName);
        printf("%s successfully created\n", archiveName);
    }
    else if (strcmp(argv[3], "--list") == 0)
    {
        printList(archiveName);
    }
    else if (strcmp(argv[3], "--create") == 0)
    {
        FILE* archive = createArchive(archiveName, argc - 4);
        for (int i = 4; i < argc; ++i)
        {
            addFileToArchive(archive, argv[i]);
        }
        fclose(archive);
        printf("%s successfully created\n", archiveName);
    }
    else
    {
        printf("Wrong arguments !\nTry one of this:\n1) --file <archive_name> --create <list_of_files>\n2)  --file <archive_name> --list\n3) --file <archive_name> --extract");
        return 1;
    }
    return 0;
}
