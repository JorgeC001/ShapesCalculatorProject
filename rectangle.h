//File: rectangle.h
//CLass: COP 3003 Fall 2022
//Dev: Jorge Cano
//Desc: Declaration for the rectangle sub-class
//---------------------------------------------------------
#include <cmath>
#include "shape.h"

#ifndef SHAPESCALCULATOR_RECTANGLE_H
class Rectangle : public Shape{
private:
    float width;
    float length;
    float area;
    float perimeter;
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int x4, y4;
public:
    //Constructors
    //-----------------------------------------------------
    Rectangle();

    //Accessors
    //-----------------------------------------------------
    std::string getPoint1 ();
    void setPoint1 (int x, int y);

    std::string getPoint2 ();
    void setPoint2 (int x, int y);

    std::string getPoint3() ;
    void setPoint3 (int x, int y);

    std::string getPoint4 ();
    void setPoint4(int x, int y);

    float getWidth ();
    void setWidth (float width);

    float getLength ();
    void setLength (float length);

    //Methods
    //-----------------------------------------------------
    float calcRectangleArea ();
    float calcRectanglePerimeter ();
    std::string combinePoints();
    std::string shapeToString ();
};
#define SHAPESCALCULATOR_RECTANGLE_H

#endif //SHAPESCALCULATOR_RECTANGLE_H
