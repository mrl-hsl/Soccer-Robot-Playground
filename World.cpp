#include "World.hpp"
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
#include <cmath>

double modelScale = 222;
double modelMode = 1;
double fontSize = 1.2;
double lineSize = 4;
double fieldBlue = 100;
double fieldGreen = 100;
double fieldRed = 100;
double robotSize  = 0.2;
double robotSharpness = 140.0;
double xSpawn = 1/2;
double ySpawn = 0.4;
double robotMove = 2.0;
double robotRotation = 1.0;
double maxMovementSpeed = 20;
double maxRotationSpeed = 10;
double fieldWidth = 6;
double fieldLength = 9;
double fieldPadding = 1;
double penaltyAreaWidth = 5;
double penaltyAreaLength = 2;
double goalAreaWidth = 3;
double goalAreaLength = 1;
double goalWidth = 2.6;
double goalDepth = 0.6;
double middleCircle1 = 0.1;
double middleCircle2 = 1.5 ;
double middleLine = 6;
double half = 0.5;
double windowWidth = (fieldWidth + 2 * fieldPadding);
double windowLength = (fieldLength + 2 * fieldPadding);
double helpWindowWidth = fieldWidth / 2;
double helpWindowLength = fieldLength;

World::World(){
    // state = 1;
    // counter = 0;
    // stopStateValue = 0;
    // activeStateValue = 0;

    Field field;
    // HelpWindow status;
    worldCreate();
}

void World::worldCreate(){
    //-- Update Window Frames Rate :
    sleep_for(milliseconds(20));
    field.makeField();
    // status.updateHelpWindow();
    waitKey(0);
    destroyAllWindows();
    worldCreate();
}