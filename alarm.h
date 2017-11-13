#ifndef ALARM_H
#define ALARM_H

#include <string>

class Alarm {
    protected:
        int ID;
    public:
        Alarm ( int originalID );

        int getID ( );
        void setID ( int newID );

        virtual void operator() ( const std::string & origin ) const = 0;
};

#endif
