#include "PhoneNumber.h"

PhoneNumber::PhoneNumber(int n1, int n2, int n3, int n4, int n5)
    : _number { Num {n1, n2, n3, n4, n5} }
{ }

Num PhoneNumber::getNumber()
{
    return _number;
}

bool PhoneNumber::is_valid()
{
    for (auto n : _number)
    {
        if (n < 0 || n > 99) 
        { 
            return false;
        }
    }
    return true;
}