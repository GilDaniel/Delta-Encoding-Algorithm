#ifndef COMPRESSION_DEFINE
#define COMPRESSION_DEFINE

    
    class Compression{

        public:
            // Compress returns a byte buffer (char*) containing the compressed representation
            // Decompress receives that byte buffer and the original data size and returns an int array
            virtual char* Compress(int* data,int dataSize) = 0;
            virtual int* Decompress(char* data,int dataSize) = 0;
    };
#endif