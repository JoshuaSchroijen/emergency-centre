#include "firealarm.h"

Firealarm::Firealarm ( int originalID ) :
    Alarm ( originalID ) {
}

void Firealarm::operator() ( const std::string & origin ) const {
    std::cout << origin
              << " signaled fire alarm with ID " + std::to_string ( ID ) + ".\n"
              << "Contacting the fire department!\n"
              << "Evacuate the building immediately!\n";
}

