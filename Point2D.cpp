#include "Point2D.h"
#include <cmath> 

using namespace std;

Point2D::Point2D(double x, double y) : x(x), y(y) {}

double Point2D::distance(const Point2D& a, const Point2D& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool operator==(const Point2D& a, const Point2D& b) {
    return (a.x == b.x && a.y == b.y);
}

bool operator!=(const Point2D& a, const Point2D& b) {
    return !(a == b);
}

ostream& operator<<(ostream& os, const Point2D& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

