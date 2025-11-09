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
        // Returns compressed byte buffer. Caller is responsible for delete[] on the returned char*.
        char* Compress(int* data,int dataSize);
        // Decompress accepts the compressed byte buffer and the original data size.
        int* Decompress(char* data,int dataSize);
    };

#endif