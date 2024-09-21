#ifndef POINT_H
#define POINT_H

class Point{
    public:
        long double getX();
        long double getY();
        long double distanceTo(Point p);
        long long distanceToSqrt(Point p);
        Point(long double x, long double y) : x(x), y(y) {}
    private:    
        long double x;
        long double y;
};

#endif