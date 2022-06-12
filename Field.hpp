#ifndef FIELD_HPP
#define FIELD_HPP

#include "Configs.hpp"


//-- wrong place for variables
double fontSize = 1.2;
double lineSize = 6;
double fieldBlue = 100;
double fieldGreen = 100;
double fieldRed = 100;
double windowWidth = (fieldWidth + 2 * fieldPadding);
double windowLength = (fieldLength + 2 * fieldPadding);
double helpWindowWidth = fieldWidth / 2;
double helpWindowLength = fieldLength;

//-- Field Class
class Field{
    private:
        Mat Ground;
    public:
        Field();
        void makeField();
};

#endif // FIELD_HPP


