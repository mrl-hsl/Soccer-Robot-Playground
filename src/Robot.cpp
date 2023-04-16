#include "include/Robot.hpp"

//-------------------------
//--| Movements Configs |--
//-------------------------
//-- Robot Move (in Pixels) -- Should be 1, Change it for Making Time Faster
double robotMoveValue = 1;
//-- Robot Rotation (in Degree) -- Should be 1, Change it for Making Time Faster
double robotRotationValue = 1;
//-- Max Movement Speed (in m/s)
double maxMovementSpeed;
//-- Max Rotation Speed (in Degree/s)
double maxvTheta;
//-- Time Speed, Normal is Equal to 1
double timeSpeed = 1;

//-- Set Function
//-- Spawn X, Spawn Y, Spawn Rotation, Model Scale, Model Length, Model Width
void Robot::setPosition(double inputX, double inputY, double inputTheta) {
    x = inputX;
    y = inputY;
    theta = inputTheta;
}

void Robot::storePosition(double inputX, double inputY, double inputTheta, double inputVX, double inputVY, double inputVTheta) {
    tempX = inputX;
    tempY = inputY;
    tempTheta = inputTheta;
    tempVX = inputVX;
    tempVY = inputVY;
    tempVTheta = inputVTheta;

}

//-- Access to X Cordinate of Robot
double Robot::accessX() {
    return x;
}

//-- Access to Y Cordinate of Robot
double Robot::accessY() {
    return y;
}

//-- Access to Rotation of Robot
double Robot::accessTheta() {
    return theta;
}

//-- Access to Movement Speed (X Vector)
double Robot::accessVX() {
    return vX;
}

//-- Access to Movement Speed (Y Vector)
double Robot::accessVY() {
    return vY;
}

//-- Access to Rotation Speed
double Robot::accessVTheta() {
    return vTheta;
}

//-- Check Impact with Border
int Robot::borderCheck() {
    //-- if Impaction then Move to Last Position
   if (x * modelScale <= fieldPadding * modelScale ){
       x = tempX ;
       checkValue = -1;
   } else if (x * modelScale >= (windowLength - fieldPadding) * modelScale){
       x = tempX ;
       checkValue = 1;
   } else if (y * modelScale <= fieldPadding * modelScale){
       y = tempY ;
       checkValue = 2;
   } else if (y * modelScale >= (windowWidth - fieldPadding) * modelScale){
       y = tempY ;
       checkValue = -2;
   } else {
       checkValue = 0;
   }
   switch(checkValue){
        case -1:
            errorInfo = "Can't Go Left More !";
            return 1;
        break;
        case 1:
            errorInfo = "Can't Go Right More !";
            return 1;
        break;
        case -2:
            errorInfo = "Can't Go Down More !";
            return 1;
        break;
        case 2:
            errorInfo = "Can't Go Up More !";
            return 1;
        break;
   }
   return 0;
}   

//-- Reset Check Value
void Robot::resetCheck() {
    checkValue = 0;
}

//-- Output Error
string Robot::error() {
    return errorInfo;
}

//-- Seek Movement and Rotation Changes
int Robot::state() {
    int output;
    if (tempVX != vX) {
        output = 1;
    } else if (tempVY != vY) {
        output = 2;
    }
    if (tempVTheta != vTheta){
        output = 3;
    }
    if (tempVTheta == vTheta && tempVX == vX && tempVY == vY){
        output = 0;
    }
    return output;
}

//-- Set Robot's Velocity (Movement Velocity, Rotation Velocity) //set
void Robot::setVelocity(double inputX, double inputY, double inputTheta) {
    vX = inputX;
    vY = inputY;
    vTheta = inputTheta;
}

//-- Updates Robot's Position
void Robot::update() {
    //-- Movement Part
    double globalVX = vX * cos(theta) + vY * sin(-theta);
    double globalVY = vY * cos(-theta) + vX * sin(theta);
    x = x - globalVX * refreshRate;
    y = y - globalVY * refreshRate;
    //-- Rotation Part
    theta += vTheta * refreshRate;
}

//-- Robot X Value Implementor
void Robot::setX(double input){
    x = input; 
}

//-- Robot Y Value Implementor
void Robot::setY(double input){
    y = input; 
}

//-- Robot Theta Value Implementor
void Robot::setTheta(double input){
    theta = input; 
}