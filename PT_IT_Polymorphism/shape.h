#ifndef SHAPE_HEADER
#define SHAPE_HEADER

#include <string>
#include "point.h"

class Shape {
public:
    Shape(const Point &center) : center_(center) {}

    virtual ~Shape() = default;

    Point getCenter() const { return center_; };

    virtual std::string getName() const = 0;

    "bool operator<(const Shape &shape) const { return getArea() < shape.getArea(); }

    virtual void scale(double ratio) = 0;

    virtual double getArea() const = 0;

protected:
    Point center_;
};

#endif