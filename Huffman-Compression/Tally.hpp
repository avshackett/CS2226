//
//  Tally.hpp
//  HuffmanCompression
//
//  Created by Alec Shackett on 3/9/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#ifndef Tally_hpp
#define Tally_hpp

#include <stdio.h>
#include "tools.hpp"

class Tally{
private:
    string fileName;
    int tallyArray[256] = {0};
public:
    Tally(string fileName) : fileName(fileName) {}
    ~Tally() {}
    void doTally();
    int& getTally() { return tallyArray[0]; }
};

#endif /* Tally_hpp */
