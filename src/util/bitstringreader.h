#ifndef BITSTRINGREADER_H
#define BITSTRINGREADER_H

class BitstringReader
{
private:
    using ulong = unsigned long long;
    using uint = unsigned int;

    uint block;
    uint bit;
    const ulong* bitstring;
    static const uint blockLenght = sizeof(ulong)*8;

public:
    BitstringReader(const ulong* bitstring) {
        this->bitstring = bitstring;
        block = bit = 0;
    }

    inline uint read(uint numOfBits) {
        uint word;

        //Word partition between two blocks
        if (bit + numOfBits > blockLenght) {
            uint bitsInCurrent = blockLenght - bit;
            uint bitsInNext = numOfBits - bitsInCurrent;

            ulong maskCurrent = ~(0xFFFFFFFFFFFFFFFF >> bitsInCurrent);
            uint maskNext = ~(0xFFFFFFFF << bitsInNext);

            word = (uint)(((bitstring[block] & maskCurrent) >> bit) | ((uint)(bitstring[block+1] & maskNext) << bitsInCurrent));

            bit = (bit+numOfBits)%blockLenght;
            ++block;
        }
        else {
            uint mask = ~(0xFFFFFFFF << numOfBits);
            word = (uint)(bitstring[block] >> bit) & mask;
            bit += numOfBits;

            //The word finishes at the same bit as the block
            if (bit == blockLenght) {
                ++block;
                bit = 0;
            }
        }

        return word;
    }
};

#endif // BITSTRINGREADER_H
