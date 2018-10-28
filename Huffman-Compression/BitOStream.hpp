//-----------------------------------------------------------------
//  BitOStream.hpp
//  Huffman and HuffEncode
//  Created by Alice Fischer on 1/3/16.

#ifndef BitOStream_hpp
#define BitOStream_hpp

#include "tools.hpp"
#include "Heap.hpp"

//-----------------------------------------------------------------
class BitOStream {
private:
    int len=0;
    unsigned char bits; // The bitcode for this letter, packed
    ofstream& bitOut;
    int bytecount=0;


public:
    BitOStream( ofstream& out ) : bitOut( out ) {};
    BitOStream() = delete;
    ~BitOStream() = default;
    void insertCode ( string s );
    void insertBit ( int c );
    void insertChar ( unsigned char newChar );
    void flushByte();
    void writeCount();
};

#endif /* BitStream_hpp */
