//File: main.cpp
//CLass: COP 3003 Fall 2022
//Dev: Jorge Cano
//Desc: main file for shapes project
//---------------------------------------------------------
#include <iostream>
#include "shape.h"
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "circle.h"

//Function Proto-Types
//---------------------------------------------------------
void printMenu();
void printShapesList(std::vector<Shape*> shapes);
Line setLineVal();
Rectangle setRectangleVal();
Circle setCircleVal();

//Function Definitions
//---------------------------------------------------------
int main() {
    std::vector<Shape*>  shapes{};
    bool Loop = true;
    int menuChoice;


    //loops through a switch statement that takes
    //the users input and creates a shape based on the
    //input given
    do {
        printMenu();
        std::cin >> menuChoice;
        if(!(menuChoice >= 1 && menuChoice <= 5)){
            std::cout << "Invalid input.\n";
            exit(0);
        }
        Line *line = new Line();
        Rectangle *rectangle = new Rectangle();
        Circle *circle = new Circle();

        switch(menuChoice) {
            case 1:
                //calls function to set values for the shape
                //and saves it to line pointer
                *line = setLineVal();
                //adds shape to shape pointer vector
                shapes.push_back(line);
                break;
            case 2:
                //calls function to set values for the shape
                //and saves it to rectangle pointer
                *rectangle = setRectangleVal();
                //adds shape to shape pointer vector
                shapes.push_back(rectangle);
                break;
            case 3:
                //calls function to set values for the shape
                //and saves it to circle pointer
                *circle = setCircleVal();
                //adds shape to shape pointer vector
                shapes.push_back(circle);
                break;
            case 4:
                //function call to print the contents in
                //the shapes vector
                printShapesList(shapes);
                break;
            case 5:
                Loop = false;
        }
    }while(Loop);

    std::cout << "Done.";
    return 0;
}
// End of Main


/**
 * this prints the menu of shapes
 */
void printMenu(){
    std::cout << "Select an option: \n";
    std::cout << "\t1.Line\n" << "\t2.Rectangle\n" <<
    "\t3.Circle\n" << "\t4.Print Shapes\n" <<
    "\t5.Exit\n";
}


void printShapesList(std::vector<Shape*> shapes){
    std::cout << "Shapes: \n";

    //loop cycles through each shape pointer and prints
    //the returned value from the shapeToString function
    for(auto s : shapes){
        std::cout << "\t" << s->shapeToString() << "\n\n";
    }

}


/**
 * sets the point values for the line
 * @return pointer to line class object
 */
Line setLineVal(){
    int x1, y1, x2, y2;
    Line *l = new Line();

    std::cout << "Enter the first point (x, y): ";
    std::cin >> x1 >> y1;
    l->setX1(x1);
    l->setY1(y1);
    if(isdigit(x1) && isdigit(y1)){
        l->addToPointVector(x1, y1);
    }
    else{
        std::cout << "Invalid Input.\n";
        exit(0);
    }

    std::cout << "Enter the Second point (x, y): ";
    std::cin >> x2 >> y2;
    l->setX2(x2);
    l->setY2(y2);
    if(isdigit(x2) && isdigit(y2)){
        l->addToPointVector(x2, y2);
    }
    else{
        std::cout << "Invalid Input.\n";
        exit(0);
    }

    l->calcLineSlope();
    l->calcLineDistance();
    l->calcLineAngle();
    l->calcLineIntercept();
    return *l;
}


/**
 * sets the values for the rectangle
 * @return pointer to rectangle class object
 */
Rectangle setRectangleVal(){
    int x, y;
    float width, length;
    Rectangle *r = new Rectangle();

    std::cout << "Enter the first point (x, y): ";
    std::cin >> x >> y;
    if(isdigit(x) && isdigit(y)){
        r->setPoint1(x, y);
    }
    else{
        std::cout << "Invalid Input.";
        exit(0);
    }

    std::cout << "Enter the width: ";
    std::cin >> width;
    if(isdigit(width)){
        r->setWidth(width);
    }
    else{
        std::cout << "Invalid Input.";
        exit(0);
    }

    std::cout << "Enter the length: ";
    std::cin >> length;
    if(isdigit(length)){
        r->setWidth(length);
    }
    else{
        std::cout << "Invalid Input.";
        exit(0);
    }

    r->setPoint2(x, y + length);
    r->setPoint3(x + width, y);
    r->setPoint4(x + width, y + length);

    r->calcRectangleArea();
    r->calcRectanglePerimeter();
    return *r;
}


/**
 * sets the values for creating circle
 * center point, and radius
 * @return pointer to circle class object
 */
Circle setCircleVal(){
    int x, y;
    int radius;
    Circle *c = new Circle;

    std::cout << "Enter center point (x, y): ";
    std::cin >> x >> y;
    c->setX(x);
    c->setY(y);

    std::cout << "Enter radius: ";
    std::cin >> radius;
    if(isdigit(radius)){
        c->setRadius(radius);
    }
    else{
        std::cout << "Invalid Input.";
        exit(0);
    }

    c->calcCircleArea();
    c->calcCircleCircumference();
    c->calcCircleDiameter();
    return *c;
}
