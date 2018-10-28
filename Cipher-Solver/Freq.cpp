//
//  Freq.cpp
//  Cryptogram
//
//  Created by Alec Shackett on 2/15/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#include "Freq.hpp"

Freq::Freq(char ch, double percent){
    this->ch = ch;
    this->pct = percent;
}

void Freq::print(){ if(ch != NULL && pct != 0) cout << setw(1) << ch << fixed << setprecision(2) << setw(6) << pct; }


