//
//  Simulation.cpp
//  AirportCheckIn
//
//  Created by Alec Shackett on 3/1/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#include "Simulation.hpp"

Simulation::Simulation(string inName){
    q = Queue();
    pQ = PQueue();
    cout << "Input number of agents:" << endl;
    cin >> numA;
    for(int x = 0; x < numA; ++x){
        string temp = "Agent" + to_string(numA - x);
        Agent ag = Agent(temp);
        pQ.push(ag);
    }
    getGroups(inName);
}

void Simulation::getGroups(string inName){
    ifstream inFile(inName);
    string fName;
    int ppl;
    int bag;
    for(;;){
        inFile >> fName >> ppl >> bag;
        if(inFile.eof()) break;
        Group gr = Group(fName, ppl, bag);
        q.push(gr);
    }
}

void Simulation::checkIn(){
    Group gr;
    Agent ag;
    for(;;){
        if(q.isempty()) break;
        gr = q.pop();
        ag = pQ.pop();
        cL = ag.getET();
        ag.handle(gr);
        pQ.push(ag);
        cout << left << setw(5) << cL << setw(8) << ag.getName() << setw(10) << gr.getName() << setw(5) << ag.getET() << endl;
    }
    if(cL <= 90) cout << "Flight is running on time!" << endl;
    else cout << "Flight will be late!" << endl;
}
    

