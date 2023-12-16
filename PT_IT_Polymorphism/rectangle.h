#ifndef RECTANGLE_HEADER
#define RECTANGLE_HEADER

#include "shape.h"

class Rectangle : public Shape {
public:
    Rectangle(const Point &lowerLeft, const Point &upperRight);

    double getArea() const override;

    void scale(double ratio) override;

    std::string getName() const override;

private:
    Point lowerLeft_;
    Point upperRight_;
};

#endif
