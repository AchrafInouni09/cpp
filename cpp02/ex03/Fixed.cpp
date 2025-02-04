#include "Fixed.h"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int n) : value(n << fractionalBits) {}

Fixed::Fixed(const float n) : value(roundf(n * (1 << fractionalBits))) {}

Fixed::Fixed(const Fixed& other) : value(other.value) {}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
    value = other.value;
    return *this;
}

bool Fixed::operator>(const Fixed& other) const { return value > other.value; }
bool Fixed::operator<(const Fixed& other) const { return value < other.value; }
bool Fixed::operator>=(const Fixed& other) const { return value >= other.value; }
bool Fixed::operator<=(const Fixed& other) const { return value <= other.value; }
bool Fixed::operator==(const Fixed& other) const { return value == other.value; }
bool Fixed::operator!=(const Fixed& other) const { return value != other.value; }

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(value + other.value);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(value - other.value);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.setRawBits((value * other.value) >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.value == 0)
        throw std::runtime_error("Division by zero");
    Fixed result;
    result.setRawBits((value << fractionalBits) / other.value);
    return result;
}

Fixed& Fixed::operator++() {
    ++value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++value;
    return temp;
}

Fixed& Fixed::operator--() {
    --value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --value;
    return temp;
}

int Fixed::getRawBits(void) const {
    return value;
}

void Fixed::setRawBits(int const raw) {
    value = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return value >> fractionalBits;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}