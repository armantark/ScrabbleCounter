#include <iostream>
#include <string>
#include <stdexcept>
#include "Mailbox.h"
using namespace std;

int main() {
    Mailbox yours( "your address" );
    Mailbox mine( "1900 Pico Boulevard" );
    Mailbox test( "test" );
    
    
    yours.setSize( 10 );
    mine.setSize( 10 );
    test.setSize( 5 );
    
    yours.deliverMail( 5 );
    mine.deliverMail( 6 );
    test.deliverMail( 5 );
    
    
    cout << test << endl;
    
    
    try {
        // contents will become negative...
        // an exception should get thrown
        test = yours - mine;
    } catch( std::logic_error le ) {
        cout << "subtraction failed" << endl;
    }
    
    
    /// test should be unchanged
    cout << test << endl;
    
    try {
        // how can you deliver negative pieces of mail??
        // an exception should get thrown
        test.deliverMail( -100 );
    } catch( std::logic_error le ) {
        cout << "deliverMail failed" << endl;
    }
    
    /// test should be unchanged
    cout << test << endl;
    
    try {
        // how can you have 5 pieces of mail in a box that
        // can only hold 3??
        // an exception should get thrown
        test.setSize( 3 );
    } catch( std::logic_error le ) {
        cout << "setSize failed" << endl;
    }
    
    /// test should be unchanged
    cout << test << endl;
    
    try {
        // how can you have a negative size??
        test.setSize( -33 );
    } catch( std::logic_error le ) {
        cout << "setSize failed" << endl;
    }
}
