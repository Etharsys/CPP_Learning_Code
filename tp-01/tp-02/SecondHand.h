#pragma once

#include <iostream>

#include "MinuteHand.h"

class SecondHand {
    public:
        int get_seconds () { return _seconds; }
        SecondHand (MinuteHand& min);
        void advance();


    private:
        int _seconds = 0;
        MinuteHand& _min_hand;
};