#ifndef FIELD_HPP
#define FIELD_HPP

#include "Configs.hpp"

//-- Field Class
class Field{
    private:
        Mat Ground;
    public:
        Field();
        void makeField();
};

Field::Field(){
    if (modelScale >= 2500){
        fontSize = 1.7;
        lineSize = 8;
    }
    else if (modelScale > 1550 && modelScale < 2500){
        fontSize = 1.2;
        lineSize = 6;
    }
    else{
        fontSize = 0.2;
        lineSize = 1;
    }
}


#endif // FIELD_HPP