//
//  Encode.cpp
//  HuffmanCompression
//
//  Created by Alec Shackett on 5/2/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#include "Encode.hpp"

Encode::Encode(){

}

void Encode::buildMap(Node* scan, string s){
    if(scan->getCh() != '*') encoded[scan->getCh()] = s;
    if(scan->getLeft() != nullptr) buildMap(scan->getLeft(), s + "0");
    if(scan->getRight() != nullptr) buildMap(scan->getRight(), s + "1");
}

void Encode::printMap(ostream& out){
    out << endl << "Table:" << endl;
    for(auto it : encoded) {
        if(isprint(it.first)) out << it.first << ": " << it.second << '\n';
        else out << "0x" << (int)it.first << ": " << it.second << '\n';
    }
    out << endl;
}

void Encode::writeToFile(string fileName, ofstream& out){
    char ch;
    ifstream file(fileName);
    BitOStream b = BitOStream(out);
    for(;;){
        file.get(ch);
        if(file.eof()) break;
        b.insertCode(encoded.at(ch));
    }
    b.flushByte();
    file.close();
}
