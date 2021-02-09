#pragma once

#include "Phone.h"

#include <iostream>

class MobilePhone: public Phone 
{
    public:
            MobilePhone (Person owner) 
                : Phone { owner }
            { }
};