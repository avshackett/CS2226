//
//  Tree.hpp
//  HuffmanCompression
//
//  Created by Alec Shackett on 3/9/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include "tools.hpp"

class Tree{
public:
private:
    class Node{
    public:
        Node(char ch, int in) { this->ch = ch; this->in = in; }
        Node(Node *left, Node* right) { this->left = left; this->right = right; }
        Node() = default;
        ~Node() = default;
        void print();
        char ch;
        int in;
        Node *left = nullptr;
        Node *right = nullptr;
    };

};

#endif /* Tree_hpp */
