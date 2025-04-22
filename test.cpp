#include <iostream>
#include <cmath>

using namespace std;


class Fixed
{
    private :

        int _value;
        static const int _fractionalBits = 8;

    public :

    Fixed () : _value(0) {}


    Fixed &operator=(const Fixed&other )
    {
        _value = other._value;
        return (*this);
    }

    Fixed (const int nb){
        this->_value = nb << _fractionalBits;
    }

    Fixed (const float nb)
    {
        this->_value = round (nb * (1 << _fractionalBits));
    }

    int to_int() const
    {
        return (this->_value >> _fractionalBits);
    }

    float to_float() const
    {
        return (static_cast<float>(this->_value )/ (1 << _fractionalBits));
    }

    bool operator>(const Fixed &other) const
    {
        return  (_value > other._value);
    }

    bool operator<(const Fixed &other) const
    {
        return  (_value < other._value);
    }

    bool operator>=(const Fixed &other) const
    {
        return  (_value >= other._value);
    }

    bool operator<=(const Fixed &other) const
    {
        return  (_value <= other._value);
    }

    bool operator==(const Fixed &other) const
    {
        return  (_value == other._value);
    }

    bool operator!=(const Fixed &other) const
    {
        return  (_value != other._value);
    }
    Fixed &operator++()
    {
        _value++;
        return (*this);
    }

    Fixed operator++(int)
    {
        Fixed tmp(*this);
        _value++;
        return (tmp);
    }

    Fixed &operator--()
    {
        _value--;
        return (*this);
    }
    Fixed operator--(int)
    {
        Fixed tmp(*this);
        _value--;
        return (tmp); 
    }

    void    setraws(const int raws)
    {
        _value = raws;
    }

    Fixed operator+(const Fixed other) const
    {
        Fixed result;
        result.setraws(_value + other._value);
        return (result);
    }

    Fixed operator-(const Fixed other) const
    {
        Fixed result;
        result.setraws(_value - other._value);
        return (result);
    }

    Fixed operator*(const Fixed other) const
    {
        Fixed result;
        result._value =  (_value * other._value) >> _fractionalBits;
        return (result);
    }

    Fixed operator/(const Fixed other) const
    {
        if (other._value == 0)
            {
                // cout << "we cannot divide by 0\n";
                throw runtime_error("we cannot divide by 0");
            }

        Fixed result;

        result.setraws((_value << _fractionalBits) / other._value );
        return (result);
    }



    // >, <, >=, <=, == and !=.
};

ostream &operator<<(ostream &out, const Fixed &fixed)
{
    out << fixed.to_float();
    return (out);
}


int main(void)
{
    // Fixed a;

    Fixed b(42);
    Fixed c(0);

    Fixed d = b / c;

    // Fixed const b(Fixed(5.05f) * Fixed(2));

    // cout << b;


    


    // Fixed d = b * c;

    // cout << d << endl;


    // cout << (1 << 8);

    



    return (0);
}