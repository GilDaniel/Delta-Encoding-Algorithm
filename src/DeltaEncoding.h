#ifndef DELTAENCODING_H
#define DELTAENCODING_H

#include <cstddef>

class DeltaEncoding{

	public:
		std::byte* Encode(std::byte* data);
		std::byte* Decode(std::byte* data);
};

#endif