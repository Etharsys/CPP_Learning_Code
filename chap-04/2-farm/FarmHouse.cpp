#include "Animal.h"
#include "Cat.h"
#include "Chicken.h"
#include "Cow.h"
#include "Dog.h"
#include "Opera.h"

#include <vector>

void sing_a_lot(const Animal& animal, unsigned int times)
{
    if (times > 0) {
        while (--times > 0)
        {
            animal.sing(' ');
        }
        animal.sing('\n');
    }
    

}

void sing_chrocus(const std::vector<Animal*>& farm) {
    for (const auto* animal : farm) 
    {
        animal->sing(' ');
    }

    std::cout << std::endl;
}

int main()
{
    Cat cat;
    Chicken chicken;
    Dog dog;
    Cow cow;

    sing_a_lot(cat, 2u);
    sing_a_lot(dog, 1u);
    sing_a_lot(cow, 3u);
    sing_a_lot(dog, 1u);
    sing_a_lot(chicken, 2u);

    std::vector<Animal*> farm;
    farm.emplace_back ( &cat );
    farm.emplace_back ( &dog );
    sing_chrocus (farm);

    Opera opera;
    opera.sing_chrocus();

    return 0;
}

