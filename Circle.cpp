#include "Circle.h"
#include <cmath>
#include <iostream>
using namespace std;

Circle::Circle() : Shape(), center(Point2D()), radius(0) {}

Circle::Circle(string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}

Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    if (r >= 0) {
        radius = r;
    } else {
        cerr << "Radius cannot be negative." << endl;
    }
}

ostream& operator<<(ostream &out, const Circle &c) {
    out << "Circle[color=" << c.color 
        << ", center=(" << c.center.x << ", " << c.center.y << ")"
        << ", radius=" << c.radius << "]";
    return out;
}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() {
    cout << *this << endl;
}

