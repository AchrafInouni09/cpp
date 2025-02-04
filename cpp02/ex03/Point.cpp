#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point() {}

Point& Point::operator=(const Point& other) {
    // Since x and y are const, we can't modify them
    // This is just to satisfy Orthodox Canonical Form
    (void)other;
    return *this;
}

Fixed Point::getX() const {
    return x;
}

Fixed Point::getY() const {
    return y;
}