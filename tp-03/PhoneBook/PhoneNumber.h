#pragma once

#include <iostream>
#include <array>

using Num = std::array<int, 5>;

class PhoneNumber {
    private :
        Num _number;

    public :
        PhoneNumber (int n1, int n2, int n3, int n4, int n5);
        Num getNumber();
        bool is_valid();
};