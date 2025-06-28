#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include "libshapes.h"

template <class cb>
class Cube : public Shape<cb>, public modShape
{
private:
    std::shared_ptr<cb> cbe[1];
    std::string shape_name = typeid(*this).name();
    cb scaleFactor, effectiveSide;

public:
    Cube(cb side, cb scale = 1) : scaleFactor(scale)
    {
        cbe[0] = std::make_shared<cb>(side);
        modShape::count++;

        effectiveSide = (scaleFactor > 1) ? scaleShape() : *cbe[0];
    }

    double scaleShape() const override
    {
        double effectiveScaleFactor = validateScaleFactor(scaleFactor, shape_name);
        return (*cbe[0]) * effectiveScaleFactor;
    }

    cb area() const override
    {
        return 6 * pow(effectiveSide, 2);
    }

    cb perimeter() const override
    {
        return 12 * effectiveSide;
    }
    cb volume() const override
    {
        return pow(effectiveSide, 3);
    }
    void display() const override;
};


template <class cb>
void Cube<cb>::display() const
{
    if (scaleFactor == 1)
    {
        std::cout << "Cube: side = " << *cbe[0]
                  << ", area = " << area()
                  << ", perimeter = " << perimeter()
                  << ", volume = " << volume() 
                  << std::endl;
    }
    else
    {
        std::cout << "Cube: scaled side = " << effectiveSide
                  << ", scaled area = " << area()
                  << ", scaled perimeter = " << perimeter() 
                  << ", scaled volume = " << volume() 
                  << std::endl;
    }
}

#endif // CUBE_H