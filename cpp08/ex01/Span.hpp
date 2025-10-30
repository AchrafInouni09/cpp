#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int maxSize);
    ~Span();

    void addNumber(int number);

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        if (std::distance(begin, end) + _numbers.size() > _maxSize) {
            throw std::overflow_error("Adding this range exceeds the maximum size of the Span.");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;
};

#endif