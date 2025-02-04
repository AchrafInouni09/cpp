#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {
private:
    const Fixed x;
    const Fixed y;

public:
    Point();                                    // Default constructor
    Point(const float x, const float y);        // Float constructor
    Point(const Point& other);                  // Copy constructor
    ~Point();                                   // Destructor

    Point& operator=(const Point& other);       // Assignment operator

    // Getters
    Fixed getX() const;
    Fixed getY() const;
};

// BSP function declaration
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif