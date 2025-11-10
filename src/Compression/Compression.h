#ifndef COMPRESSION_DEFINE
#define COMPRESSION_DEFINE

    
    class Compression{

        public:
            virtual char* Compress(int* data,int dataSize) = 0;
            virtual int* Decompress(char* data,int dataSize) = 0;
    };
#endif
