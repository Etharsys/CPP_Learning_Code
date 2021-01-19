#include "Histogram.h"
#include <cstring>

Histogram::Histogram()
    : _count { new unsigned[26] }
{
    std::cout << "Histogram constructed" << std::endl; 
}


Histogram::Histogram(const Histogram& old)
    : _count { new unsigned[26] }
{
    for (auto i = 0; i < 26; ++i)
    {
        _count[i] = old._count[i];
    }
    std::cout << "Histogram copied" << std::endl; 
}


Histogram::~Histogram()
{
    std::cout << "Histogram deleted" << std::endl; 
    delete[] _count;
}

Histogram& Histogram::operator=(const Histogram& old)
{
    if (this != &old) {
        std::memcpy (this->_count, old._count, 26);
    }
    return *this;
}

void Histogram::analyze(const std::string& entry)
{
    for (auto c : entry)
    {
        _count[c - 'a'] += 1;
    }
}

void Histogram::print() const
{
    for (auto i = 0; i < 26; ++i)
    {
        std::cout << _count[i] << " ";
    }
}