 #ifndef FIREALARM_H
#define FIREALARM_H

#include <iostream>

#include "alarm.h"

class Firealarm : public Alarm {
    public:
        void operator() ( );
};

#endif
