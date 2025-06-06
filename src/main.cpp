#include <iostream>
#include "../include/libshapes.h"
#include "../include/include.h"

int main()
{
    std::vector<std::unique_ptr<Shape<double>>> shapes;
    try
    {
        shapes.push_back(std::make_unique<Circle<double>>(4, 500));
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try
    {
        shapes.push_back(std::make_unique<Circle<double>>(4, 5));
        shapes.push_back(std::make_unique<Rectangle<double>>(4.5, 8.5));
        shapes.push_back(std::make_unique<Square<double>>(5.0));
        shapes.push_back(std::make_unique<Sphere<double>>(6.2));
        shapes.push_back(std::make_unique<Circle<double>>(5.5, 5));
        shapes.push_back(std::make_unique<Circle<double>>(4));
        shapes.push_back(std::make_unique<Circle<double>>(2, 35));
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    for (std::size_t i = 0; i < shapes.size(); i++)
    {
        shapes[i]->display();
    }

    std::cout << "Total Shapes created: " << modShape::getShapeCount() << std::endl;
}
