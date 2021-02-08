#pragma once

#include <iostream>

class Animal
{
public:
    virtual ~Animal() { };
    virtual void sing(char next) const { std::cout << "..." << next; }
};
