#pragma once

#include <iostream>

#include "Animal.h"

class Dog : public Animal
{
public:
    void sing(char next) const override { std::cout << "Waf" << next; }
};
