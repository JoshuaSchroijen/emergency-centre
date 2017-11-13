#include "alarm.h"

Alarm::Alarm ( int originalID ) :
    ID ( originalID ) {
}

int Alarm::getID ( ) {
    return ( ID );
}

void Alarm::setID ( int newID ) {
    ID = newID;
}
