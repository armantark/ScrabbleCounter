//
//  ScrabbleCounter.cpp
//  ScrabbleCounter
//
//  Created by Arman Tarkhanian on 8/2/15.
//  Copyright (c) 2015 Arman Tarkhanian. All rights reserved.
//

#include "ScrabbleCounter.h"
#include <stdio.h>
#include <iostream>
#include <string>
ScrabbleCounter::ScrabbleCounter(){
    myScrabbleString = "";
}

void ScrabbleCounter::setString(string value){
    myScrabbleString = value;
}

void ScrabbleCounter::setCString(char * value){
    myScrabbleString = value;
}

void ScrabbleCounter::clear(){
    myScrabbleString = "";
}

int ScrabbleCounter::getScrabbleValue() const{
    int value = 0;
    for (int i = 0;i<myScrabbleString.length();i++){
        switch (myScrabbleString.at(i)) {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'O':
            case 'o':
            case 'N':
            case 'n':
            case 'R':
            case 'r':
            case 'T':
            case 't':
            case 'L':
            case 'l':
            case 'S':
            case 's':
            case 'U':
            case 'u':
                value += 1;
                break;
            case 'D':
            case 'd':
            case 'G':
            case 'g':
                value += 2;
                break;
            case 'B':
            case 'b':
            case 'C':
            case 'c':
            case 'M':
            case 'm':
            case 'P':
            case 'p':
                value += 3;
                break;
            case 'F':
            case 'f':
            case 'H':
            case 'h':
            case 'V':
            case 'v':
            case 'W':
            case 'w':
            case 'Y':
            case 'y':
                value += 4;
                break;
            case 'K':
            case 'k':
                value += 5;
                break;
            case 'J':
            case 'j':
            case 'X':
            case 'x':
                value += 8;
                break;
            case 'Q':
            case 'q':
            case 'Z':
            case 'z':
                value += 10;
                break;
            default:
                break;
        }
    }
    
    return value;
}

ostream& operator <<( ostream& outs, const ScrabbleCounter& c ){
    cout << c.myScrabbleString << " = " << c.getScrabbleValue();
    return( outs );
}

