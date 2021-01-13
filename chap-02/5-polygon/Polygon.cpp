#include "Polygon.h"
#include "realloc.h"
#include <ostream>

using namespace std;


Polygon::~Polygon()
{
    delete[] _vertices;
}

void Polygon::add_vertex(int x, int y)
{
    const auto old_size = _size;
    ++_size;

    _vertices = realloc(_vertices, old_size, _size);
    _vertices[old_size] = Vertex { x, y };
}

ostream& operator<< (ostream& stream, const Polygon& poly)
{
    for (auto i = 0; i < poly._size; ++i)
    {
        auto vertice = poly._vertices[i];
        stream << "(" << vertice.first << "," << vertice.second << ") ";
    }
    return stream;
}

const Vertex& Polygon::get_vertex (size_t pos) const 
{ 
    return _vertices[pos]; 
}