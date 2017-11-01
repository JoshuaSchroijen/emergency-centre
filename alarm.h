#ifndef ALARM_H
#define ALARM_H

class Alarm {
    public:
        virtual void operator() ( ) const = 0;
};

#endif
