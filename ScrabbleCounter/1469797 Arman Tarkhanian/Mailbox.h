#ifndef MAILBOX_H
#define MAILBOX_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
using namespace std;

class Mailbox {
public:
    Mailbox();                  // a new empty mailbox
    Mailbox( string address );  // a new empty mailbox, if you know its address
    Mailbox( int size );
    Mailbox( int size, int contents );
    
    void   setAddress( string address );
    string getAddress();
    int    getSize();
    void   setSize( int size );
    int    getContents();
    
    int    deliverMail( int pieces );
    void   pickupMail( );
    
    friend const Mailbox operator + (const Mailbox& left, const Mailbox& right);
    friend const Mailbox operator - (const Mailbox& left, const Mailbox& right);
    friend std::ostream& operator <<( std::ostream& outs, const Mailbox& mailbox );
    friend std::istream& operator >>( std::istream& ins, Mailbox& mailbox );
    
    friend bool   operator <( const Mailbox& left, const Mailbox& right );
    friend bool   operator >( const Mailbox& left, const Mailbox& right );
    friend bool   operator <=( const Mailbox& left, const Mailbox& right );
    friend bool   operator >=( const Mailbox& left, const Mailbox& right );
    friend bool   operator ==( const Mailbox& left, const Mailbox& right );
    friend bool   operator !=( const Mailbox& left, const Mailbox& right );
private:
    int my_Size;
    int my_Contents;
    string my_Address;
};


#endif