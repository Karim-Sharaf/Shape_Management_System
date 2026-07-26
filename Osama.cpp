#include <iostream>
#include <cmath>
using namespace std;


double PI = 3.14159;


// Circle
class Circle {
    double radius;
public:
    void input() {
        cout << "Enter radius of circle: ";
        cin >> radius;
    }

    double area() {
        return PI * radius * radius;
    }

    void display() {
        cout << "Circle Area = " << area() << endl;
    }
};

// Rectangle
class Rectangle {
    double length, width;
public:
    void input() {
        cout << "Enter length and width of rectangle: ";
        cin >> length >> width;
    }

    double area() {
        return length * width;
    }

    void display() {
        cout << "Rectangle Area = " << area() << endl;
    }
};

// Square
class Square {
    double side;
public:
    void input() {
        cout << "Enter side of square: ";
        cin >> side;
    }

    double area() {
        return side * side;
    }

    void display() {
        cout << "Square Area = " << area() << endl;
    }
};

// Triangle
class Triangle {
    double base, height;
public:
    void input() {
        cout << "Enter base and height of triangle: ";
        cin >> base >> height;
    }

    double area() {
        return 0.5 * base * height;
    }

    void display() {
        cout << "Triangle Area = " << area() << endl;
    }
};

// Cuboid
class Cuboid {
    double length, width, height;
public:
    void input() {
        cout << "Enter length, width and height of cuboid: ";
        cin >> length >> width >> height;
    }

    double area() {
        return 2 * (length * width + width * height + height * length);
    }

    double volume() {
        return length * width * height;
    }

    void display() {
        cout << "Cuboid Surface Area = " << area() << endl;
        cout << "Cuboid Volume = " << volume() << endl;
    }
};

// Pyramid
class Pyramid {
    double baseLength, height;
public:
    void input() {
        cout << "Enter base length and height of pyramid: ";
        cin >> baseLength >> height;
    }

    double area() {
        double baseArea = baseLength * baseLength;
        double slantHeight = sqrt((baseLength / 2) * (baseLength / 2) + height * height);
        double lateralArea = 2 * baseLength * slantHeight;
        return baseArea + lateralArea;
    }

    double volume() {
        return (1.0 / 3.0) * baseLength * baseLength * height;
    }

    void display() {
        cout << "Pyramid Surface Area = " << area() << endl;
        cout << "Pyramid Volume = " << volume() << endl;
    }
};
