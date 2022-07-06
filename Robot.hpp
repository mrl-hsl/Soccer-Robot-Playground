#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Configs.hpp"

//-- Robot Class
class Robot {
    private:
        double x;
        double y;
        double robotLastX;
        double robotLastY;
        double theta;
        double robotLastTetha;
        int checkValue;
        string errorInfo;
        double movementSpeedX;
        double movementSpeedY;
        double globalmovementSpeedX;
        double globalmovementSpeedY;
        double rotationSpeed;
        double lastMovementSpeedX;
        double lastMovementSpeedY;
        double lastRotationSpeed;
        double updateTime;
    public:
        //-- Config Robot's Spawn Position
        void robotSet();
        //-- Save Current Position before Movement
        void savePosition(double, double, double);
        //-- Position Accessors
        double accessX();
        double accessY();
        double accessTheta();
        void setX(double);
        void setY(double);
        void setTetha(double);
        double accessMovementSpeedX();
        double accessMovementSpeedY();
        double accessRotationSpeed();
        //-- Border Impact Check
        int borderCheck();
        void resetCheck();
        //-- Reset Robot's Speed
        void resetSpeed();
        //-- Error Output
        string error();
        //-- Seek Movement and Rotation Changes
        int state();
        //-- Reset Robot's Position to Spawn Point
        void resetPosition();
        //-- Set Robot's Refresh Time
        void setTime(double);
        //-- Set Robot's Velocity (Movement Velocity, Rotation Velocity)
        void setVelocity(double, double, double);
        void Action();
};

#endif // ROBOT_HPP
