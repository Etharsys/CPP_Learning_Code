#include "MinuteHand.h"

void MinuteHand::advance() 
{
    _minutes ++;
}

int MinuteHand::get_minutes () 
{ 
    return _minutes; 
}