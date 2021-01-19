#include "SecondHand.h"

SecondHand::SecondHand (MinuteHand& min) 
    : _min_hand { min } 
{ }

void SecondHand::advance ()
{
    if (_seconds >= 60)
    {
        _seconds = 0;
        _min_hand.advance();
    } else {
        _seconds ++;
    }
}