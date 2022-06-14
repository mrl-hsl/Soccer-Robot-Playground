#include "World.hpp"

//---------------------
//--| Model Configs |--
//---------------------
//-- Window Scale (in Pixels) :
//- for 3K Monitors := 222
//- for 2k Monitors := 180
//- for 1k Monitors := 140
double modelScale = 200;
//-- GameMode :
//- 0 : Position Control
//- 1 : Velocity Control
double modelMode = 1;
//-- Font Size Scale :
double fontSize = 1.2;
//-- Lines of Model Scale :
double lineSize = 4;
//-- Blue, Green, Red
double fieldBlue = 100;
double fieldGreen = 100;
double fieldRed = 100;
//-- Mathematical 
#define rad 0.0174533

//---------------------
//--| Robot Configs |--
//---------------------
//-- Robot Size (in Meter) :
double robotSize  = 0.15;
double robotLineSize = 2.5;
//-- Sharpness of Robot (in Degree) :
double robotSharpness = 140.0;
//-- Robot Spawining Position (According to Scale in Meter) :
double xSpawn = 0.5;
double ySpawn = 0.5;
double rotationSpawn = 0;
//-- Robot Colors
double robotBlue = 212;
double robotGreen = 255;
double robotRed = 127;

//-- Convert Degree to Radian
double Radian(double input){
    input *= rad;
    return input;
}

//-- Spawning Configuration in Constructor
World::World(){
    agentCenterX = xSpawn * windowLength;
    agentCenterY = ySpawn * windowWidth;
    updateWindow();
}


void World::updateWindow(){
    //-- Update Window Frames Rate :
    // sleep_for(milliseconds(200));
    status.updateHelpWindow();
    field.fieldCreate();
    robotCreate();
    waitKey(0);
    destroyAllWindows();
    updateWindow();
}

//-- Draws the Robot on Field
void World::robotCreate(){
    //-------------------
    //--| Robot Shape |--
    //-------------------
    //-- Creates Agent
    field.Access().copyTo(Agent);
    //-- Point Center
    Point agentCenter(agentCenterX * modelScale, agentCenterY * modelScale);
    //-- Point Direction
    agentDirectionX = agentCenterX - robotSize * cos(Radian(rotationSpawn));
    agentDirectionY = agentCenterY - robotSize * sin(Radian(rotationSpawn));
    Point agentDirection(agentDirectionX * modelScale, agentDirectionY * modelScale);
    //-- Point Right
    agentRightX = agentCenterX - robotSize * cos(Radian(rotationSpawn + robotSharpness));
    agentRightY = agentCenterY - robotSize * sin(Radian(rotationSpawn + robotSharpness));
    Point agentRight(agentRightX * modelScale, agentRightY * modelScale);
    //-- Point Left
    agentLeftX = agentCenterX - robotSize * cos(Radian(rotationSpawn - robotSharpness));
    agentLeftY = agentCenterY - robotSize * sin(Radian(rotationSpawn - robotSharpness));
    Point agentLeft(agentLeftX * modelScale, agentLeftY * modelScale);
    //-- DR Line
    line(Agent, agentDirection, agentRight, Scalar(robotBlue, robotGreen, robotRed), robotLineSize, 8, 0);
    //-- DL Line
    line(Agent, agentDirection, agentLeft, Scalar(robotBlue, robotGreen, robotRed), robotLineSize, 8, 0);
    //-- OR Line
    line(Agent, agentCenter, agentRight, Scalar(robotBlue, robotGreen, robotRed), robotLineSize, 8, 0);
    //-- OL Line
    line(Agent, agentCenter, agentLeft, Scalar(robotBlue, robotGreen, robotRed), robotLineSize, 8, 0);
    imshow("Soccer Ground 2", Agent);
}
