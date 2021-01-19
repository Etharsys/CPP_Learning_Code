#include "Clock.h"
#include "SecondHand.h"
#include "MinuteHand.h"

Clock::Clock()
    : _minutes { MinuteHand { } }, _seconds { SecondHand { _minutes } }
{ }

void Clock::tick()
{
    _seconds.advance();
}