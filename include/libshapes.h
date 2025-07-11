#ifndef LIBSHAPES_H
#define LIBSHAPES_H

#include <memory>
#include <tuple>
#include <cmath>
#include <string>
#include <vector>

template <class S>
class Shape
{
public:
    virtual S area() const = 0;
    virtual S perimeter() const = 0;
    virtual S volume() const
    {
        return static_cast<S>(0); // Default behavior for 2D shapes
    }
    virtual void display() const = 0;
    virtual ~Shape() = default;
};

class modShape
{
private:
    static int count;

protected:
    double validateScaleFactor(double scaleFactor, std::string shape_name) const
    {
        if (scaleFactor < 0)
            return 1.0;

        else if (scaleFactor > 100)
        {
            std::cerr << "Shape: " + shape_name + "\n  High scaling factor: " + std::to_string(scaleFactor) << std::endl;    
            // throw std::invalid_argument("Shape: " + shape_name + "\n  High scaling factor: " + std::to_string(scaleFactor));
            return 1.0;
        }
        else
            return scaleFactor;
    }

public:
    static int getShapeCount() { return count; }
    template <class C>
    friend class Circle;
    template <class T>
    friend class Triangle;
    template <class R>
    friend class Rectangle;
    template <class Sq>
    friend class Square;
    template <class Sp>
    friend class Sphere;
    template <class cb>
    friend class Cube;
    virtual double scaleShape() const
    {
        return 1.0;
    }
};

int modShape::count = 0;

#endif // LIBSHAPES_H