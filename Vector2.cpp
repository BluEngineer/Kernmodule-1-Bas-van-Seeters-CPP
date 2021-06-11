//
// Created by basva on 19/05/2021.
//

#include "Vector2.h"

//constructors
Vector2::Vector2(float newX, float newY)
{
    xValue = newX;
    yValue = newY;

}

//de-constructor
Vector2::~Vector2()= default;

//methods
void Vector2::Set(float x, float y)
{
    xValue = x;
    yValue = y;
}

float Vector2::x(){return xValue;}
float Vector2::y(){return yValue;}