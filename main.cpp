//File: main.cpp
//CLass: COP 3003 Fall 2022
//Dev: Jorge Cano
//Desc: main file for shapes project
//---------------------------------------------------------
#include <iostream>
#include <memory>
#include "shape.h"
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "circle.h"

//Function Proto-Types
//---------------------------------------------------------
void printMenu();
void printShapesList(std::vector<std::shared_ptr<Shape>> shapes);

//setshape functions are now void and no longer return pointers
void setLineVal(std::shared_ptr<Line> l);
void setRectangleVal(std::shared_ptr<Rectangle> r);
void setCircleVal(std::shared_ptr<Circle> c);

//Function Definitions
//---------------------------------------------------------
int main() {
    
    /*shapes is now a vector of smart pointers
     * example of how to do this was from:
     * https://stackoverflow.com/questions/28733385/c11-vector-of-smart-pointer
     * by user: vsoftco */
    std::vector<std::shared_ptr<Shape>> shapes{};
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
        
       /* normal pointers were replaced with smart pointers from the
         * <memory> library */

        auto line = std::make_shared<Line>();
        auto rectangle = std::make_shared<Rectangle>();
        auto circle = std::make_shared<Circle>();

        switch(menuChoice) {
            case 1:
                //calls function to set values for the shape
                //and saves it to line pointer
                setLineVal(line);
                //adds shape to shape pointer vector
                shapes.push_back(line);
                break;
            case 2:
                //calls function to set values for the shape
                //and saves it to rectangle pointer
                setRectangleVal(rectangle);
                //adds shape to shape pointer vector
                shapes.push_back(rectangle);
                break;
            case 3:
                //calls function to set values for the shape
                //and saves it to circle pointer
                setCircleVal(circle);
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


void printShapesList(std::vector<std::shared_ptr<Shape>> shapes){
    std::cout << "Shapes: \n";

    //loop cycles through each shape pointer and prints
    //the returned value from the shapeToString function
    for(auto s : shapes){
        std::cout << "\t" << s->shapeToString() << "\n\n";
    }

}


/**
 * sets the point values for the line
 */
void setLineVal(std::shared_ptr<Line> l){
    int x1, y1, x2, y2;

    bool loop = true;

    //loops if the input from user does not meet criteria which is that both x and y values have to be
    //numbers between -100 and 100
    while(loop){
        std::cout << "Enter the first point (values between -100 and 100) \n";
        std::cout << "Enter x: ";
        std::cin >> x1;
        std::cout << "Enter y: ";
        std::cin >> y1;
        //values are limited in size to avoid buffer issue
        if((x1 >= -100 && x1 <= 100) && (y1 >= -100 && y1 <= 100)){
            loop = false;
        }
        else{
            std::cout << "\nInvalid Input.\n Please enter points that are between -100 and 100.";
            loop = true;
        }
    }
    l->setX1(x1);
    l->setY1(y1);
    l->addToPointVector(x1, y1);

    loop = true;
    while(loop){
        std::cout << "Enter the second point (values between -100 and 100) \n";
        std::cout << "Enter x: ";
        std::cin >> x2;
        std::cout << "Enter y: ";
        std::cin >> y2;
        //values are limited in size to avoid buffer issue
        if((x2 >= -100 && x2 <= 100) && (y2 >= -100 && y2 <= 100)){
            loop = false;
        }
        else{
            std::cout << "\nInvalid Input.\n Please enter points that are between -100 and 100.";
            loop = true;
        }
    }
    l->setX2(x2);
    l->setY2(y2);
    l->addToPointVector(x2, y2);

    l->calcLineSlope();
    l->calcLineDistance();
    l->calcLineAngle();
    l->calcLineIntercept();
}


/**
 * sets the values for the rectangle
 */
void setRectangleVal(std::shared_ptr<Rectangle> r){
    int x, y;
    float width, length;
    bool loop = true;

    //loops if the input from user does not meet criteria which is that both x and y values have to be
    //numbers between -100 and 100
    while(loop){
        std::cout << "Enter the first point (values between -100 and 100) \n";
        std::cout << "Enter x: ";
        std::cin >> x;
        std::cout << "Enter y: ";
        std::cin >> y;
        //values are limited in size to avoid buffer issue
        if((x >= -100 && x <= 100) && (y >= -100 && y <= 100)){
            loop = false;
        }
        else{
            std::cout << "\nInvalid Input.\n Please enter points that are between -100 and 100.";
            loop = true;
        }
    }
    r->setPoint1(x, y);

    loop = true;
    while(loop){
        std::cout << "Enter the width: ";
        std::cin >> width;
        //values are limited in size to avoid buffer issue
        if(width >= 0 && width <= 100){
            loop = false;
        }
        else{
            std::cout << "\nInvalid Input.\n Please enter a value that is between 0 and 100.\n";
            loop = true;
        }
    }
    r->setWidth(width);


    loop = true;
    while(loop){
        std::cout << "Enter the length: ";
        std::cin >> length;
        //values are limited in size to avoid buffer issue
        if(length >= 0 && length <= 100){
            loop = false;
        }
        else{
            std::cout << "\nInvalid Input.\n Please enter a value that is between 0 and 100.\n";
            loop = true;
        }
    }
    r->setLength(length);

    r->setPoint2(x, y + length);
    r->setPoint3(x + width, y);
    r->setPoint4(x + width, y + length);

    r->calcRectangleArea();
    r->calcRectanglePerimeter();
}


/**
 * sets the values for creating circle
 * center point, and radius
 */
void setCircleVal(std::shared_ptr<Circle> c){
    int x, y;
    int radius;

    bool loop = true;

    //loops if the input from user does not meet criteria which is that both x and y values have to be 
    //numbers between -100 and 100
    while(loop){
        std::cout << "Enter the center point (values between -100 and 100) \n";
        std::cout << "Enter x: ";
        std::cin >> x;
        std::cout << "Enter y: ";
        std::cin >> y;
        //values are limited in size to avoid buffer issue
        if((x >= -100 && x <= 100) && (y >= -100 && y <= 100)){
            loop = false;
        }
        else{
            std::cout << "\nInvalid Input.\n Please enter points that are between -100 and 100.";
            loop = true;
        }
    }
    c->setX(x);
    c->setY(y);

    loop = true;
    while(loop) {
        std::cout << "Enter radius: ";
        std::cin >> radius;
        //values are limited in size to avoid buffer issue
        if(radius >= 0 && radius <= 100){
            loop = false;
        }
        else{
            std::cout << "\nInvalid Input.\n Please enter a value that is between -0 and 100.";
            loop = true;
        }
    }
    c->setRadius(radius);

    c->calcCircleArea();
    c->calcCircleCircumference();
    c->calcCircleDiameter();
}
