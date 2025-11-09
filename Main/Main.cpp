#include <iostream>
#include "Compression/CompressionHandler.h"
#include "Compression/Compression.h"
#include "DeltaEncoding/DeltaEncoding.h"

using namespace std;

int main(){

    int DATA_SIZE;
    DeltaEncoding deltaEnc;
    CompressionHandler compressionHandler(deltaEnc);

    int escolha;
    bool continuar = true;
    while(continuar){
        cout << "Demonstracao Algoritmo Delta Encoding" << endl;
        cout << "1 - Sobre" << endl;
        cout << "2 - Teste" << endl;
        cout << "0 - Sair" << endl;

        cin >> escolha;

        switch(escolha){
            case 1:
                cout << "Este eh um programa que visa demonstrar o algoritmo de compactação Delta Encoding," << endl;
                cout << "compactando um vetor de números inteiros atraves da diferença entre numeros consecutivos" << endl;
                cout << endl << "IMPORTANTE: Este programa so eh capaz de propriamente compactar e descompactar vetores" << endl;
                cout << "cuja diferenca entre dois valores consecutivos nao ultrapassa 127" << endl << endl;
                break;
            case 2: {
                cout << "Digite o tamanho do vetor a ser compactado:" << endl;
                cin >> DATA_SIZE;
                int data[DATA_SIZE];
                char u[sizeof(int) + (DATA_SIZE - 1)];
                cout << "Digite os elementos de seu vetor:" << endl;
                for (int i = 0; i<DATA_SIZE; i++){
                    cin >> data[i];
                }
                char* compressedData =  compressionHandler.Compress(data,DATA_SIZE);
                int* decompressedData = compressionHandler.Decompress(compressedData,DATA_SIZE);
                int compressedLen = sizeof(int) + (DATA_SIZE - 1);
                memcpy(u, compressedData, compressedLen);

                cout << endl << "Vetor compactado (bytes):" << endl;
                for(int i = 0; i < compressedLen - 1; i++){
                    cout << (int)(unsigned char)compressedData[i] << " ";
                }
                cout << (int)(unsigned char)compressedData[compressedLen - 1] << endl;
                cout << "Vetor descompactadado: " << endl;
                for(int i = 0; i < DATA_SIZE-1; i++){
                    cout << decompressedData[i] << " ";
                }
                cout << decompressedData[DATA_SIZE-1] << endl;
                cout << endl << "Memoria do vetor original(bytes): " << sizeof(data) << endl;
                cout << "Memoria do vetor compactado(bytes): " << sizeof(u) << endl << endl;
                delete[] compressedData;
                delete[] decompressedData;
                break; }

            case 0:
                continuar = false;
                break;
        }
    }
}

