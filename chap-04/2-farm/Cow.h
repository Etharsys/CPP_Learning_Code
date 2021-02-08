#pragma once

#include "Animal.h"

#include <iostream>

class Cow : public Animal
{
public:
    void sing(char next) const override { std::cout << "Mewwwwwh" << next; }
};
