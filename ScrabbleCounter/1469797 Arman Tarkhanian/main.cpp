//
//  main.cpp
//  ScrabbleCounter
//
//  Created by Arman Tarkhanian on 8/2/15.
//  Copyright (c) 2015 Arman Tarkhanian. All rights reserved.
//

#include <iostream>
#include "ScrabbleCounter.h"
using namespace std;

int main() {
    ScrabbleCounter s;
    string str( "hello" );
    
    s.setCString( "Hello" );
    cout << s << endl;
    // should print: "Hello = 8"
    
    s.clear();
    s.setString( str );
    cout << s << endl;
    // should print: "hello = 8"
}
