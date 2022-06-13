#include "World.hpp"

//---------------------
//--| Model Configs |--
//---------------------
//-- Window Scale (in Pixels) :
//- for 3K Monitors := 222
//- for 2k Monitors := 180
//- for 1k Monitors := 140
double modelScale = 222;
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

//---------------------
//--| Robot Configs |--
//---------------------
//-- Robot Size (in Meter) :
double robotSize  = 0.2;
//-- Sharpness of Robot (in Degree) :
double robotSharpness = 140.0;
//-- Robot Spawining Position (According to Scale in Meter) :
double xSpawn = 0.5;
double ySpawn = 0.5;

//-- Mathematical 
double rad = 0.0174533;

double Radian(double input){
    input *= rad;
    return rad;
}



//-- Spawn Time Configuration
World::World(){
    worldCreate();
    agentCenterX = xSpawn * windowWidth * modelScale;
    agentCenterY = ySpawn * windowLength * modelScale;
}

void World::worldCreate(){
    //-- Update Window Frames Rate :
    // sleep_for(milliseconds(200));
    HelpWindow status;
    status.updateHelpWindow();
    field.fieldCreate();
    robotCreate();
    // status.updateHelpWindow();;
    waitKey(0);
    destroyAllWindows();
    worldCreate();
}

void World::robotCreate(){
    //-- Creates Agent
    field.Access().copyTo(Agent);
    //-- Point Center
    Point agentCenter(agentCenterX, agentCenterY);

    //-- Point Direction
    agentDirectionX = agentCenterX + robotSize * cos(Radian(robot.Access()));
    agentDirectionY = agentCenterY + robotSize * sin(Radian(robot.Access()));
    Point agentDirection(agentDirectionX * modelScale, agentDirectionY * modelScale);
    line(Agent, agentCenter, agentDirection, Scalar(255,0,0), lineSize, 8, 0);
    //-- Point Right
    //-- Point Left




    imshow("Soccer Ground 2", Agent);
}
