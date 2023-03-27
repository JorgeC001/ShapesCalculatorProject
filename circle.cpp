//File: circle.cpp
//CLass: COP 3003 Fall 2022
//Dev: Jorge Cano
//Desc: Implementation for circle class object
//---------------------------------------------------------
#include "circle.h"
#include "shape.h"

//Constructors
//---------------------------------------------------------
Circle::Circle() {
    x = 0;
    y = 0;
    radius = 0;
    area = 0;
    circumference = 0;
    diameter = 0;
}

//Accessors
//---------------------------------------------------------
int Circle::getX() {
    return x;
}
void Circle::setX(int x) {
    this->x = x;
}


int Circle::getY() {
    return y;
}
void Circle::setY(int y) {
    this->y = y;
}


int Circle::getRadius() {
    return radius;
}
void Circle::setRadius(int radius) {
    this->radius = radius;
}

//Methods
//---------------------------------------------------------


/**
 * calculates the area of the circle using the radius
 * @return area of circle
 */
float Circle::calcCircleArea() {
    area = M_PI * pow(radius, 2);
    return area;
}


/**
 * calculates the circumference of the circle
 * @return circumference of circle
 */
float Circle::calcCircleCircumference() {
    circumference = 2 * M_PI * radius;
    return circumference;
}


/**
 * calculates the diameter of the circle
 * @return diameter of circle
 */
float Circle::calcCircleDiameter() {
    diameter = 2 * radius;
    return diameter;
}


std::string Circle::shapeToString(){
    std::string circleString;
    circleString = "Circle:\n\tCenter point: (" +
            std::to_string(x) + ", " + std::to_string(y) +
            ")\n\tRadius: " + std::to_string(radius) +
            "\n\tArea: " + std::to_string(area)+
            "\n\tCircumference: " +
            std::to_string(circumference) +
            "\n\tDiameter: " + std::to_string(diameter);
    return circleString;
}