#include "./DeltaEncoding/DeltaEncoding.h"


char* DeltaEncoding::Compress(int* data, int dataSize) {
    if (dataSize <= 0) return nullptr;

    int totalBytes = sizeof(int) + (dataSize - 1);
    
    // Aloca o buffer final de 'char'
    char* compressedBytes = new char[totalBytes];

    // 1. Armazena o primeiro 'int' (o valor base) nos 4 primeiros bytes
    int baseValue = data[0];
    std::memcpy(compressedBytes, &baseValue, sizeof(int));

    // 2. Armazena os deltas (como 'char') a partir do 5º byte
    int write_index = sizeof(int); // Começa a escrever depois do 'int' (no índice 4)
    
    for (int i = 1; i < dataSize; i++) {
        int delta = data[i] - data[i - 1];
        compressedBytes[write_index] = (char)delta;
        write_index++;
    }
    return compressedBytes;
}

int* DeltaEncoding::Decompress(char* compressed_data, int originalDataSize) {
    if (originalDataSize <= 0) return nullptr;

    // Aloca o array final para os dados decodificados
    int* decompressedData = new int[originalDataSize];

    // 1. Lê o valor base (o 'int' dos 4 primeiros bytes)
    int baseValue;
    std::memcpy(&baseValue, compressed_data, sizeof(int));
    decompressedData[0] = baseValue;

    // 2. Lê os deltas (os 'char') e recria os 'int'
    int read_index = sizeof(int); // Começa a ler *depois* do int base (do índice 4)
    
    for (int i = 1; i < originalDataSize; i++) {
        // Lê o delta de 1 byte
        char delta_byte = compressed_data[read_index];
        
        // Converte o char de volta para int (para a soma)
        int delta = (int)delta_byte; 

        // Recria o valor original
        decompressedData[i] = decompressedData[i - 1] + delta;
        
        read_index++;
    }

    return decompressedData;
}