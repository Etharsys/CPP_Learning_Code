#pragma once

#include "Car.h"

class FlyingCar : public Car 
{
    public:
        FlyingCar (const Driver& driver, unsigned int speed)
            : Car { driver, speed }
            , _flying_speed { 10u * speed }
        { }

        unsigned int FlyingCar::drive() const override
        {
            if ( !_driver.has_flying_licence() ) {
                std::cout << "Not vrooming in the air :( " << std::endl;
                return Car::drive();
            }
            std::cout << "Vrooooom to the future ..................... !" << std::endl;
            return _flying_speed;
        }

    private:
        unsigned int _flying_speed = 0;
};