#ifndef MODEL_HPP
#define MODEL_HPP

#include "Configs.hpp"

class Model {
    private:
        Mat Model;
        double x;
        double y;
        double theta;
        double vX;
        double vY;
        double vTheta;
    public:
        //-- Set Default Robot Position
        void setPosition(double, double, double);
        //-- Pass Robot's Speed to Model
        void setVelocity(double, double, double);
        //-- Update Position
        void update();
        //-- Accessors
        double accessX();
        double accessY();
        double accessTheta();
        double accessVX();
        double accessVY();
        double accessVTheta();
};

#endif // MODEL_HPP