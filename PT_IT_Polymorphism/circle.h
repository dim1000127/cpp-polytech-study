#ifndef CIRCLE_HEADER
#define CIRCLE_HEADER


#include "shape.h"

class Circle : public Shape{
public:
    Circle(const Point &center, const double radius);

    double getArea() const override;

    void scale(double ratio) override;

    std::string getName() const override;
private:
    double radius_;
};

#endif
