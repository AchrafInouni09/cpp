#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int maxSize) : _maxSize(maxSize) {}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::overflow_error("Cannot add more numbers, Span is full.");
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        shortest = std::min(shortest, sorted[i] - sorted[i - 1]);
    }
    return shortest;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}