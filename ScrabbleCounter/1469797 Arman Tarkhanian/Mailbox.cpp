#include "Mailbox.h"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

Mailbox::Mailbox( ) {
    my_Size = 0;
    my_Contents = 0;
    my_Address = "?address?";
}

Mailbox::Mailbox( string address ) {
    my_Size = 0;
    my_Contents = 0;
    my_Address = address;
}
Mailbox::Mailbox( int size ) {
    my_Size = size;
    my_Contents = size;
    my_Address = "?address?";
}
Mailbox::Mailbox( int size, int contents ) {
    my_Size = size;
    my_Contents = contents;
    my_Address = "?address?";
}

void Mailbox::setAddress( string address ) {
    my_Address = address;
}

string Mailbox::getAddress() {
    return( my_Address );
}

int    Mailbox::getSize() {
    return( my_Size );
}

void   Mailbox::setSize( int size ) {
    if (my_Contents < size)
        my_Size = size;
    else{
        throw logic_error("Too small");
    }
}

int    Mailbox::getContents() {
    return( my_Contents );
}

int    Mailbox::deliverMail( int pieces ) {
    if (pieces>0)
        my_Contents += pieces;
    else
        throw logic_error( "Negative delivery" );
    //    cout << "--> this mailbox has " << my_Contents << " pieces of mail" << endl;
    return( 49 * pieces );
}

void   Mailbox::pickupMail( ) {
    cout << "--> you picked up " << my_Contents << " pieces of mail from this mailbox" << endl;
    my_Contents = 0;
    
}

const Mailbox operator+ (const Mailbox& left, const Mailbox& right) {
    Mailbox temp = Mailbox(left.my_Contents + right.my_Contents);
    if (temp.my_Contents > temp.my_Size){
        cout << "Contents are too much! Throwing away excess.\n";
        temp.my_Contents = temp.my_Size;
        return temp;
    }
    else{
        return temp;
    }
}
const Mailbox operator- (const Mailbox& left, const Mailbox& right) {
    Mailbox temp = Mailbox(left.my_Contents - right.my_Contents);
    if (temp.my_Contents > 0)
        return temp;
    else{
        throw logic_error( "Subtraction failed" );
    }
}

ostream& operator <<( ostream& outs, const Mailbox& mailbox ) {
    cout << mailbox.my_Contents << " pieces of mail in this mailbox\n";
    return( outs );
}
istream& operator >>( istream& ins, Mailbox& mailbox ){
    int i = 0;
    ins >> i;
    mailbox.setSize(i);
    return( ins );
}
bool   operator <( const Mailbox& left, const Mailbox& right ) {
    return( left.my_Size < right.my_Size );
}
bool   operator >( const Mailbox& left, const Mailbox& right ) {
    return( left.my_Size > right.my_Size );
}
bool   operator <=( const Mailbox& left, const Mailbox& right ){
    return( left.my_Size <= right.my_Size );
}
bool   operator >=( const Mailbox& left, const Mailbox& right ) {
    return( left.my_Size >= right.my_Size );
}
bool   operator ==( const Mailbox& left, const Mailbox& right ) {
    return( left.my_Size == right.my_Size && left.my_Contents == right.my_Contents && left.my_Address == right.my_Address);
}
bool   operator !=( const Mailbox& left, const Mailbox& right ) {
    return( left.my_Size != right.my_Size || left.my_Contents != right.my_Contents || left.my_Address != right.my_Address );
}