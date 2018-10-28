//
//  Encode.hpp
//  HuffmanCompression
//
//  Created by Alec Shackett on 5/2/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#ifndef Encode_hpp
#define Encode_hpp

#include <stdio.h>
#include "tools.hpp"
#include "Heap.hpp"
#include "BitOStream.hpp"

class Encode{
private:
    map<char, string> encoded;
    string temp = "";
public:
    Encode();
    ~Encode() = default;
    void buildMap(Node* scan, string s);
    void printMap(ostream& out);
    void writeToFile(string fileName, ofstream& out);
};

#endif /* Encode_hpp */
