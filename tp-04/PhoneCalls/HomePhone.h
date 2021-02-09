#pragma once

#include "Phone.h"

#include <iostream>

class HomePhone: public Phone
{
    public:
        HomePhone (Person owner) 
            : Phone { owner }
        { }

        HomePhone (Person owner, int position) 
            : Phone { owner }, _position { position }
        { }

        void ring() const override {
            if (_owner.get_position() != _position) {
                std::cout << "This is the voicemail of " << _owner.getName() << " Please leave a message." << std::endl; 
            } else {
                _owner.answer_phone();
            }
        }
    
    private:
        int _position = 0;
};