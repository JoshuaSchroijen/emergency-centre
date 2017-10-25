#include "firealarm.h"
#include <iostream>
#include <sstream>
Firealarm::Firealarm(int alarmID):alarm{alarmID}
{

}
void Firealarm::ring(){

    std::cout << "The fireman are on his way!" <<  std::endl;

}
