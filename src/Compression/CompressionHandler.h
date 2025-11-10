#ifndef COMPRESSION_HANDLER_DEFINE
#define COMPRESSION_HANDLER_DEFINE
    
    #include "Compression.h"

   
    class CompressionHandler{

        protected:
            Compression& compression;
            bool logData;

        public:
            CompressionHandler(Compression& compressionAlgorithm,bool logData = true): compression(compressionAlgorithm){
                CompressionHandler::logData = logData;
            };
        char* Compress(int* data,int dataSize);
        int* Decompress(char* data,int dataSize);
    };

#endif
