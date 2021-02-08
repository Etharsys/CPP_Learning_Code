#pragma once

#include "Animal.h"

#include <iostream>

class Chicken : public Animal
{
public:
    ~Chicken () override
    {
        std::cout << "Cocooooooooooot!" << std::endl;
    }

    void sing(char next) const override { std::cout << "Cotcotcotcodet" << next; }
};
