//File: line.cpp
//CLass: COP 3003 Fall 2022
//Dev: Jorge Cano
//Desc: Implementation for line class object
//---------------------------------------------------------
#include "line.h"
#include "shape.h"

//Constructors
//---------------------------------------------------------
Line::Line(){
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    slope = 0;
    angle = 0;
    distance = 0;
    intercept = 0;
}

Line::Line(int x1, int y1, int x2, int y2){
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}
//Accessors
//---------------------------------------------------------
int Line::getX1() {return x1;}
void Line::setX1(int x) {x1 = x;}

int Line::getY1() {return y1;}
void Line::setY1(int y) {y1 = y;}

int Line::getX2() {return x2;}
void Line::setX2(int x) {x2 = x;}

int Line::getY2() {return y2;}
void Line::setY2(int y) {y2 = y;}

//Methods
//---------------------------------------------------------


/**
 * adds the x and y point to the vector of class Point
 * @param x
 * @param y
 */
void Line::addToPointVector(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    points.push_back(p);
}


/**
 * calculates the slope of the line
 * @return slope of line
 */
float Line::calcLineSlope() {
    slope = (y2 - y1) / (x2 - x1);
    return slope;
}


/**
 * calculates the distance between the two points
 * @return distance between two points
 */
float Line::calcLineDistance() {
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;
}


/**
 * calculates the angle between the line and the x-axis
 * @return angle of the line
 */
float Line::calcLineAngle() {
    angle = atan2(y2 - y1, x2 - x1) * 180.0 / M_PI;
    return angle;
}


/**
 * calculates the y-intercept of the line
 * @param slope - uses slope of line
 * @return y-intercept of the line
 */
float Line::calcLineIntercept() {
    intercept = y1 - (slope * x1);
    return intercept;
}


/**
 * takes the points stored in the points vector and puts
 * them into a string
 * @return string containing points in (x, y) form
 */
std::string Line::pointsString() {
    std::string combinedPoints;
    for(auto c : points){
        combinedPoints += "(" + std::to_string(c.x) + ", " +
                std::to_string(c.y) + ") ";
    }
    return combinedPoints;
}

/**
 * puts all the attributes of the shape into a string
 * @return returns a string of the line's attributes
 */
std::string Line::shapeToString() {
    std::string lineString;
    lineString = "Line:\n\tPoints: " + pointsString()
            + "\n\tSlope: " + std::to_string(slope)
            + "\n\tDistance: " + std::to_string(distance)
            + "\n\tAngle: " + std::to_string(angle)
            + "\n\tIntercept: (0," + std::to_string(intercept) + ")";
    return lineString;
}




