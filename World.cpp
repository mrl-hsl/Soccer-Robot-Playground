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
//-- Refresh Rate (ms)
int refreshRate = 1;
//-- Refresh Rate Const (ms)
int refreshConst = 1000;
//-- Mathematical 
double rad = 0.0174533;

//---------------------
//--| Robot Configs |--
//---------------------
//-- Robot Size (in Meter) :
double robotSize  = 0.18;
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

//-- Spawning Configuration in Constructor
World::World(){
    agentCenterX = xSpawn * windowLength;
    agentCenterY = ySpawn * windowWidth;
    agentRotation = rotationSpawn;
    robot.savePosition(agentCenterX, agentCenterY, agentRotation);
    robot.robotSet();
    robot.setTime(refreshRate, refreshConst);
    field.fieldCreate();
    updateWindow();
}

int World::updateWindow(){
    //-- Update Window Frame's Refresh Rate :
    i++;
    status.updateHelpWindow();
    sleep_for(milliseconds(refreshRate));
    agentCenterX = robot.accessX();
    agentCenterY = robot.accessY();
    agentRotation = robot.accessTetha();
    robotStateUpdate();
    if (robot.borderCheck() == 0){
        robot.savePosition(agentCenterX, agentCenterY, agentRotation);
        if (robot.state() == 1){
            status.updateStatus(1, robot.accessMovementSpeed());
        } else if (robot.state() == -1){
            status.updateStatus(-1, robot.accessRotationSpeed());
        } else if (robot.state() == 0){
            status.updateStatus(0, 0);
        }
        switch(waitKey(1)){
            //-- [W] --> Increase Movement Speed Key 
            case 119:
                robot.updateVelocity(1, 0);
            break;
            //-- [S] --> Decrease Movement Speed Key
            case 115:
                robot.updateVelocity(-1, 0);
            break;
            //-- [D] --> Increase Rotation Speed Key
            case 100:
                robot.updateVelocity(0, 1);
            break;
            //-- [A] --> Decrease Rotation Speed Key
            case 97:
                robot.updateVelocity(0, -1);
            break;
            //-- [R] --> Position Reset Key
            case 114:
                robot.resetPosition();
            break;
            //-- [P] --> Pause Key
            case 112:
                robot.resetSpeed();
            break;
            //-- [Q] --> Quit Key
            case 113:
                destroyAllWindows();
                return 0;
            break;
        }
        robot.Action();
        updateWindow();
    } else {
        robot.resetCheck();
        robot.resetSpeed();
        robot.error();
        updateWindow();
    }
    return 0;
}

//-- Draws the Robot on Field
void World::robotStateUpdate(){
    //-------------------
    //--| Robot Shape |--
    //-------------------
    //-- Creates Agent
    field.Access().copyTo(Agent);
    //-- Point Center
    Point agentCenter(agentCenterX * modelScale, agentCenterY * modelScale);
    //-- Point Direction
    agentDirectionX = agentCenterX - robotSize * cos(agentRotation);
    agentDirectionY = agentCenterY - robotSize * sin(agentRotation);
    Point agentDirection(agentDirectionX * modelScale, agentDirectionY * modelScale);
    //-- Point Right
    agentRightX = agentCenterX - robotSize * cos(agentRotation + (robotSharpness * M_PI / 180));
    agentRightY = agentCenterY - robotSize * sin(agentRotation + (robotSharpness * M_PI / 180));
    Point agentRight(agentRightX * modelScale, agentRightY * modelScale);
    //-- Point Left
    agentLeftX = agentCenterX - robotSize * cos(agentRotation - (robotSharpness * M_PI / 180));
    agentLeftY = agentCenterY - robotSize * sin(agentRotation - (robotSharpness * M_PI / 180));
    Point agentLeft(agentLeftX * modelScale, agentLeftY * modelScale);
    //-- DR Line
    line(Agent, agentDirection, agentRight, Scalar(robotBlue, robotGreen, robotRed), robotLineSize, 8, 0);
    //-- DL Line
    line(Agent, agentDirection, agentLeft, Scalar(robotBlue, robotGreen, robotRed), robotLineSize, 8, 0);
    //-- OR Line
    line(Agent, agentCenter, agentRight, Scalar(robotBlue, robotGreen, robotRed), robotLineSize, 8, 0);
    //-- OL Line
    line(Agent, agentCenter, agentLeft, Scalar(robotBlue, robotGreen, robotRed), robotLineSize, 8, 0);
    ostringstream x,y,t;
    x << fixed;
    y << fixed;
    t << fixed;
    x << setprecision(2);
    y << setprecision(2);
    t << setprecision(2);
    x << robot.accessX();
    y << robot.accessY();
    t << robot.accessTetha();
    Point agentInfo(agentCenterX * modelScale, (agentCenterY + 0.3) * modelScale);
    putText(Agent, t.str(), agentDirection, FONT_HERSHEY_DUPLEX, 0.8, Scalar(255,255,255));    
    putText(Agent, x.str(), agentRight, FONT_HERSHEY_DUPLEX, 0.8, Scalar(255,255,255));
    putText(Agent, y.str(), agentLeft, FONT_HERSHEY_DUPLEX, 0.8, Scalar(255,255,255));    
    putText(Agent, to_string(i), agentInfo, FONT_HERSHEY_DUPLEX, 0.8, Scalar(255,255,0));
    imshow("Soccer Ground 2", Agent);
}
