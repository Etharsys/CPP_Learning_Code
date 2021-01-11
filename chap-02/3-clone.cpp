#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(const std::string& name, const std::string& surname)
        : _name { name }, _surname { surname }
    {}
    Person(const Person& original)
        : _name { original._name }, _surname { original._surname }
    {}

    Person& operator=(const Person& original)
    {
        if (this != &original)
        {
            _name = original._name;
            _surname = original._surname;
        }
        return *this;
    } 

    std::string  get_full_name() const { return _name + " " + _surname; }
    unsigned int get_age() const  { return _age; }

    void wait(unsigned int years) { _age += years; }

private:
    std::string  _name;
    std::string  _surname;
    unsigned int _age = 0u;
};

ostream& operator<< (ostream& stream, const Person& person)
{
    return stream << "Person named '" << person.get_full_name() << "' is " << person.get_age() << " years old.";
}

int main()
{
    Person batman { "Bruce", "Wayne" };
    batman.wait(23);

    std::cout << batman << std::endl;

    auto batman_le_retour = batman;
    std::cout << batman_le_retour << std::endl;

    Person assigned_clone { "Batman", "2" };
    cout << assigned_clone << endl;

    assigned_clone = batman;
    cout << assigned_clone << endl;

    return 0;
}
