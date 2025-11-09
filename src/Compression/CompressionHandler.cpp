#include "CompressionHandler.h"
#include <iostream>

char* CompressionHandler::Compress(int* data,int size)
{
    char* compressedData =  CompressionHandler::compression.Compress(data,size);

    return compressedData;
}

int* CompressionHandler::Decompress(char* data, int size){

    int* decompressedData =  CompressionHandler::compression.Decompress(data,size);

    return decompressedData;
}