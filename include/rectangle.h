#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "libshapes.h"

template <class R>
class Rectangle : public Shape<R>, public modShape
{
private:
    std::pair<std::shared_ptr<R>, std::shared_ptr<R>> rect;

public:
    Rectangle(R len, R wid)
    {
        rect = std::make_pair(std::make_shared<R>(len), std::make_shared<R>(wid));
        modShape::count++;
    }
    R area() const override;
    R perimeter() const override;
    void display() const override;
};

template <class R>
R Rectangle<R>::area() const
{
    R area_value = (*rect.first) * (*rect.second);
    return area_value;
}

template <class R>
R Rectangle<R>::perimeter() const
{
    R perimeter_value = 2 * ((*rect.first) + (*rect.second));
    return perimeter_value;
}

template <class R>
void Rectangle<R>::display() const
{
    std::cout << "Rectangle: sides = (" << *rect.first << ", " << *rect.second << ")" << ", area = " << area() << ", perimeter = " << perimeter() << std::endl;
}

#endif // RECTANGLE_H
