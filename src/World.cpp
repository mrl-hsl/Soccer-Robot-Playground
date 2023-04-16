#include "include/World.hpp"

//---------------------
//--| Model Configs |--
//---------------------
//-- Robot Size (in Meter) :
double robotSize  = 0.18;
double robotLineSize = 2.5;
double modelLineSize = 5;
//-- Window Scale (in Pixels) :
//- for 3K Monitors := 222
//- for 2k Monitors := 120
//- for 1k Monitors := 80
double modelScale = 100;
//-- Font Size Scale :
double fontSize = 1.2;
//-- Lines of Model Scale :
double lineSize = 4;
//-- Blue, Green, Red
double fieldLineBlue = 100;
double fieldLineGreen = 100;
double fieldLineRed = 100;
double fieldBGBlue = 0;
double fieldBGGreen = 0;
double fieldBGRed = 0;
double enemyGoalBlue = 200;
double enemyGoalGreen = 220;
double enemyGoalRed = 0;
double teamGoalBlue = 0;
double teamGoalGreen = 220;
double teamGoalRed = 220;
//-- Refresh Rate (ms)
double refreshRate = 20.0 / 1000.0;
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
//-- Model Window Size
double modelLength = windowLength * half;
double modelWidth = windowWidth * half;

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
//-- Model Colors
double modelBlue = 164;
double modelGreen = 108;
double modelRed = 180;
//-- Color Value When Clicked
int clickedColorValue = 0;
//-- Speed Increase/Decrease Value
double moveSpeedValue = 0.2;
double rotateSpeedValue = 0.4;


//-- Spawning Configuration in Constructor
World::World() {
    robot.setPosition(xSpawn * windowLength, ySpawn * windowWidth, 0);
    robot.setVelocity(0, 0, 0);
    model.setPosition(robot.accessX(), robot.accessY(), robot.accessTheta());
    model.setVelocity(0, 0, 0);
    field.fieldCreate();
    create();
    setMouseCallback("World", mouseAttacher, this);
    mouseFlag = 1;
    robot.storePosition(0, 0, 0, 0, 0, 0);
    updateWindow();
}

//-- Updates Frames of Program
int World::updateWindow() {
    while (true) {
        //-- Update Window Frame's Refresh Rate :
        sleep_for(milliseconds((int)refreshRate * 1000));
        create();
        if (robot.accessVX() != 0 || robot.accessVY() != 0 || robot.accessVTheta() != 0) {
            status.updateHelpWindow(true);
        } else {
            status.updateHelpWindow(false);
        }
        if (robot.borderCheck() == 0) {
            if (robot.state() == 1) {
                status.updateStatus(1, robot.accessVX());
            } else if (robot.state() == 2) {
                status.updateStatus(2, robot.accessVY());
            } else if(robot.state() == 3) {
                status.updateStatus(3, robot.accessVTheta());
            } else if (robot.state() == 0) {
                status.updateStatus(0, 0);
            }
            switch(waitKey(1)) {
                case (int('l')):
                    robot.storePosition(robot.accessX(), robot.accessY(), robot.accessTheta(), robot.accessVX(), robot.accessVY(), robot.accessVTheta());
                    status.resetError();
                    model.setVelocity(model.accessVX(), model.accessVY(), model.accessVTheta() + rotateSpeedValue);
                    robot.setVelocity(robot.accessVX(), robot.accessVY(), robot.accessVTheta() + rotateSpeedValue);
                break;
                case (int('j')):
                    robot.storePosition(robot.accessX(), robot.accessY(), robot.accessTheta(), robot.accessVX(), robot.accessVY(), robot.accessVTheta());
                    status.resetError();
                    model.setVelocity(model.accessVX(), model.accessVY(), model.accessVTheta() - rotateSpeedValue);
                    robot.setVelocity(robot.accessVX(), robot.accessVY(), robot.accessVTheta() - rotateSpeedValue);
                break;
                case (int('i')):
                    robot.storePosition(robot.accessX(), robot.accessY(), robot.accessTheta(), robot.accessVX(), robot.accessVY(), robot.accessVTheta());
                    status.resetError();
                    model.setVelocity(model.accessVX() + moveSpeedValue, model.accessVY(), model.accessVTheta());
                    robot.setVelocity(robot.accessVX() + moveSpeedValue, robot.accessVY(), robot.accessVTheta());
                break;
                case (int(';')):
                    robot.storePosition(robot.accessX(), robot.accessY(), robot.accessTheta(), robot.accessVX(), robot.accessVY(), robot.accessVTheta());
                    status.resetError();
                    model.setVelocity(model.accessVX(), model.accessVY() + moveSpeedValue, model.accessVTheta());
                    robot.setVelocity(robot.accessVX(), robot.accessVY() + moveSpeedValue, robot.accessVTheta());
                break;
                case (int(',')):
                    robot.storePosition(robot.accessX(), robot.accessY(), robot.accessTheta(), robot.accessVX(), robot.accessVY(), robot.accessVTheta());
                    status.resetError();
                    model.setVelocity(model.accessVX() - moveSpeedValue, model.accessVY(), model.accessVTheta());
                    robot.setVelocity(robot.accessVX() - moveSpeedValue, robot.accessVY(), robot.accessVTheta());
                break;
                case (int('h')):
                    robot.storePosition(robot.accessX(), robot.accessY(), robot.accessTheta(), robot.accessVX(), robot.accessVY(), robot.accessVTheta());
                    status.resetError();
                    model.setVelocity(model.accessVX(), model.accessVY() - moveSpeedValue, model.accessVTheta());
                    robot.setVelocity(robot.accessVX(), robot.accessVY() - moveSpeedValue, robot.accessVTheta());
                break;
                //-- [j] --> Reset Key
                case (int('k')):
                    robot.setVelocity(0, 0, 0);
                    model.setVelocity(0, 0, 0);
                break;
                case (int('r')):
                    robot.setPosition(xSpawn * windowLength, ySpawn * windowWidth, 0);
                    robot.setVelocity(0, 0, 0);
                    model.setPosition(xSpawn * windowLength, ySpawn * windowWidth, 0);
                    model.setVelocity(0, 0, 0);
                break;
                //-- [Q] --> Quit Key
                case (int('q')):
                    destroyAllWindows();
                    return 0;
                break;
            }
            if ( mouseFlag == 0 || mouseFlag == -1 || mouseFlag == 2) {
                robot.setVelocity(0, 0, 0);
            }
            model.update();
            robot.update();
        } else {
            robot.resetCheck();
            // robot.setVelocity(0, 0, 0);
            status.updateError(robot.error());
        }
    }
    cout << "end @" << endl;
    return 0;
}

//-- Draws the Robot on Field
void World::create() {
    //-- Creates Agent and Model
    field.Access().copyTo(realWorld);
    field.Access().copyTo(modelWorld);
    // modelWorld = Mat(modelWidth * modelScale, modelLength * modelScale, CV_8UC3, Scalar(fieldBGBlue, fieldBGGreen, fieldBGRed));
    // resize(modelWorld, modelWorld, Size(windowLength * modelScale * half, windowWidth * modelScale * half), INTER_LINEAR);
    //-------------
    //--| World |--
    //-------------
    double agentCenterX = robot.accessX();
    double agentCenterY = robot.accessY();
    double agentTheta = robot.accessTheta();
    double agentDirectionX;
    double agentDirectionY;
    double agentRightX;
    double agentRightY;
    double agentLeftX;
    double agentLeftY;
    //-- Point Center
    Point agentCenter(agentCenterX * modelScale, agentCenterY * modelScale);
    //-- Point Direction
    agentDirectionX = agentCenterX - robotSize * cos(agentTheta);
    agentDirectionY = agentCenterY - robotSize * sin(agentTheta);
    Point agentDirection(agentDirectionX * modelScale, agentDirectionY * modelScale);
    //-- Point Right
    agentRightX = agentCenterX - robotSize * cos(agentTheta + (robotSharpness * M_PI / 180));
    agentRightY = agentCenterY - robotSize * sin(agentTheta + (robotSharpness * M_PI / 180));
    Point agentRight(agentRightX * modelScale, agentRightY * modelScale);
    //-- Point Left
    agentLeftX = agentCenterX - robotSize * cos(agentTheta - (robotSharpness * M_PI / 180));
    agentLeftY = agentCenterY - robotSize * sin(agentTheta - (robotSharpness * M_PI / 180));
    Point agentLeft(agentLeftX * modelScale, agentLeftY * modelScale);
    //-- DR Line
    line(realWorld, agentDirection, agentRight, Scalar(robotBlue - clickedColorValue, robotGreen - clickedColorValue, robotRed - clickedColorValue), robotLineSize, 8, 0);
    //-- DL Line
    line(realWorld, agentDirection, agentLeft, Scalar(robotBlue - clickedColorValue, robotGreen - clickedColorValue, robotRed - clickedColorValue), robotLineSize, 8, 0);
    //-- OR Line
    line(realWorld, agentCenter, agentRight, Scalar(robotBlue - clickedColorValue, robotGreen - clickedColorValue, robotRed - clickedColorValue), robotLineSize, 8, 0);
    //-- OL Line
    line(realWorld, agentCenter, agentLeft, Scalar(robotBlue - clickedColorValue, robotGreen - clickedColorValue, robotRed - clickedColorValue), robotLineSize, 8, 0);
    Point agentInfo(agentCenterX * modelScale, (agentCenterY + 0.3) * modelScale); 
    //-------------
    //--| Model |--
    //-------------
    double modelCenterX = model.accessX();
    double modelCenterY = model.accessY();
    double modelTheta = model.accessTheta();
    double modelDirectionX = modelCenterX - robotSize * cos(modelTheta);
    double modelDirectionY = modelCenterY - robotSize * sin(modelTheta);
    double modelSize = robotSize * modelScale;
    //-- Point Center
    Point modelCenter(modelCenterX * modelScale, modelCenterY * modelScale);
    //-- Point Direction
    Point modelDirection(modelDirectionX * modelScale, modelDirectionY * modelScale);
    //-- Model Circle
    circle(modelWorld, modelCenter, modelSize, Scalar(modelBlue, modelGreen, modelRed), modelLineSize / 2, 8, 0);
    //-- Direction Center
    circle(modelWorld, modelDirection, modelSize / 4, Scalar(modelBlue + 50, modelGreen + 50, modelRed + 50), -1, 8, 0);
    //-- OD Line
    line(modelWorld, modelCenter, modelDirection, Scalar(modelBlue + 50, modelGreen + 50, modelRed + 50), modelLineSize / 2, 8, 0);
    imshow("Model", modelWorld);
    imshow("World", realWorld);
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
                    mouseDistance = sqrt(pow(robot.accessX() * modelScale - x, 2) + pow(robot.accessY() * modelScale - y, 2));
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
                case EVENT_LBUTTONUP:
                robot.setVelocity(model.accessVX(), model.accessVY(), model.accessVTheta());
                    clickedColorValue = 0;
                    mouseFlag = 1;
                break;
                case EVENT_MOUSEHWHEEL:
                    if (getMouseWheelDelta(flags) < 0){
                        robot.setTheta(robot.accessTheta() + mouseRotationValue * M_PI / 180);
                    } else {
                        robot.setTheta(robot.accessTheta() - mouseRotationValue * M_PI / 180);
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
                //-- Double Click Left Button to Decrease Theta
                case EVENT_LBUTTONDOWN:
                    robot.setTheta(robot.accessTheta() - mouseRotationValue * M_PI / 180);
                break;
                //-- Double Click Right Button to Increase Theta
                case EVENT_RBUTTONDOWN:
                    robot.setTheta(robot.accessTheta() + mouseRotationValue * M_PI / 180);
                break;
                case EVENT_MBUTTONDOWN:
                    mouseFlag = -1;
                break;
            }
        }
    } else {
        robot.resetCheck();
        robot.setVelocity(0, 0, 0);
        status.updateError(robot.error());
        updateWindow();
    }
}