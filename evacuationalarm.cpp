#include <iostream>

#include "evacuationalarm.h"

void Evacuationalarm::operator() ( ) const {
    std::cout << "Please take your valuables and evacuate immediately!\n";
}
