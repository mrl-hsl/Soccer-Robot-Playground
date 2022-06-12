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
extern double modelScale;
//-- GameMode :
//- 0 : Position Control
//- 1 : Velocity Control
extern double modelMode;
//-- Font Size Scale :
extern double fontSize;
//-- Lines of Model Scale :
extern double lineSize;
//-- Blue, Green, Red
extern double fieldBlue;
extern double fieldGreen;
extern double fieldRed;

//---------------------
//--| Robot Configs |--
//---------------------
//-- Robot Size (in Meter) :
extern double robotSize;
//-- Sharpness of Robot (in Degree) :
extern double robotSharpness;

//-------------------------
//--| Movements Configs |--
//-------------------------
//-- Robot Spawining Position (According to Scale in Meter) :
extern double xSpawn ;
extern double ySpawn ;
//-- Robot Move (in Pixels)
extern double robotMove ;
//-- Robot Rotation (in Degree)
extern double robotRotation ;
//-- Max Movement Speed (in m/s)
extern double maxMovementSpeed  ;
//-- Max Rotation Speed (in Degree/s)
extern double maxRotationSpeed  ;

//---------------------------
//--| Robocup Field Rules |--
//---------------------------
//-- Field Width & Length
extern double fieldWidth  ;
extern double fieldLength ;
//-- Field Padding (in Meter)
extern double fieldPadding ;
//-- Penalty Area (in Meter)
extern double penaltyAreaWidth ;
extern double penaltyAreaLength ;
//-- Goal Area (in Meter)
extern double goalAreaWidth;
extern double goalAreaLength ;
//-- Goal (in Meter)
extern double goalWidth ;
extern double goalDepth  ;
//-- Middle Circle Diameter (in Meter)
extern double middleCircle1  ;
extern double middleCircle2  ;
//-- Middle Line Size
extern double middleLine ;

//--------------------
//--| Mathematical |--
//--------------------
//-- Half
extern double half ;

//---------------------------------------
//--| Playground and Help Window Size |--
//---------------------------------------
extern double windowWidth;
extern double windowLength ;
extern double helpWindowWidth ;
extern double helpWindowLength ;

#endif // SOCCERCONFIGS_HPP