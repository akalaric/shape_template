#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "libshapes.h"
namespace circle_constants
{
    constexpr double pi = 3.141592653589793;
}
template <class C>
class Circle : public Shape<C>, public modShape
{
private:
    std::string shape_name = "Circle";
    std::shared_ptr<C> radius;
    C scaleFactor, effectiveRadius;

public:
    Circle(C rad, C scale = 1) : scaleFactor(scale)
    {
        radius = std::make_shared<C>(rad);
        modShape::count++;

        effectiveRadius = (scaleFactor > 1) ? scaleShape() : *radius;
    }
    double scaleShape() const override
    {
        double effectiveScaleFactor = validateScaleFactor(scaleFactor, shape_name);
        return (*radius) * effectiveScaleFactor;
    }
    C area() const override
    {
        return circle_constants::pi * (effectiveRadius * effectiveRadius);
    }
    C perimeter() const override
    {
        auto perimeter_value = (2 * circle_constants::pi * effectiveRadius);
        return perimeter_value;
    }
    void display() const override;
};

template <class C>
void Circle<C>::display() const
{
    if (scaleFactor == 1)
    {
        std::cout << "Circle: radius = " << *radius
                  << ", area = " << area()
                  << ", perimeter = " << perimeter() << std::endl;
    }
    else
    {
        std::cout << "Circle: scaled radius = " << effectiveRadius
                  << ", scaled area = " << area()
                  << ", scaled perimeter = " << perimeter() << std::endl;
    }
}

#endif // CIRCLE_H