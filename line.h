//File: line.h
//CLass: COP 3003 Fall 2022
//Dev: Jorge Cano
//Desc: Declaration for the line sub-class
//---------------------------------------------------------
#include <cmath>
#include <vector>
#include "shape.h"

#ifndef SHAPESCALCULATOR_LINE_H
class Line : public Shape{
private:
    int x1, y1, x2, y2;
    float slope;
    float distance;
    float angle;
    float intercept;

public:
    //Constructors
    //-----------------------------------------------------
    Line();
    Line(int x1, int y1, int x2, int y2);

    //Accessors
    //-----------------------------------------------------
    int getX1();
    void setX1(int x);

    int getY1();
    void setY1(int y);

    int getX2();
    void setX2(int x);

    int getY2();
    void setY2(int y);

    //Methods
    //-----------------------------------------------------
    void addToPointVector(int x, int y);
    float calcLineSlope ();
    float calcLineDistance ();
    float calcLineAngle ();
    float calcLineIntercept ();
    std::string pointsString();
    std::string shapeToString ();

};
#define SHAPESCALCULATOR_LINE_H

#endif //SHAPESCALCULATOR_LINE_H
