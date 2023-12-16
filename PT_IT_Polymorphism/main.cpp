#include <iostream>
#include "rectangle.h"
#include "point.h"
#include "circle.h"

void printShapeInfo(const Shape *shape) {
    std::cout << std::endl;
    std::cout << shape->getName() << std::endl;
    std::cout << " Center:\n X - " << shape->getCenter().x << "\n Y - " << shape->getCenter().y << std::endl;
    std::cout << " Area - " << shape->getArea() << std::endl;
}

void sort(Shape **shapes, int length) {
    Shape *temp = nullptr;

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - 1; ++j) {
            if (*shapes[j + 1] < *shapes[j]) {
                temp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = temp;
            }
        }
    }
}

int main() {

    const int SHAPE_COUNT = 5;
    Shape *shapes[SHAPE_COUNT]{nullptr};

    try {
        Point lowerLeft1{0, 0};
        Point upperRight1{5, 5};
        Point center1{0, 0};

        shapes[0] = new Rectangle(lowerLeft1, upperRight1);
        shapes[1] = new Circle(center1, 5);

        Point lowerLeft2{-1, 2};
        Point upperRight2{2, 7};
        Point center2{-1, -1};

        shapes[2] = new Circle(center2, 2);
        shapes[3] = new Rectangle(lowerLeft2, upperRight2);

        Point center3{-4, 5};
        shapes[4] = new Circle(center3, 4);

        bool eq = shapes[1]->operator<(*shapes[2]);
        std::cout << eq << std::endl;

        std::cout << "Before" << std::endl;
        for (auto &shape: shapes)
            printShapeInfo(shape);

        for (auto &shape: shapes)
            shape->scale(2);

        std::cout << "After scale" << std::endl;

        for (auto &shape: shapes)
            printShapeInfo(shape);

        sort(shapes, SHAPE_COUNT);
        std::cout << "After" << std::endl;

        for (auto &shape: shapes)
            printShapeInfo(shape);

    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    for (auto &shape: shapes)
        delete shape;

    return 0;
}
