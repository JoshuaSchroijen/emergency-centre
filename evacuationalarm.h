#ifndef EVACUATIONALARM_H
#define EVACUATIONALARM_H

#include "alarm.h"

class Evacuationalarm : public Alarm {
    public:
        void operator() ( ) const;
};

#endif
