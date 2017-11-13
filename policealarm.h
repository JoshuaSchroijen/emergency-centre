#ifndef POLICEALARM_H
#define POLICEALARM_H

#include <iostream>

#include "alarm.h"

class Policealarm : public Alarm {
    public:
        Policealarm ( int originalID );

        void operator() ( const std::string & origin ) const override;
};

#endif
