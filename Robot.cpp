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
    movementSpeed = 0;
    rotationSpeed = 0;
    resetSpeed();
}

//-- Save Current Position before Movement
void Robot::savePosition(double inputX, double inputY, double inputTetha) {
    robotLastX = inputX;
    robotLastY = inputY;
    robotLastTetha = inputTetha;
    lastMovementSpeed = movementSpeed;
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

//-- Access to Movement Speed
double Robot::accessMovementSpeed() {
    return movementSpeed;
}

//-- Access to Rotation Speed
double Robot::accessRotationSpeed() {
    return rotationSpeed;
}

//-- Check Impact with Border       [complete later]
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
    movementSpeed = 0;
    rotationSpeed = 0;
}

//-- Output Error
string Robot::error() {
    return errorInfo;
}

//-- Seek Movement and Rotation Changes
int Robot::state() {
    int output;
    if (lastMovementSpeed != movementSpeed){
        output = 1;
    }
    if (lastRotationSpeed != rotationSpeed){
        output = -1;
    }
    if (lastRotationSpeed == rotationSpeed && lastMovementSpeed == movementSpeed){
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
void Robot::setTime(int t1, int t2) {
    updateTime = t1;
    constTime = t2;
}

//-- Set Robot's Velocity (Movement Velocity, Rotation Velocity)
void Robot::updateVelocity(double movementVelocity, double rotationVelocity) {
    movementSpeed += movementVelocity;
    rotationSpeed += rotationVelocity;
}

//-- Updates Robot's Position
void Robot::Action() {
    //-- Movement Part
    //- X :
    robotX = robotX - timeSpeed * movementSpeed * cos(robotTetha) * (updateTime / constTime);
    //- Y :
    robotY = robotY - timeSpeed * movementSpeed * sin(robotTetha) * (updateTime / constTime);
    //-- Rotation Part
    robotTetha = robotTetha + timeSpeed * rotationSpeed * (updateTime / constTime);
}
