#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Configs.hpp"

//-- Robot Class
class Robot {
    private:
        double robotX;
        double robotY;
        double robotLastX;
        double robotLastY;
        double robotTetha;
        double robotLastTetha;
        int checkValue;
        string errorInfo;
        double movementSpeed;
        double rotationSpeed;
        double lastMovementSpeed;
        double lastRotationSpeed;
        double updateTime;
        double constTime;
    public:
        //-- Config Robot's Spawn Position
        void robotSet();
        //-- Save Current Position before Movement
        void savePosition(double, double, double);
        //-- Position Accessors
        double accessX();
        double accessY();
        double accessTetha();
        double accessMovementSpeed();
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
        void setTime(int, int);
        //-- Set Robot's Velocity (Movement Velocity, Rotation Velocity)
        void updateVelocity(double, double);
        void Action();
};

#endif // ROBOT_HPP
