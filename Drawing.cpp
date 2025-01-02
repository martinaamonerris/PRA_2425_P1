#include "Drawing.h"
#include "Shape.h"
#include "ListArray.h"
#include <iostream>
#include <typeinfo>
#include <cmath>
using namespace std;

Drawing::Drawing() {
    shapes = new ListArray<Shape*>();
}

Drawing::~Drawing() {
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->insert(0, shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* shape = shapes->get(i);
        cout << "Figura " << i + 1 << ": ";
        shape->print();
    }
}

double Drawing::get_area_all_circles() {
    double totalArea = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* shape = shapes->get(i);
        if (typeid(*shape) == typeid(Circle)) {
            Circle* circle = dynamic_cast<Circle*>(shape);
            totalArea += circle->area();
        }
    }
    return totalArea;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* shape = shapes->get(i);
        if (typeid(*shape) == typeid(Square)) {
            Square* square = dynamic_cast<Square*>(shape);
            square->translate(incX, incY);
        }
    }
}

