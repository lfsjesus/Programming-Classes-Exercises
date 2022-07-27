#ifndef POINT_H
#define POINT_H

class Point {
    public:
        Point();
        Point(int x, int y);
        float distance(const Point& point) const;
        void show() const;
    private:
        int x_, y_;
};
#endif