#include "Person.h"

using namespace std;

Person::Person (const string& fn, const string& ln)
    : Person {fn, ln, PhoneNumber {-1, 0, 0, 0, 0}}
{ }

Person::Person (const string& fn, const string& ln, const PhoneNumber& pn)
    : _first_name { fn }, _last_name { ln }, _phone_number { pn }
{ }

string Person::get_first_name()
{
    return _first_name;
}

string Person::get_full_name()
{
    return _first_name + " " + _last_name;
}

PhoneNumber Person::get_phone_number()
{
    return _phone_number;
}

void Person::set_phone_number(PhoneNumber pn)
{
    _phone_number = pn;
}

bool Person::operator< (const Person& person) const
{
    if (_last_name == person._last_name) 
    {
        return _first_name < person._first_name;
    }
    return _last_name < person._last_name;
}