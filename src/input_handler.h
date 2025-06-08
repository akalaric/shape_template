#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <iostream>
#include <sstream>
#include <cassert>
#include <cassert>
#include "../include/libshapes.h"
#include "../include/include.h"

template <typename option>
void make_shape(std::shared_ptr<option> &input_shape)
{
    try
    {
        input_shape->display();
        std::cout << "Total Shapes created: " << modShape::getShapeCount() << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void process_input(const std::string &line)
{
    std::istringstream iss(line);
    std::string shape;
    iss >> shape;

    if (shape == "circle")
    {
        double r;
        if (iss >> r)
        {
            assert(r > 0);
            auto circle = std::make_shared<Circle<double>>(r);
            make_shape(circle);
        }
        else
        {
            std::cerr << "Usage: circle <radius>\n";
        }
    }
    else if (shape == "rectangle")
    {
        double l, b;
        if (iss >> l >> b)
        {
            assert(l > 0 && b > 0);
            auto rectangle = std::make_shared<Rectangle<double>>(l, b);
            make_shape(rectangle);
        }
        else
        {
            std::cerr << "Usage: rectangle <length> <breadth>\n";
        }
    }
    else if (shape == "square")
    {
        double s;
        if (iss >> s)
        {
            assert(s > 0);
            auto square = std::make_shared<Square<double>>(s);
            make_shape(square);
        }
        else
        {
            std::cerr << "Usage: square <side>\n";
        }
    }
    else if (shape == "sphere")
    {
        double r;
        if (iss >> r)
        {
             assert(r > 0);
            auto sphere = std::make_shared<Sphere<double>>(r);
            make_shape(sphere);
        }
        else
        {
            std::cerr << "Usage: sphere <radius>\n";
        }
    }
    else if (shape == "triangle")
    {
        double hypotenuse, adjacent, opposite;
        if (iss >> hypotenuse >> adjacent >> opposite)
        {
            assert(hypotenuse > 0 && adjacent > 0 && opposite > 0);
            auto triangle = std::make_shared<Triangle<double>>(hypotenuse, adjacent, opposite);
            make_shape(triangle);
        }
        else
        {
            std::cerr << "Usage: triangle <hypotenuse> <adjacent> <opposite>\n";
        }
    }
    else
    {
        std::cerr << "Usage: \n"
                  << "       circle <radius>\n"
                  << "       rectangle <length> <breadth>\n"
                  << "       square <side>\n"
                  << "       sphere <radius>\n"
                  << "       triangle <hypotenuse> <adjacent> <opposite>\n";
    }
}

#endif // INPUT_HANDLER_H