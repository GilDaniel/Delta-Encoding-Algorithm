#include "CompressionHandler.h"
#include <iostream>

char* CompressionHandler::Compress(int* data,int size)
{
    char* compressedData =  CompressionHandler::compression.Compress(data,size);

    if(CompressionHandler::logData){
        std::cout << "Data Decompressed:" << std::endl;
        for(int i = 0; i < size-1; i++){
            std::cout << data[i] << ",";
        }
        std::cout << data[size-1] << std::endl;

        // compressed length for this scheme: sizeof(int) + (size - 1)
        int compressedLen = sizeof(int) + (size - 1);
        std::cout << "Data Compressed (bytes):" << std::endl;
        for(int i = 0; i < compressedLen - 1; i++){
            // print as unsigned values to see raw byte numbers
            std::cout << (int)(unsigned char)compressedData[i] << ",";
        }
        std::cout << (int)(unsigned char)compressedData[compressedLen - 1] << std::endl;
    }

    return compressedData;
}

int* CompressionHandler::Decompress(char* data, int size){

    int* decompressedData =  CompressionHandler::compression.Decompress(data,size);

    if(CompressionHandler::logData){
        int compressedLen = sizeof(int) + (size - 1);
        std::cout << "Data Compressed (bytes):" << std::endl;
        for(int i = 0; i < compressedLen - 1; i++){
            std::cout << (int)(unsigned char)data[i] << ",";
        }
        std::cout << (int)(unsigned char)data[compressedLen - 1] << std::endl;

        std::cout << "Data Decompressed:" << std::endl;
        for(int i = 0; i < size-1; i++){
            std::cout << decompressedData[i] << ",";
        }
        std::cout << decompressedData[size-1] << std::endl;
    }

    return decompressedData;
}