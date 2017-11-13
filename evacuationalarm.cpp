#include <iostream>

#include "evacuationalarm.h"

Evacuationalarm::Evacuationalarm ( int originalID ) :
    Alarm ( originalID ) {
}

void Evacuationalarm::operator() ( const std::string & origin ) const {
    std::cout << origin
              << " signaled evacuation alarm with ID " + std::to_string ( ID ) + ".\n"
              << "Contacting the fire department!\n"
              << "Evacuate the building immediately!\n";
}
