#ifndef COMPRESSION_HANDLER_DEFINE
#define COMPRESSION_HANDLER_DEFINE
    
    #include "./Compression/Compression.h"

   
    class CompressionHandler{

        protected:
            Compression& compression;
            bool logData;

        public:
            CompressionHandler(Compression& compressionAlgorithm,bool logData = true): compression(compressionAlgorithm){
                CompressionHandler::logData = logData;
            };
            int* Compress(int* data,int dataSize);
            int* Decompress(int* data,int dataSize);
    };

#endif