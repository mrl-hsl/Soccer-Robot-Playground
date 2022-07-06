#include "World.hpp"

//---------------------
//--| Model Configs |--
//---------------------
//-- Robot Size (in Meter) :
double robotSize  = 0.18;
double robotLineSize = 2.5;
//-- Window Scale (in Pixels) :
//- for 3K Monitors := 222
//- for 2k Monitors := 180
//- for 1k Monitors := 140
double modelScale = 120;
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
double fieldBGBlue = 0;
double fieldBGGreen = 0;
double fieldBGRed = 0;
//-- Refresh Rate (ms)
double refreshRate = 1.0 / 100.0;
//-- Mathematical 
double rad = 0.0174533;
//-- Mouse Click Flag
int mouseFlag;
//-- Rotation Value with Mouse
double mouseRotationValue = 10;
//-- Click Area Radius
double clickAreaRadius = robotSize * modelScale;
//-- Mouse Distance to Center of Agent
double mouseDistance;

//---------------------
//--| Robot Configs |--
//---------------------
//-- Sharpness of Robot (in Degree) :
double robotSharpness = 140.0;
//-- Robot Spawining Position (According to Scale in Meter) :
double xSpawn = 0;
double ySpawn = 0;
double rotationSpawn = M_PI;
//-- Robot Colors
double robotBlue = 212;
double robotGreen = 255;
double robotRed = 127;
//-- Color Value When Clicked
int clickedColorValue = 0;
//-- Speed Increase/Decrease Value
double moveSpeedValue = 0.35;
double rotateSpeedValue = 0.4;

//-- Spawning Configuration in Constructor
World::World() {
    cout << "done";
    robot.setTime(refreshRate);
    robot.robotSet();
    robot.savePosition(robot.accessX(), robot.accessY(), robot.accessTheta());
    field.fieldCreate();
    robotStateUpdate();
    setMouseCallback("Soccer Ground 2", mouseAttacher, this); 
    mouseFlag = 1;
    i = 0;
    updateWindow();
}

//-- Updates Frames of Program
int World::updateWindow() {
    //-- Counter for Frames
    cout << "hi" << endl;
    // waitKey(0);
    if (robot.accessMovementSpeedX() != 0 || robot.accessMovementSpeedY() != 0 || robot.accessRotationSpeed() != 0) {
        i++;
    }

    //-- Update Window Frame's Refresh Rate :
    sleep_for(milliseconds((int)refreshRate*1000));
    agentCenterX = robot.accessX();
    agentCenterY = robot.accessY();
    agentRotation = robot.accessTheta();
    robotStateUpdate();
    if (robot.accessMovementSpeedX() != 0 || robot.accessMovementSpeedY() != 0 || robot.accessRotationSpeed() != 0) {
        status.updateHelpWindow(true);
    } else {
        status.updateHelpWindow(false);
    }
    if (robot.borderCheck() == 0) {
        robot.savePosition(agentCenterX, agentCenterY, agentRotation);
        if (robot.state() == 1) {
            status.updateStatus(1, sqrt(pow(robot.accessMovementSpeedX(), 2) + pow(robot.accessMovementSpeedY(), 2)));
        } else if (robot.state() == -1) {
            status.updateStatus(-1, robot.accessRotationSpeed());
        } else if (robot.state() == 0) {
            status.updateStatus(0, 0);
        }
        switch(waitKey(1)) {
            //-- [j] --> Increase Rotation Speed Key
            case (int('j')):
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX(), robot.accessMovementSpeedY(), robot.accessRotationSpeed() + moveSpeedValue);
            break;
            //-- [l] --> Decrease Rotation Speed Key
            case (int('l')):
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX(), robot.accessMovementSpeedY(), robot.accessRotationSpeed() - moveSpeedValue);
            break;
            //-- [O] --> Increase Velocity in X Axis
            case (int('i')):
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX() + moveSpeedValue, robot.accessMovementSpeedY(), robot.accessRotationSpeed());
            break;
            //-- [h] --> Increase Velocity in Y Axis
            case (int('h')):
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX(), robot.accessMovementSpeedY() - moveSpeedValue, robot.accessRotationSpeed());
            break;
            //-- [I] --> Decrease Velocity in X Axis
            case (int(',')):
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX() - moveSpeedValue, robot.accessMovementSpeedY(), robot.accessRotationSpeed());
            break;
            //-- [J] --> Decrease Velocity in Y Axis
            case (int(';')):
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX(), robot.accessMovementSpeedY() + moveSpeedValue, robot.accessRotationSpeed());
            break;
            //-- [j] --> Reset Key
            case (int('k')):
                robot.setVelocity(0, 0, 0);
                // robot.resetPosition();
                i = -1;
            break;
            //-- [Q] --> Quit Key
            case (int('q')):
                destroyAllWindows();
                return 0;
            break;
        }
        if ( mouseFlag == 0 || mouseFlag == -1 || mouseFlag == 2){
            robot.resetSpeed();
        }
        robot.Action();
        updateWindow();
    } else {
        robot.resetCheck();
        robot.resetSpeed();
        status.updateError(robot.error());
        updateWindow();
    }
    return 0;
}

//-- Draws the Robot on Field
void World::robotStateUpdate() {
    //-------------------
    //--| Robot Shape |--
    //-------------------
    //-- Creates Agent
    field.Access().copyTo(Agent);
    //-- Point Center
    double robotCenterXPixel = (0.5 * windowLength) + robot.accessX() * modelScale;
    double robotCenterYPixel = (0.5 * windowWidth) + robot.accessY() * modelScale;
    Point agentCenter(robotCenterXPixel, robotCenterYPixel);
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
    line(Agent, agentDirection, agentRight, Scalar(robotBlue - clickedColorValue, robotGreen - clickedColorValue, robotRed - clickedColorValue), robotLineSize, 8, 0);
    //-- DL Line
    line(Agent, agentDirection, agentLeft, Scalar(robotBlue - clickedColorValue, robotGreen - clickedColorValue, robotRed - clickedColorValue), robotLineSize, 8, 0);
    //-- OR Line
    line(Agent, agentCenter, agentRight, Scalar(robotBlue - clickedColorValue, robotGreen - clickedColorValue, robotRed - clickedColorValue), robotLineSize, 8, 0);
    //-- OL Line
    line(Agent, agentCenter, agentLeft, Scalar(robotBlue - clickedColorValue, robotGreen - clickedColorValue, robotRed - clickedColorValue), robotLineSize, 8, 0);
    ostringstream x,y,t;
    x << fixed;
    y << fixed;
    t << fixed;
    x << setprecision(2);
    y << setprecision(2);
    t << setprecision(2);
    x << robot.accessX();
    y << robot.accessY();
    t << robot.accessTheta();
    Point agentInfo(agentCenterX * modelScale, (agentCenterY + 0.3) * modelScale); 
    // putText(Agent, to_string(i), agentInfo, FONT_HERSHEY_DUPLEX, fontSize, Scalar(255,255,0));
    imshow("Soccer Ground 2", Agent);
}

//-- Attach Mouse to Window
void World::mouseAttacher(int event, int x, int y, int flags, void *data){
    World *pointer = reinterpret_cast<World* >(data);
    pointer -> Mouse(event, x, y, flags);
}

//-- Offer Mouse Clicking Options
void World::Mouse(int event, int x, int y, int flags){
    if (robot.borderCheck() == 0){
        if (mouseFlag == 1){
            switch(event){
                //-- Click Left Button to Pick Agent
                case EVENT_LBUTTONDOWN:
                    mouseDistance = sqrt(pow(agentCenterX*modelScale - x, 2) + pow(agentCenterY * modelScale - y, 2));
                    if (mouseDistance < clickAreaRadius) {
                        clickedColorValue = 100;
                        mouseFlag = -1;
                    }
                break;
            }
        } else if (mouseFlag == -1) {
            switch(event){
                //-- Set Agent Position to Cursor Position
                case EVENT_MOUSEMOVE:
                    robot.setX(x / modelScale);
                    robot.setY(y / modelScale);
                break;
                //-- Click Left Button to Place Agent
                case EVENT_LBUTTONDOWN:
                    clickedColorValue = 0;
                    setMouseCallback("Soccer Ground 2", NULL, this);
                    setMouseCallback("Soccer Ground 2", mouseAttacher, this);
                    mouseFlag = 1;
                break;
                case EVENT_MOUSEHWHEEL:
                    if (getMouseWheelDelta(flags) < 0){
                        robot.setTetha(robot.accessTheta() + mouseRotationValue * M_PI / 180);
                    } else {
                        robot.setTetha(robot.accessTheta() - mouseRotationValue * M_PI / 180);
                    }
                break;
                case EVENT_MBUTTONDOWN:
                    mouseFlag = 0;
                break;
            }
        } else if (mouseFlag == 0){
            switch(event){
                case EVENT_MOUSEMOVE:
                    robot.setX(x / modelScale);
                    robot.setY(y / modelScale);
                break;
                //-- Double Click Left Button to Decrease Tetha
                case EVENT_LBUTTONDOWN:
                    robot.setTetha(robot.accessTheta() + mouseRotationValue * M_PI / 180);
                break;
                //-- Double Click Right Button to Increase Tetha
                case EVENT_RBUTTONDOWN:
                    robot.setTetha(robot.accessTheta() - mouseRotationValue * M_PI / 180);
                break;
                case EVENT_MBUTTONDOWN:
                    mouseFlag = -1;
                break;
            }
        }
    } else {
        robot.resetCheck();
        robot.resetSpeed();
        status.updateError(robot.error());
        updateWindow();
    }
}