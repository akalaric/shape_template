#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include "libshapes.h"

namespace sphere_constants
{
    const auto pi = std::make_shared<double>(3.141592653589793);
    const auto val = std::make_shared<double>(1.33333);
}

template <class Sp>
class Sphere : public Shape<Sp>, public modShape
{
private:
    std::vector<std::shared_ptr<Sp>> radius;

public:
    Sphere(Sp rad)
    {
        radius.push_back(std::make_shared<Sp>(rad));
        modShape::count++;
    }
    Sp area() const override;
    Sp perimeter() const override;
    Sp Volume() const override;
    void display() const override;
};

template <class Sp>
Sp Sphere<Sp>::Volume() const 
{
    return (*sphere_constants::val) * (*sphere_constants::pi) * pow((*radius[0]), 3);
}

template <class Sp>
Sp Sphere<Sp>::area() const
{
    return 4 * (*sphere_constants::pi) * pow((*radius[0]), 2);
}

template <class Sp>
Sp Sphere<Sp>::perimeter() const
{
    return 2 * (*sphere_constants::pi) * (*radius[0]);
}
template <class Sp>
void Sphere<Sp>::display() const
{
    std::cout << "Sphere: radius = (" << *radius[0] << ")" << ", area = " << area() << ", perimeter = " << perimeter() << ", Volume = " << Volume()  << std::endl;
}

#endif // SPHERE_H
