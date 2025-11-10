#include "DeltaEncoding.h"


char* DeltaEncoding::Compress(int* data, int dataSize) {
    if (dataSize <= 0) return nullptr;

    int totalBytes = sizeof(int) + (dataSize - 1);
    
    // Allocate the final buffer of 'char's
    char* compressedBytes = new char[totalBytes];

    // 1. Store the first 'int' (base value) on the first 4 bytes
    int baseValue = data[0];
    std::memcpy(compressedBytes, &baseValue, sizeof(int));

    // 2. Stores the deltas as 'char's from the fifth byte on
    int write_index = sizeof(int); // Starts writing after the 'int' (at the fourth index)
    
    for (int i = 1; i < dataSize; i++) {
        int delta = data[i] - data[i - 1];
        compressedBytes[write_index] = (char)delta;
        write_index++;
    }
    return compressedBytes;
}

int* DeltaEncoding::Decompress(char* compressed_data, int originalDataSize) {
    if (originalDataSize <= 0) return nullptr;

    // Allocate the final array for the decoded data
    int* decompressedData = new int[originalDataSize];

    // 1. Reads the base value ( the 'integer' of the first 4 bytes)
    int baseValue;
    std::memcpy(&baseValue, compressed_data, sizeof(int));
    decompressedData[0] = baseValue;

    // 2. Reads the deltas ('char's) and convert them to 'int'
    int read_index = sizeof(int); // Starts reading *after* the base integer (index 4)
    
    for (int i = 1; i < originalDataSize; i++) {
        // Reads delta of one byte
        char delta_byte = compressed_data[read_index];
        
        // Converts the char back to int (so we can sum it)
        int delta = (int)delta_byte; 

        // Recreate the original value
        decompressedData[i] = decompressedData[i - 1] + delta;
        
        read_index++;
    }

    return decompressedData;
}