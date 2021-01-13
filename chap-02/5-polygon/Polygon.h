#pragma once

#include <utility>
#include <cstdio>
#include <ostream>

using Vertex = std::pair<int, int>;

class Polygon
{
    friend std::ostream& operator<< (std::ostream& stream, const Polygon& poly);

    public:
        ~Polygon ();

        void add_vertex(int x, int y);

        const Vertex& get_vertex (size_t pos) const;

    private:
        size_t  _size     = 0u;
        Vertex* _vertices = nullptr;
};