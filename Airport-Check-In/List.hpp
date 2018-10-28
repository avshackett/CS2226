//
//  List.hpp
//  AirportCheckIn
//
//  Created by Alec Shackett on 3/1/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include "tools.hpp"
#include "Person.hpp"

class List{
protected:
    class Cell{
    public:
        Cell(Cell *next, Agent ag) { this->next = next; this->ag = ag; }
        Cell(Cell *next, Group gr) { this->next = next; this->gr = gr; }
        ~Cell() = default;
        Cell *next;
        Agent ag;
        Group gr;
    };
    Cell *head = nullptr;
    Cell *scan = nullptr;
    Cell *prior = nullptr;
    int cnt = 0;
public:
    List() = default;
};

class PQueue : List{
public:
    PQueue() = default;
    void push(Agent ag);
    Agent pop();
    bool isempty();
    void print();
};

class Queue : List{
private:
    Cell *tail = nullptr;
public:
    Queue() = default;
    void push(Group gr);
    Group pop();
    bool isempty();
    void print();
};

#endif /* List_hpp */
