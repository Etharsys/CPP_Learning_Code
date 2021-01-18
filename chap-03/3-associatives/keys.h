#pragma once

#include <string>
#include <functional>

class ComparableDog
{
public:
    ComparableDog(const std::string& name, const std::string& species)
        : _name { name }, _species { species }
    {}

    bool operator< (const ComparableDog& dog) const
    {
        return _name < dog._name; //question : si je mets <= il ajoute le clone :/ why ?
    }

private:
    std::string _name;
    std::string _species;
};

class HashableDog
{
public:
    HashableDog(const std::string& name, const std::string& species)
        : _name { name }, _species { species }
    {}

    size_t get_hash() const
    {
        std::hash<std::string> hash_fnc;
        return hash_fnc(_name) ^ hash_fnc(_species);
    }

    bool operator== (const HashableDog& dog) const
    {
        return _name == dog._name && _species == dog._species;
    }

private:
    std::string _name;
    std::string _species;
};

namespace std {

template <>
struct hash<HashableDog>
{
    size_t operator()(const HashableDog& c) const
    {
        return c.get_hash();
    } 
};

}
