#pragma once
#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual double CalculateArea() const;

    virtual double CalculatePerimeter() const;

    virtual double CalculateVolume() const;
    
};

#endif


    virtual ~Shape() {}
};
