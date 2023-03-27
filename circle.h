//File: circle.h
//CLass: COP 3003 Fall 2022
//Dev: Jorge Cano
//Desc: Declaration for the circle sub-class
//---------------------------------------------------------
#include <cmath>
#include "shape.h"

#ifndef SHAPESCALCULATOR_CIRCLE_H
class Circle : public Shape{
private:
    int x;
    int y;
    int radius;
    float area;
    float circumference;
    float diameter;
public:
    //Constructors
    //-----------------------------------------------------
    Circle();

    //Accessors
    //-----------------------------------------------------
    int getX ();
    void setX (int x);

    int getY ();
    void setY (int y);

    int getRadius ();
    void setRadius (int radius);

    //Methods
    //-----------------------------------------------------
    float calcCircleArea();
    float calcCircleCircumference();
    float calcCircleDiameter();
    std::string shapeToString();
};
#define SHAPESCALCULATOR_CIRCLE_H

#endif //SHAPESCALCULATOR_CIRCLE_H
