#ifndef SOCCERCONFIGS_HPP
#define SOCCERCONFIGS_HPP
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

using namespace std;
using namespace cv;
using namespace chrono;
using namespace this_thread;

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
double lineSize = 6;
//-- Blue, Green, Red
double fieldBlue = 100;
double fieldGreen = 100;
double fieldRed = 100;

//---------------------
//--| Robot Configs |--
//---------------------
//-- Robot Size (in Meter) :
double robotSize  =0.2;
//-- Sharpness of Robot (in Degree) :
double robotSharpness  =140.0;

//-------------------------
//--| Movements Configs |--
//-------------------------
//-- Robot Spawining Position (According to Scale in Meter) :
double xSpawn  =1/2;
double ySpawn  =4/11;
//-- Robot Move (in Pixels)
double robotMove = 2.0;
//-- Robot Rotation (in Degree)
double robotRotation  =1.0;
//-- Max Movement Speed (in m/s)
double maxMovementSpeed  =20;
//-- Max Rotation Speed (in Degree/s)
double maxRotationSpeed  =10;

//---------------------------
//--| Robocup Field Rules |--
//---------------------------
//-- Field Width & Length
double fieldWidth  =6;
double fieldLength  =9;
//-- Field Padding (in Meter)
double fieldPadding  =1;
//-- Penalty Area (in Meter)
double penaltyAreaWidth = 5;
double penaltyAreaLength  =2;
//-- Goal Area (in Meter)
double goalAreaWidth = 3;
double goalAreaLength  =1;
//-- Goal (in Meter)
double goalWidth  =2.6;
double goalDepth  =0.6;
//-- Middle Circle Diameter (in Meter)
double middleCircle1  =0.1;
double middleCircle2  =1.5 ;
//-- Middle Line Size
double middleLine = 6;

//--------------------
//--| Mathematical |--
//--------------------
//-- Half
double half = 1/2;

//---------------------------------------
//--| Playground and Help Window Size |--
//---------------------------------------
double windowWidth = (fieldWidth + 2 * fieldPadding);
double windowLength = (fieldLength + 2 * fieldPadding);
double helpWindowWidth = fieldWidth / 2;
double helpWindowLength = fieldLength;

#endif // SOCCERCONFIGS_HPP