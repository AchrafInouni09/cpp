#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
private:
    int _nbValue; // Raw fixed-point value
    static const int _fractionalBits = 8;

public:
    Fixed();                        // Default constructor
    Fixed(const int value);         // Constructor with integer parameter
    Fixed(const float value);       // Constructor with float parameter
    Fixed(const Fixed &other);      // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment operator
    ~Fixed();                       // Destructor

    int  getRawBits(void) const;    // Get the raw fixed-point value
    void setRawBits(int const raw); // Set the raw fixed-point value

    // float toFloat(void) const;      // Convert to float
    // int toInt(void) const;          // Convert to int
};

// Overload the insertion operator

#endif