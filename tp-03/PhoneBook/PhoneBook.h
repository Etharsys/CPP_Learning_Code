#pragma once

#include <iostream>
#include <set>

#include "Person.h"

class PhoneBook {
    public :
        void insert(const Person& person);
        bool empty ();
        Person& first_of_familly(const std::string& familly);
        Person  operator[] (int index);

    private :
        std::set<Person> _phone_book;
};