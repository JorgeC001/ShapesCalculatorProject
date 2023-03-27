//File: rectangle.cpp
//CLass: COP 3003 Fall 2022
//Dev: Jorge Cano
//Desc: Implementation for rectangle class object
//---------------------------------------------------------
#include "rectangle.h"

//Constructors
//---------------------------------------------------------
Rectangle::Rectangle() {
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    x3 = 0;
    y3 = 0;
    x4 = 0;
    y4 = 0;
    width = 0;
    length = 0;
}


//Accessors
//---------------------------------------------------------

//these getters for the points coverts the x and y values
//to strings and puts them in (x, y) format
std::string Rectangle::getPoint1() {
    std::string point1String;
    point1String = "(" + std::to_string(x1) + ", " +
            std::to_string(y1) + ")";

    return point1String;
}
void Rectangle::setPoint1(int x, int y) {
    x1 = x;
    y1 = y;
}


std::string Rectangle::getPoint2() {
    std::string point2String;
    point2String = "(" + std::to_string(x2) + ", " +
                   std::to_string(y2) + ")";

    return point2String;
}
void Rectangle::setPoint2(int x, int y) {
    x2 = x;
    y2 = y;
}


std::string Rectangle::getPoint3() {
    std::string point3String;
    point3String = "(" + std::to_string(x3) + ", " +
                   std::to_string(y3) + ")";

    return point3String;
}
void Rectangle::setPoint3(int x, int y) {
    x3 = x;
    y3 = y;
}


std::string Rectangle::getPoint4() {
    std::string point4String;
    point4String = "(" + std::to_string(x4) + ", " +
                   std::to_string(y4) + ")";

    return point4String;
}
void Rectangle::setPoint4(int x, int y) {
    x4 = x;
    y4 = y;
}

float Rectangle::getWidth() {
    return width;
}
void Rectangle::setWidth(float width) {
    this->width = width;
}

float Rectangle::getLength() {
    return length;
}
void Rectangle::setLength(float length) {
    this->length = length;
}


//Methods
//---------------------------------------------------------


/**
 * calculates the area of a rectangle
 * @return area gets returned
 */
float Rectangle::calcRectangleArea() {
    area = width * length;
    return area;
}


/**
 * calculates the perimeter of a rectangle
 * @return perimeter gets returned
 */
float Rectangle::calcRectanglePerimeter() {
    perimeter = (2 * width) + (2 * length);
    return perimeter;
}


/**
 * puts all the points of a rectangle into one string
 * @return string of all points in (x, y) form
 */
std::string Rectangle::combinePoints() {
    std::string combinedPoints = getPoint1() + " "
            + getPoint2() + " " + getPoint3() +
            " " + getPoint4();
    return combinedPoints;
}


/**
 * turns values of the rectangle into a string
 * @return string containing the values of rectangle
 */
std::string Rectangle::shapeToString(){
    std::string rectangleString;
    rectangleString = "Rectangle:\n\tWidth: " +
            std::to_string(width) + "\n\tLength:" +
            std::to_string(length) + "\n\tArea: " +
            std::to_string(area) + "\n\tPerimeter: " +
            std::to_string(perimeter) + "\n\tPoints: "
            + combinePoints();
    return rectangleString;
}

