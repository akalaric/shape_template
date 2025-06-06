#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "libshapes.h"

template <class Sq>
class Square : public Shape<Sq>, public modShape
{
private:
    std::vector<std::shared_ptr<Sq>> sqr;

public:
    Square(Sq side)
    {
        sqr.push_back(std::make_shared<Sq>(side));
        modShape::count++;
    }
    Sq area() const override;
    Sq perimeter() const override;
    void display() const override;
};

template <class Sq>
Sq Square<Sq>::area() const
{
    Sq area_value;
    area_value = (*sqr[0]) * (*sqr[0]);
    return area_value;
}

template <class Sq>
Sq Square<Sq>::perimeter() const
{
    return 4 * (*sqr[0]);
}

template <class Sq>
void Square<Sq>::display() const
{
    std::cout << "Square: side = (" << *sqr[0] << ")" << ", area = " << area() << ", perimeter = " << perimeter() << std::endl;
}

#endif // SQUARE_H
