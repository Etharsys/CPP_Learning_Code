#pragma once

#include <iostream>

#include "PhoneNumber.h"

class Person {
    public :
        Person (const std::string& fn, const std::string& ln);
        Person (const std::string& fn, const std::string& ln, const PhoneNumber& pn);
        std::string get_full_name();
        std::string get_first_name();
        PhoneNumber get_phone_number();
        void        set_phone_number(PhoneNumber pn);
        bool        operator<(const Person& person) const;


    private :
        std::string _first_name;
        std::string _last_name;
        PhoneNumber _phone_number;
};