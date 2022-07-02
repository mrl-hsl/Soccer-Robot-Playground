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
//-- Refresh Rate (ms)
double refreshRate = 200 / 1000;
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
double xSpawn = 0.5;
double ySpawn = 0.5;
double rotationSpawn = 0;
//-- Robot Colors
double robotBlue = 212;
double robotGreen = 255;
double robotRed = 127;
//-- Color Value When Clicked
int clickedColorValue = 0;

//-- Spawning Configuration in Constructor
World::World() {
    agentCenterX = xSpawn * windowLength;
    agentCenterY = ySpawn * windowWidth;
    agentRotation = rotationSpawn;
    robot.savePosition(agentCenterX, agentCenterY, agentRotation);
    robot.robotSet();
    robot.setTime(refreshRate);
    field.fieldCreate();
    robotStateUpdate();
    setMouseCallback("Soccer Ground 2", mouseAttacher, this); 
    mouseFlag = 1;
    updateWindow();
    i = 0;
}

int World::updateWindow() {
    //-- Counter for Frames
    if (robot.accessMovementSpeedX() != 0 || robot.accessMovementSpeedY() != 0) {
        i++;
    }
    //-- Update Window Frame's Refresh Rate :
    sleep_for(milliseconds((int)refreshRate*1000));
    agentCenterX = robot.accessX();
    agentCenterY = robot.accessY();
    agentRotation = robot.accessTetha();
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
            
            //-- [W] --> Increase Movement Speed Key 
            case 119:
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX() + 1, robot.accessMovementSpeedY() + 1, robot.accessRotationSpeed());
            break;
            //-- [S] --> Decrease Movement Speed Key
            case 115:
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX() - 1, robot.accessMovementSpeedY() - 1, robot.accessRotationSpeed());
            break;
            //-- [D] --> Increase Rotation Speed Key
            case 100:
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX(), robot.accessMovementSpeedY(), robot.accessRotationSpeed() + 1);
            break;
            //-- [A] --> Decrease Rotation Speed Key
            case 97:
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX(), robot.accessMovementSpeedY(), robot.accessRotationSpeed() - 1);
            break;
            //-- [R] --> Position Reset Key
            case 114:
                status.resetError();
                robot.resetPosition();
                i = -1;
            break;
            //-- [O] --> Increase Velocity in X Axis
            case 111:
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX() + 1, robot.accessMovementSpeedY(), robot.accessRotationSpeed());
            break;
            //-- [K] --> Increase Velocity in Y Axis
            case 107:
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX(), robot.accessMovementSpeedY() + 1, robot.accessRotationSpeed());
            break;
            //-- [I] --> Decrease Velocity in X Axis
            case 105:
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX() - 1, robot.accessMovementSpeedY(), robot.accessRotationSpeed());
            break;
            //-- [J] --> Decrease Velocity in Y Axis
            case 106:
                status.resetError();
                robot.setVelocity(robot.accessMovementSpeedX(), robot.accessMovementSpeedY() - 1, robot.accessRotationSpeed());
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
    t << robot.accessTetha();
    Point agentInfo(agentCenterX * modelScale, (agentCenterY + 0.3) * modelScale); 
    putText(Agent, to_string(i), agentInfo, FONT_HERSHEY_DUPLEX, 0.8, Scalar(255,255,0));
    imshow("Soccer Ground 2", Agent);
}

//-- Attach Mouse to Window
void World::mouseAttacher(int event, int x, int y, int flags, void *data){
    World *pointer = reinterpret_cast<World*>(data);
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
                    cout << mouseDistance << endl;
                break;
            }
        } else if (mouseFlag == -1) {
            switch(event){
                //-- Set Agent Position to Cursor Position
                case EVENT_MOUSEMOVE:
                    if (agentCenterX * modelScale - x >= 0){
                        robot.setX((x + mouseDistance * cos(agentRotation)) / modelScale);
                    } else {
                        robot.setX((x - mouseDistance * cos(agentRotation)) / modelScale);
                    }
                    if (agentCenterY * modelScale - y <= 0){
                        robot.setY((y + mouseDistance * sin(agentRotation)) / modelScale);
                    } else {
                        robot.setY((y - mouseDistance * sin(agentRotation)) / modelScale);
                    }
                break;
                //-- Click Left Button to Place Agent
                case EVENT_LBUTTONDOWN:
                    clickedColorValue = 0;
                    setMouseCallback("Soccer Ground 2", NULL, this);
                    setMouseCallback("Soccer Ground 2", mouseAttacher, this);
                    mouseFlag = 1;
                break;
                case EVENT_MBUTTONDOWN:
                    mouseFlag = 0;
                break;
                case EVENT_MOUSEHWHEEL:
                    if (getMouseWheelDelta(flags) < 0){
                        robotSize += 0.1;
                        clickAreaRadius += 0.1 * modelScale;
                    } else {
                        robotSize -= 0.1;
                        clickAreaRadius -= 0.1 * modelScale;
                    }
                break;
            }
        } else {
            switch(event){
                case EVENT_MOUSEMOVE:
                    if (agentCenterX * modelScale - x >= 0){
                        robot.setX((x + mouseDistance * cos(agentRotation)) / modelScale);
                    } else {
                        robot.setX((x - mouseDistance * cos(agentRotation)) / modelScale);
                    }
                    if (agentCenterY * modelScale - y <= 0){
                        robot.setY((y + mouseDistance * sin(agentRotation)) / modelScale);
                    } else {
                        robot.setY((y - mouseDistance * sin(agentRotation)) / modelScale);
                    }
                break;
                //-- Double Click Left Button to Decrease Tetha
                case EVENT_LBUTTONDOWN:
                    robot.setTetha(-mouseRotationValue * M_PI / 180);
                break;
                //-- Double Click Right Button to Increase Tetha
                case EVENT_RBUTTONDOWN:
                    robot.setTetha(+mouseRotationValue * M_PI / 180);
                break;
                case EVENT_MOUSEHWHEEL:
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