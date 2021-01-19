#pragma once

#include <iostream>

class MinuteHand {
    public:
        int get_minutes();
        void advance();

    private:
        int _minutes = 0;
};