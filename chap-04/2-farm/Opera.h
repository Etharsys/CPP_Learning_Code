#pragma once

#include "Cat.h"
#include "Chicken.h"
#include "Cow.h"
#include "Dog.h"
#include "Animal.h"

#include <iostream>
#include <vector>

class Opera
{
    public:
        Opera () 
        { 
            _animals.emplace_back(new Cat {});
            _animals.emplace_back(new Chicken {});
            _animals.emplace_back(new Cow {});
            _animals.emplace_back(new Dog {});
        }

        virtual ~Opera () 
        {
            for (auto* animal : _animals)
            {
                delete animal;
            }
        }

        void sing_chrocus() const {
            for (const auto* animal : _animals) 
            {
                animal->sing(' ');
            }

            std::cout << std::endl;
        }

    private:
        std::vector<Animal*> _animals;
};
