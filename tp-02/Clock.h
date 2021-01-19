#pragma once

#include <iostream>

#include "MinuteHand.h"
#include "SecondHand.h"

class Clock {
    public:
        Clock();
        void tick();
    
    private:
        MinuteHand _minutes;
        SecondHand _seconds;
};