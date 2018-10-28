//
//  Simulation.hpp
//  AirportCheckIn
//
//  Created by Alec Shackett on 3/1/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#ifndef Simulation_hpp
#define Simulation_hpp

#include <stdio.h>
#include "tools.hpp"
#include "List.hpp"
#include "Person.hpp"

class Simulation{
private:
    ifstream inFile;
    Queue q;
    PQueue pQ;
    int numA;
    float cL = 0;
public:
    Simulation(string inName);
    void getGroups(string inName);
    void checkIn();
};

#endif /* Simulation_hpp */
