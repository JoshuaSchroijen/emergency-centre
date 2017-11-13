#ifndef EVACUATIONALARM_H
#define EVACUATIONALARM_H

#include "alarm.h"

class Evacuationalarm : public Alarm {
    public:
        Evacuationalarm ( int originalID );

        void operator() ( const std::string & origin ) const override;
};

#endif
