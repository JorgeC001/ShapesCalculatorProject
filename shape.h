//File: shape.h
//CLass: COP 3003 Fall 2022
//Dev: Jorge Cano
//Desc: Declaration for the shape base class
//---------------------------------------------------------
#include <vector>
#include <string>
#include "point.h"

//HEADER GUARD
#ifndef SHAPESCALCULATOR_SHAPE_H
#define SHAPESCALCULATOR_SHAPE_H


class Shape {
private:
    std::string shape;
protected:
    std::vector<Point> points{};
public:
    virtual std::string shapeToString();
};
#endif //SHAPESCALCULATOR_SHAPE_H
