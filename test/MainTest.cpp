#include <iostream>
#include "../src/DeltaEncoding.h"



int main(){


    std::byte *dataToEncode = new std::byte[1000];
    DeltaEncoding deltaEncoder;
    std::byte *encoded = deltaEncoder.Encode(dataToEncode);
    
}

