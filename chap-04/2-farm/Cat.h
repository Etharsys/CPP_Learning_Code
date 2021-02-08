#pragma once

#include "Animal.h"

#include <iostream>

class Cat : public Animal
{
public:
    void sing(char next) const override { std::cout << "Meow" << next; }
};
