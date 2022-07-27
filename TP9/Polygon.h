#include <vector>
#ifndef POLYGON_H
#define POLYGON_H

class Polygon {
    public:
        Polygon();
        Polygon(std::vector<Point> v);
        void show() const;
        bool get_vertex(size_t position, Point& p);
        void add_vertex(int position, Point p);
        float perimeter() const;

    private:
        std::vector<Point> v_;
};
#endif