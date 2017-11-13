#include "policealarm.h"

Policealarm::Policealarm ( int originalID ) :
    Alarm ( originalID ) {
}

void Policealarm::operator() ( const std::string & origin ) const {
    std::cout << origin
              << " signaled fire alarm with ID " + std::to_string ( ID ) + ".\n"
              << "Contacting the police!\n";
}
