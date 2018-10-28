//
//  main.cpp
//  AirportCheckIn
//
//  Created by Alec Shackett on 2/27/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#include <iostream>
#include "Simulation.hpp"

#define INF "input.txt"

int main() {
    banner();
    Simulation s = Simulation(INF);
    s.checkIn();
    bye();
}
