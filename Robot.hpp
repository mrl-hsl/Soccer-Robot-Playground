#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Configs.hpp"

//-- Robot Class
class Robot {
    private:
        double width;
        double length;
        double robotX;
        double robotY;
        double robotLastX;
        double robotLastY;
        double robotTetha;
        double robotLastTetha;
        double checkValue;
        double windowScale;
    public:
        //-- Config Robot Spawn Position a
        void robotSet(double, double ,double, double, double, double);
        //-- Save Current Position before Movement
        void savePosition(double, double, double);
        //-- Accessors
        double accessX();
        double accessY();
        double accessTetha();
        //-- Border Impact Check
        int borderCheck();
        void resetCheck();

};

#endif // ROBOT_HPP
