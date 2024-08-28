#ifndef SHAPE_H
#define SHAPE_H


// Abstract base class: Shape
class Shape {
public:
    // Pure virtual functions providing the interface for derived classes
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;

    // Virtual destructor to ensure proper cleanup of derived shapes
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor
    Circle(double r);

    // Implementations will be provided in the .cpp file
    double area() const override;
    double perimeter() const override;
    void display() const override;
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Constructor
    Rectangle(double w, double h);

    // Implementations will be provided in the .cpp file
    double area() const override;
    double perimeter() const override;
    void display() const override;
};

#endif // SHAPE_H