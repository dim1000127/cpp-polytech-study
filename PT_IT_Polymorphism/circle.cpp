#include <stdexcept>
#include <cmath>
#include "circle.h"

Circle::Circle(const Point &center, const double radius) : Shape(center) {
    if (radius <= 0){
        throw std::invalid_argument("Radius can't be less 0");
    }

    radius_ = radius;
}

double Circle::getArea() const {
    return M_PI * pow(radius_, 2);
}

void Circle::scale(double ratio) {
    if (ratio <= 0){
        throw std::invalid_argument("Ratio can't be less 0");
    }

    radius_ = radius_ * ratio;
}

std::string Circle::getName() const {
    return "CIRCLE";
}
