#include <iostream>
#include "Compression/CompressionHandler.h"
#include "Compression/Compression.h"
#include "DeltaEncoding/DeltaEncoding.h"

using namespace std;


/*


                                   
                                   
                                   
                 @@                
                @@@@               
                @@@@               
               @@@@@@              
              @@@@@@@@             
             @@@  @@@@@            
            @@@    @@@@@           
           @@@      @@@@           
          @@@       @@@@@          
          @@         @@@@@         
         @@           @@@@@        
        @@@            @@@@@       
       @@@             @@@@@       
      @@@@@@@@@@@@@@@@@@@@@@@      
     _______             __    __                      ________                                      __  __                     
    |       \           |  \  |  \                    |        \                                    |  \|  \                    
    | $$$$$$$\  ______  | $$ _| $$_     ______        | $$$$$$$$ _______    _______   ______    ____| $$ \$$ _______    ______  
    | $$  | $$ /      \ | $$|   $$ \   |      \       | $$__    |       \  /       \ /      \  /      $$|  \|       \  /      \ 
    | $$  | $$|  $$$$$$\| $$ \$$$$$$    \$$$$$$\      | $$  \   | $$$$$$$\|  $$$$$$$|  $$$$$$\|  $$$$$$$| $$| $$$$$$$\|  $$$$$$\
    | $$  | $$| $$    $$| $$  | $$ __  /      $$      | $$$$$   | $$  | $$| $$      | $$  | $$| $$  | $$| $$| $$  | $$| $$  | $$
    | $$__/ $$| $$$$$$$$| $$  | $$|  \|  $$$$$$$      | $$_____ | $$  | $$| $$_____ | $$__/ $$| $$__| $$| $$| $$  | $$| $$__| $$
    | $$    $$ \$$     \| $$   \$$  $$ \$$    $$      | $$     \| $$  | $$ \$$     \ \$$    $$ \$$    $$| $$| $$  | $$ \$$    $$
    \$$$$$$$   \$$$$$$$ \$$    \$$$$   \$$$$$$$       \$$$$$$$$ \$$   \$$  \$$$$$$$  \$$$$$$   \$$$$$$$ \$$ \$$   \$$ _\$$$$$$$
                                                                                                                  |  \__| $$
                                                                                                                   \$$    $$
                                                                                                                    \$$$$$$ 



By  Carlos Davi Carvalho Lima dos Santos
    Davi Gobo,
    Enzo Larger Manfio,
    Gil Daniel Silva Fernandes,
    Gustavo Tavares Gonçalves,                                                                                                                  
    Vitor Rodrigues Santana,
*/
    

int main(){

    int DATA_SIZE;
    DeltaEncoding deltaEnc;
    CompressionHandler compressionHandler(deltaEnc);

    int chosen;
    bool repeat = true;
    while(repeat){
        cout << "Delta Encoding Algorithm Showcase" << endl;
        cout << "1 - About" << endl;
        cout << "2 - Testing" << endl;
        cout << "0 - Exit" << endl;

        cin >> chosen;

        switch(chosen){
            case 1:
                
                cout << "This code aims to showchase the Delta Encoding algorithm." << endl;
                cout << "Works by compressing a vector of integer numbers through the difference of consecutive numbers." << endl;
                cout << endl << "IMPORTANT: This can only propperly compress and decompress vectors (arrays) of integers" << endl;
                cout << "that the difference of two consecutive terms don't exceed 127" << endl << endl;
                break;
            case 2: {
                cout << "Type the size of the vector to be compressed" << endl;
                cin >> DATA_SIZE;
                int data[DATA_SIZE];
                char u[sizeof(int) + (DATA_SIZE - 1)];
                cout << "Type the elements of the vector:" << endl;
                for (int i = 0; i<DATA_SIZE; i++){
                    cin >> data[i];
                }
                char* compressedData =  compressionHandler.Compress(data,DATA_SIZE);
                int* decompressedData = compressionHandler.Decompress(compressedData,DATA_SIZE);
                int compressedLen = sizeof(int) + (DATA_SIZE - 1);
                memcpy(u, compressedData, compressedLen);

                cout << endl << "Compressed vector (bytes):" << endl;
                for(int i = 0; i < compressedLen - 1; i++){
                    cout << (int)(unsigned char)compressedData[i] << " ";
                }
                cout << (int)(unsigned char)compressedData[compressedLen - 1] << endl;
                cout << "Uncompressed vector: " << endl;
                for(int i = 0; i < DATA_SIZE-1; i++){
                    cout << decompressedData[i] << " ";
                }
                cout << decompressedData[DATA_SIZE-1] << endl;
                cout << endl << "Memory of the original vector (bytes): " << sizeof(data) << endl;
                cout << "Memory of the compressed vector(bytes): " << sizeof(u) << endl << endl;
                delete[] compressedData;
                delete[] decompressedData;
                break; }

            case 0:
                repeat = false;
                break;
        }
    }
}

