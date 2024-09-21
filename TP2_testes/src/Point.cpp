#include "../include/Point.hpp"
#include  <cmath>

long double Point::getX(){
    return this->x;
}

long double Point::getY(){
    return this->y;
}

long double Point::distanceTo(Point p){
    long double dx = std::abs(p.getX() - this->getX());
    long double dy = std::abs(p.getY() - this->getY());
    return std::sqrt(dx*dx + dy*dy);
}

long long Point::distanceToSqrt(Point p){
    long double dx = std::abs(p.getX() - this->getX());
    long double dy = std::abs(p.getY() - this->getY());
    return dx*dx + dy*dy;
} 