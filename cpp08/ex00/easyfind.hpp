#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>

class NotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found in the container.";
    }
};


template <typename T>
int easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return *it;
}

#endif