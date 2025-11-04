#include "CompressionHandler.h"
#include <iostream>

int* CompressionHandler::Compress(int* data,int size)
{
    int* compressedData =  CompressionHandler::compression.Compress(data,size);

    if(CompressionHandler::logData){
        
        std::cout << "Data Decompressed:" << std::endl;
        for(int i = 0; i < size-1; i++){
            std::cout << data[i] << ",";
        }
        std::cout << data[size-1] << std::endl;
        
        
        std::cout << "Data Compressed:" << std::endl;
        for(int i = 0; i < size-1; i++){
            std::cout << compressedData[i] << ",";
        }
        std::cout << compressedData[size-1] << std::endl;
        
        
    }

    return compressedData;
}

int* CompressionHandler::Decompress(int* data, int size){


    int* decompressedData =  CompressionHandler::compression.Decompress(data,size);

    if(CompressionHandler::logData){
        
        std::cout << "Data Compressed:" << std::endl;
        for(int i = 0; i < size-1; i++){
            std::cout << data[i] << ",";
        }
        std::cout << data[size-1] << std::endl;
        
        
        std::cout << "Data Decompressed:" << std::endl;
        for(int i = 0; i < size-1; i++){
            std::cout << decompressedData[i] << ",";
        }
        std::cout << decompressedData[size-1] << std::endl;
        
        
    }
}