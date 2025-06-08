#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "libshapes.h"

template <class T>
class Triangle : public Shape<T>, public modShape
{
private:
    // 3 sides are taken to calculate the perimeter
    // Tuple to store the three sides of the triangle
    std::tuple<std::shared_ptr<T>, std::shared_ptr<T>, std::shared_ptr<T>> sides;

public:
    Triangle(T S1, T S2, T S3)
    {
        sides = std::make_tuple(std::make_shared<T>(S1), std::make_shared<T>(S2), std::make_shared<T>(S3));
        modShape::count++;
    }
    T area() const override;
    T perimeter() const override;
    void display() const override;
};

template <class T>
T Triangle<T>::area() const
{
    T a = *(std::get<0>(sides));
    T b = *(std::get<1>(sides));
    T c = *(std::get<2>(sides));
    T s = (a + b + c) / 2; // Semi-perimeter
    T area_value = std::sqrt(s * (s - a) * (s - b) * (s - c));
    return area_value;
}

template <class T>
T Triangle<T>::perimeter() const
{
    auto perimeter_value = (*std::get<0>(sides)) + (*std::get<1>(sides)) + (*std::get<2>(sides));

    return perimeter_value;
}

template <typename T>
void Triangle<T>::display() const
{
    std::cout << "Triangle: sides = (" << *std::get<0>(sides) << ", " << *std::get<1>(sides) << ", " << *std::get<2>(sides) << ")"
              << ", area = " << area() << ", perimeter = " << perimeter() << std::endl;
}

#endif // TRIANGLE_H
