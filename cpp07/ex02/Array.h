#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{  
    private:
        T *_elements;
        unsigned int _size;

    public:
        Array() : _elements(new T[0]), _size(0) {}
        Array(unsigned int n) : _elements(new T[n]()), _size(n) {}
        Array(const Array &other) : _elements(new T[other._size]()), _size(other._size)
        {
            for (unsigned int i = 0; i < _size; i++)
                _elements[i] = other._elements[i];
        }
        Array &operator=(const Array &other)
        {
            if (this != &other)
            {
                delete[] _elements;
                _size = other._size;
                _elements = new T[_size]();
                for (unsigned int i = 0; i < _size; i++)
                    _elements[i] = other._elements[i];
            }
            return *this;
        }
        T &operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return _elements[index];
        }

        unsigned int size() const { return _size; }

        ~Array() { delete[] _elements; }
};

#endif



