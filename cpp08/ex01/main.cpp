#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        std::vector<int> range ;
        for (int i = 1; i <= 3; ++i)
            range.push_back(i);
        Span sp2(10);
        sp2.addRange(range.begin(), range.end());
        sp2.addNumber(10);
        std::cout << "Shortest Span in sp2: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span in sp2: " << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}