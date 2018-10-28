//
//  main.cpp
//  HuffmanCompression
//
//  Created by Alec Shackett on 3/9/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#include <iostream>
#include "Tally.hpp"
#include "Heap.hpp"
#include "Encode.hpp"
#include "tools.hpp"

int main(){
    banner();
    string filename;
    cout << "Input filename:" << endl;
    cin >> filename;
    Tally tal = Tally(filename);
    tal.doTally();
    Heap h = Heap(&tal.getTally());
    h.printHeap();
    h.reduceHeap();
    h.printTree();
    Encode e = Encode();
    e.buildMap(h.getTree(), "");
    e.printMap(cout);
    ofstream output("output.txt");
    e.writeToFile(filename, output);
}
