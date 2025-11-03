#ifndef DELTAENCODING_DEFINE
#define DELTAENCODING_DEFINE

#include "../Compression/Compression.h"

class DeltaEncoding : public Compression{

	public:
		int* Compress(int* data,int dataSize) override;
		int* Decompress(int* data,int dataSize) override;
};

#endif