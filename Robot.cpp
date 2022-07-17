#include "Robot.hpp"

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
double maxRotationSpeed;
//-- Time Speed, Normal is Equal to 1
double timeSpeed = 1;

//-- Set Function
//-- Spawn X, Spawn Y, Spawn Rotation, Model Scale, Model Length, Model Width
void Robot::robotSet() {
    robotX = xSpawn * windowLength;
    robotY = ySpawn * windowWidth;
    robotTetha = rotationSpawn;
    movementSpeedX = 0;
    movementSpeedY = 0;
    rotationSpeed = 0;
    resetSpeed();
}

//-- Save Current Position before Movement
void Robot::savePosition(double inputX, double inputY, double inputTetha) {
    robotLastX = inputX;
    robotLastY = inputY;
    robotLastTetha = inputTetha;
    lastMovementSpeedX = movementSpeedX;
    lastMovementSpeedY = movementSpeedY;
    lastRotationSpeed = rotationSpeed;
}

//-- Access to X Cordinate of Robot
double Robot::accessX() {
    return robotX;
}

//-- Access to Y Cordinate of Robot
double Robot::accessY() {
    return robotY;
}

//-- Access to Rotation of Robot
double Robot::accessTetha() {
    return robotTetha;
}

//-- Access to Movement Speed (X Vector)
double Robot::accessMovementSpeedX() {
    return movementSpeedX;
}

//-- Access to Movement Speed (Y Vector)
double Robot::accessMovementSpeedY() {
    return movementSpeedY;
}

//-- Access to Rotation Speed
double Robot::accessRotationSpeed() {
    return rotationSpeed;
}

//-- Check Impact with Border
int Robot::borderCheck() {
    //-- if Impaction then Move to Last Position
   if (robotX * modelScale <= fieldPadding * modelScale ){
       robotX = robotLastX ;
       checkValue = -1;
   } else if (robotX * modelScale >= (windowLength - fieldPadding) * modelScale){
       robotX = robotLastX ;
       checkValue = 1;
   } else if (robotY * modelScale <= fieldPadding * modelScale){
       robotY = robotLastY ;
       checkValue = 2;
   } else if (robotY * modelScale >= (windowWidth - fieldPadding) * modelScale){
       robotY = robotLastY ;
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

//-- Reset Speed
void Robot::resetSpeed() {
    movementSpeedX = 0;
    movementSpeedY = 0;
    rotationSpeed = 0;
}

//-- Output Error
string Robot::error() {
    return errorInfo;
}

//-- Seek Movement and Rotation Changes
int Robot::state() {
    int output;
    if (lastMovementSpeedX != movementSpeedX || lastMovementSpeedY != movementSpeedY){
        output = 1;
    }
    if (lastRotationSpeed != rotationSpeed){
        output = -1;
    }
    if (lastRotationSpeed == rotationSpeed && lastMovementSpeedX == movementSpeedX && lastMovementSpeedY == movementSpeedY){
        output = 0;
    }
    return output;
}

//-- Reset's Robot's Position to Spawn Point
void Robot::resetPosition() {
    robotX = xSpawn * windowLength;
    robotY = ySpawn * windowWidth;
}

//-- Set Robot's Refresh Time (Refresh Rate, Refresh Const)
void Robot::setTime(double input) {
    updateTime = input;
}

//-- Set Robot's Velocity (Movement Velocity, Rotation Velocity) //set
void Robot::setVelocity(double Vx, double Vy, double Vtetha) {
    movementSpeedX = Vx;
    movementSpeedY = Vy;
    rotationSpeed = Vtetha;
}

//-- Updates Robot's Position
void Robot::Action() {
    //-- Movement Part
    globalmovementSpeedX = movementSpeedX * cos(robotTetha) + movementSpeedY * sin(-robotTetha);
    globalmovementSpeedY = movementSpeedY * cos(-robotTetha) + movementSpeedX * sin(robotTetha);
    robotX = robotX - globalmovementSpeedX * updateTime;
    robotY = robotY - globalmovementSpeedY * updateTime;
    //-- Rotation Part
    robotTetha -= rotationSpeed * updateTime;
}

//-- Robot X Value Implementor
void Robot::setX(double input){
    robotX = input; 
}

//-- Robot Y Value Implementor
void Robot::setY(double input){
    robotY = input; 
}

//-- Robot Tetha Value Implementor
void Robot::setTetha(double input){
    robotTetha = input;
}
