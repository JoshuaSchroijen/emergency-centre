#ifndef POLICEALARM_H
#define POLICEALARM_H

#include <iostream>

#include "alarm.h"

class Policealarm : public Alarm {
    public:
        void operator() ( );
};

#endif
