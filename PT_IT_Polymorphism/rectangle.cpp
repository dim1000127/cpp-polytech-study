#include <stdexcept>
#include "rectangle.h"

Rectangle::Rectangle(const Point &lowerLeft, const Point &upperRight)
        : Shape({(lowerLeft.x + upperRight.x) / 2, (lowerLeft.y + upperRight.x) / 2}) {
    if (lowerLeft.x >= upperRight.x) {
        throw std::invalid_argument("Upper right point can't below the lower left point in x");
    }

    lowerLeft_ = lowerLeft;

    if (lowerLeft.y >= upperRight.y) {
        throw std::invalid_argument("Upper right point can't below the lower left point in y");
    }

    upperRight_ = upperRight;
}

double Rectangle::getArea() const {
    double x = upperRight_.x - lowerLeft_.x;
    double y = upperRight_.y - lowerLeft_.y;

    return x * y;
}

void Rectangle::scale(double ratio) {
    if (ratio <= 0){
        throw std::invalid_argument("Ratio can't be less 0");
    }


    upperRight_.x = center_.x + (upperRight_.x - center_.x) * ratio;
    upperRight_.y = center_.y + (upperRight_.y - center_.y) * ratio;
    lowerLeft_.x = center_.x + (lowerLeft_.x - center_.x) * ratio;
    lowerLeft_.y = center_.y + (lowerLeft_.y - center_.y) * ratio;
}

std::string Rectangle::getName() const {
    return "RECTANGLE";
}


