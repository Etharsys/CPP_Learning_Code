#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person()
    {}

    Person(const string& name, const string& surname)
        : _name { name }, _surname { surname }
    {}
    
    std::string  get_full_name() const  { return _name + " " + _surname; }
    unsigned int get_age()       const  { return _age; }

    void         wait(unsigned int age) { _age += age; }

private:
    string _name;
    string _surname;   
    unsigned int _age = 0u;
};

int main()
{
    Person p { "Bruce", "Wayne" };
    Person test {};
    
    p.wait(23);

    std::cout << "Person named '" << p.get_full_name() << "' is " << p.get_age() << " years old." << std::endl;
    
    return 0;
}
