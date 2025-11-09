#include <iostream>
#include "Compression/CompressionHandler.h"
#include "Compression/Compression.h"
#include "DeltaEncoding/DeltaEncoding.h"

#define DATA_SIZE 5


int main(){
    int data[DATA_SIZE] = {1000,1001,1002,1004,1007};

    DeltaEncoding deltaEnc;
    CompressionHandler compressionHandler(deltaEnc);


    int* compressedData =  compressionHandler.Compress(data,DATA_SIZE);
    int* decompressedData = compressionHandler.Decompress(compressedData,DATA_SIZE);
    
    delete[] compressedData;
    delete[] decompressedData;
}

