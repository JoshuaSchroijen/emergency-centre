#include "policealarm.h"
#include <iostream>
#include <sstream>
policealarm::policealarm(int alarmID): alarm{alarmID}//question here
{

}
void policealarm::ring(){

   std::cout << "The police is on his way now!" << std::endl;
}
