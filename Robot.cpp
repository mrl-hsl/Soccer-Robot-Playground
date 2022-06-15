#include "Robot.hpp"

//-- Set Function
//-- Spawn X, Spawn Y, Spawn Rotation, Model Scale, Model Length, Model Width
void Robot::robotSet(double x, double y ,double r, double scale, double l, double w){
    robotX = x;
    robotY = y;
    robotTetha = r;
    windowScale = scale;
    length = l;
    width = w;
}

//-- Save Current Position before Movement
void Robot::savePosition(double inputX, double inputY, double inputTetha){
    robotLastX = inputX;
    robotLastY = inputY;
    robotLastTetha = inputTetha;
}

//-- Access to X Cordinate of Robot
double Robot::accessX(){
    return robotX;
}

//-- Access to Y Cordinate of Robot
double Robot::accessY(){
    return robotY;
}

//-- Access to Rotation of Robot
double Robot::accessTetha(){
    return robotTetha;
}

//-- Check Impact with Border
int Robot::borderCheck(){
    //-- if Impaction then Move to Last Position
   if (robotX * windowScale <=  )




}   

//-- Reset Check Value
void Robot::resetCheck(){

}