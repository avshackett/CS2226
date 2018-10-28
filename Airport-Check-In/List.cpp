//
//  List.cpp
//  AirportCheckIn
//
//  Created by Alec Shackett on 3/1/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#include "List.hpp"

//PQueue functions
void PQueue::push(Agent ag){
    if(isempty()) head = new Cell(nullptr, ag);
    else{
        scan = head;
        prior = head;
        for(;;){
            if(ag.getET() > scan->ag.getET() && scan->next != nullptr){
                prior = scan;
                scan = scan->next;
            }
            else if(ag.getET() > scan->ag.getET() && scan->next == nullptr){
                scan->next = new Cell(nullptr, ag);
                break;
            }
            else if(ag.getET() < scan->ag.getET() && cnt == 1){
                head = new Cell(scan, ag);
                break;
            }
            else{
                prior->next = new Cell(prior->next, ag);
                break;
            }
        }
    }
    cnt++;
}

Agent PQueue::pop(){
    scan = head;
    head = head->next;
    Agent temp = scan->ag;
    delete scan;
    cnt--;
    return temp;
}

bool PQueue::isempty(){
    if(head == nullptr) return true;
    else return false;
}

void PQueue::print(){
    for(scan = head; scan != nullptr; scan = scan->next) scan->ag.print();
    cout << cnt << endl;
}

//Queue functions
void Queue::push(Group gr){
    if(isempty()) head = tail = new Cell(nullptr, gr);
    else{
        tail->next = new Cell(nullptr, gr);
        prior = tail;
        tail = tail->next;
    }
    cnt++;
}

Group Queue::pop(){
    scan = head;
    head = head->next;
    Group temp = scan->gr;
    delete scan;
    cnt--;
    return temp;
}

bool Queue::isempty(){
    if(head == nullptr) return true;
    else return false;
}

void Queue::print(){
    for(scan = head; scan != nullptr; scan = scan->next) scan->gr.print();
    cout << cnt << endl;
}
