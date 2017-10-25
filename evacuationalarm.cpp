#include "evacuationalarm.h"
#include <iostream>
#include <sstream>

evacuationalarm::evacuationalarm( int alarmID ):alarm{alarmID}
{


}
void evacuationalarm::ring(){


    std:: cout << "Who let's the dog outside???" << std:: endl;
}
