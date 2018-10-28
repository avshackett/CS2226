//
//  Heap.cpp
//  HuffmanCompression
//
//  Created by Alec Shackett on 3/9/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#include "Heap.hpp"

//Node=====================================================================

void Node::print(){
    if(isprint(ch)) cout << ch << " " << freq << endl;
    else cout  << "0x" <<  hex << (int)ch << dec << " " << freq << endl;
}

//Heap=====================================================================

Heap::Heap(int* tal){
    for(int x = 0; x < 256; ++x) if(tal[x] > 0) nAry[++heapSize] = new Node(x, tal[x]);
    buildHeap();
}

void Heap::downHeap(int k, Node* cur){
    int parent = k, lchild, rchild;
    for(;;){
        lchild = 2 * parent;  //Left son
        rchild = lchild + 1;  //Right son
        if(lchild >= heapSize) break;
        if(rchild <= heapSize && nAry[lchild]->freq > nAry[rchild]->freq) lchild = rchild;
        if(cur->freq <= nAry[lchild]->freq) break;
        nAry[parent] = nAry[lchild];
        parent = lchild;
    }
    nAry[parent] = cur;
}

void Heap::upHeap(int k, Node* cur){
    int child = k, parent;
    for(;;){
        parent = child / 2;
        if(heapSize == 1) break;
        if(nAry[parent]->freq <= cur->freq) break;
        nAry[child] = nAry[parent];
        child = parent;
    }
    nAry[child] = cur;
}

void Heap::push(Node* n){
    nAry[++heapSize] = n;
    upHeap(heapSize, nAry[heapSize]);
}

Node* Heap::pop(){
    Node* temp = nAry[1];
    nAry[1] = nAry[heapSize--];
    buildHeap();
    return temp;
}

void Heap::reduceHeap(){
    for(;heapSize > 1;){
        Node* temp1 = pop();
        Node* temp2 = pop();
        push(new Node(temp1, temp2));
    }
}

void Heap::printTreeReal(ostream& out, Node* scan, string indent){
    if(scan == NULL){
        out << indent + "———-" << endl;
        return;
    }
    printTreeReal(out, scan->left, indent+"   ");
    if(isprint(scan->ch)) out << indent << scan->ch << " " << scan->freq << endl;
    else out << indent << hex << "0x" << (int)scan->ch << dec << " " << scan->freq << endl;
    printTreeReal(out, scan->right, indent+"   ");
}
