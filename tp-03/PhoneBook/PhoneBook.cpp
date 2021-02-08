#include "PhoneBook.h"

#include <algorithm>

using namespace std;

void PhoneBook::insert(const Person& person)
{
    _phone_book.insert(person);
}

bool PhoneBook::empty()
{
    return _phone_book.empty();
}

Person& PhoneBook::first_of_familly(const string& familly)
{
    for (auto person : _phone_book) {
        if (person.get_first_name() == familly){
            return person;
        }
    }
    return nullptr;
}

Person PhoneBook::operator[](int index)
{
    auto iter = _phone_book.find(index);
    return _phone_book[index];
}