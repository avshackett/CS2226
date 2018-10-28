//
//  Person.hpp
//  AirportCheckIn
//
//  Created by Alec Shackett on 2/27/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include "tools.hpp"

class Person{
protected:
    string name;
public:
    Person(string name) { this->name = name; }
    Person() = default;
    virtual ~Person() = default;
};

class Group : Person{
private:
    int nP;
    int nB;
public:
    Group(string name, int nP, int nB) { this->name = name; this->nP = nP; this->nB = nB; }
    Group() = default;
    virtual ~Group() = default;
    int getNumP(){ return this->nP; }
    int getNumB(){ return this->nB; }
    void print();
    string getName() { return this->name; }
};

class Agent : Person{
private:
    float eT = 0;
public:
    Agent(string name) { this->name = name; }
    Agent() = default;
    virtual ~Agent() = default;
    void print();
    void handle(Group gr);
    string getName() { return this->name; }
    float getET() { return this->eT; }
};

#endif /* Person_hpp */
