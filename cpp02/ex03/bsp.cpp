#include "Point.h"

// Calculate area of triangle using cross product
static Fixed area(Point const &a, Point const &b, Point const &c) {
    Fixed area = ((b.getX() - a.getX()) * (c.getY() - a.getY()) - 
                  (c.getX() - a.getX()) * (b.getY() - a.getY())) / 2;
    return area < 0 ? area * -1 : area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate area of the main triangle
    Fixed abcArea = area(a, b, c);
    
    // Calculate areas of three triangles formed by the point and two vertices
    Fixed pabArea = area(point, a, b);
    Fixed pbcArea = area(point, b, c);
    Fixed pcaArea = area(point, c, a);
    
    // Check if point is on any edge or vertex (areas would be 0)
    if (pabArea == 0 || pbcArea == 0 || pcaArea == 0)
        return false;
    
    // Point is inside if sum of three areas equals the main triangle area
    Fixed sumAreas = pabArea + pbcArea + pcaArea;
    
    return sumAreas == abcArea;
}