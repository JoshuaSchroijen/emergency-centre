 #ifndef FIREALARM_H
#define FIREALARM_H

#include <iostream>

#include "alarm.h"

class Firealarm : public Alarm {
    public:
        Firealarm ( int originalID );

        void operator() ( const std::string & origin ) const override;
};

#endif
