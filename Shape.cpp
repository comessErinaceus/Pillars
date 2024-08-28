#define _USE_MATH_DEFINES // Need this for constants, for some reason?
#include <iostream>
#include <cmath>

#include "Shape.h"
//Derived Circle
Circle::Circle(double r) : radius(r){}
//area
double Circle::area() const {
    return M_PI * radius * radius;
}
//perimeter
double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

//display
void Circle::display() const {
    std::cout << "Circle Radius = " << radius
        <<", Area = " << area()
        <<", Perimeter = " << perimeter()
        << std::endl;
}
// Derived Rectangle
//Constructor
Rectangle::Rectangle(double l, double w) : width(w), height(l){}
//Area
double Rectangle::area() const {
    return width * height;
}
//Perimeter
double Rectangle::perimeter() const {
    return (2*height) + (2*width);
}
//dispaly
void Rectangle::display() const {
    std::cout << "Rectangle Width X Height = " << width << " X " << height
    <<", Area = " << area()
    <<", Perimeter = " << perimeter()
    << std::endl;
}

//main(){}

//-------------------- What does this class accomplish --------------------
//Uses separate .h and .cpp implementation
//Abstract base class is in the .h, as it is not implementation by definition

// Advantage 1: Polymorphism 
//  allows for a base class to take multiple shapes
//Dynamic Binding: virtual functions allow the function being called to be
//  determined at runtime

/**Advantage 2
 *  Unified Interface
 * In this example Shape is a "unified interface"
 * 
 * Write code to work with shape and you write code that works
 * with its children automatically
 * 
 */

/**Advantage 3
 * Open/Closed Principle (OCP) - Extensibility
 *      Using virtual functions allows for the extention of capability later.
 * 
 * -Simpify define a new shape that implement existing mehtods, without
 *      modifying existing code.
 */

/**Advantage 4
 * Inheritance
 *      - Reuse code through Deriving child classes from parent classes
 *      - child classes can "override" parent methods, changing their
 *          functionality. (Also Polymorhpism)
 * 
 * Access modifiers:
 * public - members that can be accessed from anywhere the obj is visible
 * private - members can only be accessed from wihtin the class itself
 * protected - members can be accessed by derived classes
 * 
 */