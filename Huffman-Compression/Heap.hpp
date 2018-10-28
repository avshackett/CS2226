//
//  Heap.hpp
//  HuffmanCompression
//
//  Created by Alec Shackett on 3/9/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#ifndef Heap_hpp
#define Heap_hpp

#include <stdio.h>
#include "tools.hpp"
#include "Tally.hpp"

class Node{
    friend class Heap;
private:
    char ch;
    int freq;
    Node* left;
    Node* right;
public:
    Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
    Node(Node* left, Node* right) : ch('*'), freq(left->freq + right->freq), left(left), right(right) {}
    Node() = default;
    ~Node() = default;
    Node* getLeft() { return this->left; }
    Node* getRight() { return this->right; }
    char getCh() { return this->ch; }
    void print();
};

class Heap{
private:
    Node* nAry[257];
    int heapSize = 0;
    string code = "";
public:
    Heap(int* tal);
    void downHeap(int k, Node* cur);
    void upHeap(int k, Node* cur);
    void buildHeap() { for(int x = (heapSize / 2); x > 0; --x) downHeap(x, nAry[x]); }
    void printHeap() { cout << "Heap:" << endl; for(int x = 1; x < heapSize + 1; ++x) nAry[x]->print(); }
    void printTree() { cout << "Tree:" << endl; printTreeReal(cout, nAry[1], ""); }
    void printTreeReal(ostream& out, Node* scan, string indent);
    void push(Node* n);
    Node* pop();
    void reduceHeap();
    void encode(Node* current);
    Node* getTree() { return nAry[1]; }
};

#endif /* Heap_hpp */
