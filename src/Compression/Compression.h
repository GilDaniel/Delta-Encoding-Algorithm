#ifndef COMPRESSION_DEFINE
#define COMPRESSION_DEFINE

    
    class Compression{

        public:
            virtual int* Compress(int* data,int dataSize) = 0;
            virtual int* Decompress(int* data,int dataSize) = 0;
    };
#endif