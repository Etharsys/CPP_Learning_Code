#include <iostream>

#include "Polygon.h"

int main()
{
    Polygon polygon;

    polygon.add_vertex(2, 3);
    polygon.add_vertex(4, 5);
    polygon.add_vertex(6, 7);
    std::cout << polygon << std::endl;

    auto vertex = polygon.get_vertex(1); //Vertex inmodifiable :/
    std::cout << "(" << vertex.first << "," << vertex.second << ")" << std::endl; // -> (4,5)

    polygon.add_vertex(8, 9); //-var-create: unable to create variable object
    
    std::cout << vertex.first << " " << vertex.second << std::endl; // -> ???

    return 0;
}
