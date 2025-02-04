#include "Point.h"
#include <iostream>

int main(void) {
    // Test cases
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);
    
    // Test points
    Point inside(2.0f, 2.0f);        // Inside the triangle
    Point outside(6.0f, 6.0f);       // Outside the triangle
    Point onEdge(2.0f, 0.0f);        // On an edge
    Point onVertex(0.0f, 0.0f);      // On a vertex
    
    std::cout << "Point inside triangle: " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    std::cout << "Point outside triangle: " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
    std::cout << "Point on edge: " << (bsp(a, b, c, onEdge) ? "true" : "false") << std::endl;
    std::cout << "Point on vertex: " << (bsp(a, b, c, onVertex) ? "true" : "false") << std::endl;
    
    return 0;
}