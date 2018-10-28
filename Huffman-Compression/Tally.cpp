//
//  Tally.cpp
//  HuffmanCompression
//
//  Created by Alec Shackett on 3/9/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#include "Tally.hpp"

void Tally::doTally(){
    ifstream inFile(fileName);
    if(!inFile) fatal("Can't open file for tallying.");
    char ch;
    for(;;){
        inFile.get(ch);
        if(inFile.eof()) break;
        tallyArray[ch]++;
    }
    inFile.close();
}
