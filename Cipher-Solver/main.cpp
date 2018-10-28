//
//  main.cpp
//  Cryptogram
//
//  Created by Alec Shackett on 1/28/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//
#include "tools.hpp"
#include "Solver.hpp"

int main() {
    banner();
    Solver s = Solver();
    s.solve();
    bye();
}
