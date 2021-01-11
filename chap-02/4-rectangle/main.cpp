#include "Rectangle.h"

#include <iostream>

using namespace std;

int main()
{
    Rectangle rect(2.f, 4.f);
    std::cout << "{ L: " << rect.get_length() << ", W: " << rect.get_width() << " }" << std::endl;

    rect.scale(3);
    std::cout << "{ L: " << rect.get_length() << ", W: " << rect.get_width() << " }" << std::endl;

    Rectangle square(2.5);
    std::cout << "{ L: " << square.get_length() << ", W: " << square.get_width() << " }" << std::endl;

    Rectangle::set_default_size(3.f);
    Rectangle s1;
    Rectangle s2;

    Rectangle::set_default_size(5.f);
    Rectangle s3;
    Rectangle s4;
    Rectangle s5;

    // At this point, size of s1 and s2 should be 3.f, and size fo s3, s4 and s5 should be 5.f. 

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;

    return 0;
}
