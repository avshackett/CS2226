//-----------------------------------------------------------------
//  BitOStream.cpp
//  HuffEncode
//  Created by Alice Fischer on 1/3/16.

#include "BitOStream.hpp"

//-----------------------------------------------------------------
// Pack one bit into the bitOutput stream.
void BitOStream::
insertBit ( int c ){
    bits <<= 1;         // Make space for new bits.
    bits |= (c & 1);    // OR in the single low order bit.
    len ++;             // This BitStream is now longer.
    if (len == 8) {
        if ( bits==0 ) cout <<"About to write a zero byte." << endl;
        bytecount++;
        //cout<< bits;
        bitOut << bits;
        bitset<8> x(bits);
        //cout <<"start" <<x <<endl;
        len = bits = 0;
    }
}

//-----------------------------------------------------------------
// Pack a string of bits (a letter code) into the bitOutput stream.
void BitOStream::
insertCode ( string s ){
    size_t n = s.length();
    for (size_t k=0; k<n; ++k) {
        insertBit ( s[k]-'0' );
    }
}

//-----------------------------------------------------------------
// Called at the end of output for the code tree and for the encoded message.
void BitOStream::
flushByte(){
     if (len != 0) {
        cout << "About to write padded byte" << endl;
        //bitOut << bits;
         int k= len;          //cout <<"Bits" << (8-len);
        for (int k=len; k<8; ++k) insertBit(0); // Pad out, flush the last byte.
         bitOut << char(8-k);
         //cout<<k;
    }
     else
     {
    bitOut<<0;
    cout << "No padding needed" << endl;
    cout << "\nFlushing bitOStream, wrote " <<bytecount <<" bytes\n";
     }
}
