//
// Created by basva on 19/05/2021.
//

#ifndef UNTITLED_VECTOR2_H
#define UNTITLED_VECTOR2_H


class Vector2
{
public:
    Vector2(float createX, float newY);
    float x();
    float y();


~Vector2();

//METHODS
void Set(float xValue, float yValue);


private:
    float xValue;
    float yValue;

};
#endif //UNTITLED_VECTOR2_H
