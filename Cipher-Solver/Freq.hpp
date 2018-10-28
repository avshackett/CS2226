//
//  Freq.hpp
//  Cryptogram
//
//  Created by Alec Shackett on 2/15/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#ifndef Freq_hpp
#define Freq_hpp

#include <stdio.h>
#include "tools.hpp"

class Freq{
private:
    char ch;
    double pct;
public:
    Freq() = default;
    Freq(char ch, double perc);
    void print();
    void print(ostream& out);
    static bool descend(const Freq& f1, const Freq& f2){ return f1.pct > f2.pct; }
};

inline ostream& operator<< (ostream& out, Freq fr) { fr.print(out); return out; }

#endif /* Freq_hpp */
