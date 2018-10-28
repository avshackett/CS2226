//
//  Solver.hpp
//  Cryptogram
//
//  Created by Alec Shackett on 2/15/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#ifndef Solver_hpp
#define Solver_hpp

#include <stdio.h>
#include "tools.hpp"
#include "Freq.hpp"
typedef char BT;

class Solver{
private:
    fstream(message),(eFreq);
    vector<BT> codeText, plainText;
    string solution = "I AM REALLY BAD AT THINKING OF SAMPLE TEXTS";
    Freq cTextF[26], engTextF[26];
    void scale();
    int tal[26];
    int cTextSize;
public:
    Solver();
    void tally();
    void print();
    void printFreq();
    void solve();
};
#endif /* Solver_hpp */
