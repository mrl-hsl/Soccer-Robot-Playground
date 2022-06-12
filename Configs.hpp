//-- Config File
//-- Here You Can Config Program 
//-- Don't Remember to Include this File

//-----------------
//--| Libraries |--
//-----------------
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
#include <cmath>

//---------------------
//--| Model Configs |--
//---------------------
//-- Window Scale (in Pixels) :
//- for 3K Monitors := 222
//- for 2k Monitors := 180
//- for 1k Monitors := 140
#define modelScale 222
//-- GameMode :
//- 0 : Position Control
//- 1 : Velocity Control
#define modelMode 1
//-- Font Size Scale :
double fontSize = 1.2;
//-- Lines of Model Scale :
double lineSize = 6;
//-- Blue, Green, Red
double fieldBlue = 100;
double fieldGreen = 100;
double fieldRed = 100;


//---------------------
//--| Robot Configs |--
//---------------------
//-- Robot Size (in Meter) :
#define robotSize 0.2
//-- Sharpness of Robot (in Degree) :
#define robotSharpness 140.0

//-------------------------
//--| Movements Configs |--
//-------------------------
//-- Robot Spawining Position (According to Scale in Meter) :
#define xSpawn 1/2
#define ySpawn 4/11
//-- Robot Move (in Pixels)
#define robotMove 2.0
//-- Robot Rotation (in Degree)
#define robotRotation 1.0
//-- Max Movement Speed (in m/s)
#define maxMovementSpeed 20
//-- Max Rotation Speed (in Degree/s)
#define maxRotationSpeed 10

//---------------------------
//--| Robocup Field Rules |--
//---------------------------
//-- Field Width & Length
#define fieldWidth 6
#define fieldLength 9
//-- Field Padding (in Meter)
#define fieldPadding 1
//-- Penalty Area (in Meter)
#define penaltyAreaWidth 5
#define penaltyAreaLength 2
//-- Goal Area (in Meter)
#define goalAreaWidth 3
#define goalAreaLength 1
//-- Goal (in Meter)
#define goalWidth 2.6
#define goalDepth 0.6
//-- Middle Circle Diameter (in Meter)
#define middleCircle1 0.1
#define middleCircle2 1.5 
//-- Middle Line Size
#define middleLine 6

//--------------------
//--| Mathematical |--
//--------------------
//-- Half
#define half 1/2

int test;

//-- Window
double windowWidth = (fieldWidth + 2 * fieldPadding);
double windowLength = (fieldLength + 2 * fieldPadding);







