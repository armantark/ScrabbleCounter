//
//  ScrabbleCounter.h
//  ScrabbleCounter
//
//  Created by Arman Tarkhanian on 8/2/15.
//  Copyright (c) 2015 Arman Tarkhanian. All rights reserved.
//

#ifndef __ScrabbleCounter__ScrabbleCounter__
#define __ScrabbleCounter__ScrabbleCounter__

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
class ScrabbleCounter{
public:
    ScrabbleCounter();
    
    void setString( string value );
    void setCString( char * value );
    void clear();
    int getScrabbleValue() const;
    
    friend ostream& operator <<( ostream& outs, const ScrabbleCounter & c );
private:
    string myScrabbleString;
};
#endif /* defined(__ScrabbleCounter__ScrabbleCounter__) */
