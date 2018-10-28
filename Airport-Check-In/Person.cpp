//
//  Person.cpp
//  AirportCheckIn
//
//  Created by Alec Shackett on 2/27/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#include "Person.hpp"

void Agent::handle(Group gr){
    float temp = 0;
    if(gr.getNumP() > 0) temp += 4;
    if(gr.getNumP() > 1) temp += gr.getNumP() - 1;
    if(gr.getNumB() > 0) temp += gr.getNumB() * .5;
    eT += temp;
}

void Group::print(){
    cout << name << " " << nP << " " << nB << endl;
}

void Agent::print(){
    cout << name << " " << eT << endl;
}
