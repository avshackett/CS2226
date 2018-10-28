//
//  Solver.cpp
//  Cryptogram
//
//  Created by Alec Shackett on 2/15/17.
//  Copyright © 2017 Alec Shackett. All rights reserved.
//

#include "Solver.hpp"

inline unsigned ord(char ch) { return ch - 'A'; }
inline char chr(unsigned ui) { return ui + 'A'; }

Solver::Solver(){
    cTextSize = 0;
    ifstream inFile("p3.txt");
    if(!inFile) fatal("Cannot open file p3.txt for input");
    string temp;
    getline(inFile, temp);
    for(int x = 0; x < temp.length(); ++x){
        codeText.push_back(toupper(temp[x]));
        if(isalpha(temp[x])){
            plainText.push_back('_');
            cTextSize++;
        }
        else plainText.push_back(temp[x]);
    }
    inFile.close();
    
    ifstream frFile("freq.txt");
    if(!frFile) fatal("Cannot open file freq.txt for input");
    char ch;
    double db;
    while(!frFile.eof()){
        frFile >> ch >> db;
        engTextF[toupper(ch)-'A'] = Freq(toupper(ch), db);
    }
    tally();
    sort(begin(engTextF), end(engTextF), Freq::descend);
    sort(begin(cTextF), end(cTextF), Freq::descend);
}

void Solver::tally(){
    for(int x = 0; x < 25; ++x) tal[x] = 0;
    for(int x = 0; x < codeText.size(); ++x){
        if(isalpha(codeText.at(x))) tal[ord(codeText.at(x))]++;
    }
    scale();
}

void Solver::scale(){
    for(int x = 0; x < 25; ++x){
        if(tal[x] > 0){
            cTextF[x] = Freq(chr(x), (tal[x] * 100.0 ) / cTextSize);
        }
    }
}

void Solver::print(){
    for(int x = 0; x < codeText.size(); ++x) cout << codeText.at(x);
    cout << endl;
    for(int x = 0; x < plainText.size(); ++x) cout << plainText.at(x);
    cout << endl;
}

void Solver::printFreq(){
    cout << setw(7) << "English" << " " << "Codetext" << endl;
    for(int x = 0; x < 25; ++x){
        engTextF[x].print();
        cout << " ";
        cTextF[x].print();
        cout << endl;
    }
}

void Solver::solve(){
    printFreq();
    cout << endl;
    print();
    int win = 0;
    char ch, cp, ce;
    bool cont = true;
    while(cont == true){
        cout << endl;
        cout << "1) Replace, 2) Erase, 3) ShowFreq, 4) Give up:";
        cin >> setw(1) >> ch;
        
        switch (ch) {
            case '1':
                win = 0;
                cin >> setw(2) >> ce >> cp;
                cout << endl;
                for(int x = 0; x < codeText.size(); ++x) if(toupper(ce) == codeText.at(x) && toupper(cp) == solution[x]) plainText.at(x) = toupper(cp);
                print();
                for(int x = 0; x < plainText.size(); ++x) if(plainText.at(x) == solution[x]) ++win;
                if(win == plainText.size()){
                    cont = false;
                    cout << "You win!";
                }
                break;
            case '2':
                cin >> setw(1) >> ch;
                for(int x = 0; x < codeText.size(); ++x) if(toupper(ch) == plainText.at(x)) plainText.at(x) = '_';
                cout << endl;
                print();
                break;
            case '3':
                print();
                cout << endl;
                printFreq();
                break;
            case '4':
                cout << endl;
                cout << "You'll get it next time! Goodbye!" << endl;
                cont = false;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}
