#ifndef DELTAENCODING_DEFINE
#define DELTAENCODING_DEFINE

#include "../Compression/Compression.h"
#include <cstring>
class DeltaEncoding : public Compression{

	public:
		char* Compress(int* data,int dataSize) override;
		int* Decompress(char* data,int dataSize) override;
};

#endif