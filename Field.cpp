#include "Field.hpp"
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
#include <cmath>

Field::Field(){
    double Scale = modelScale * 12;
    if (Scale >= 2500){
        fontSize = 1.7;
        lineSize = 4;
    }
    else if (Scale > 1550 && Scale < 2500){
        fontSize = 1.2;
        lineSize = 4;
    }
    else{
        fontSize = 0.2;
        lineSize = 1;
    }
}

void Field::makeField(){
    //-- Creates the Window
    Ground = Mat(windowWidth * modelScale, windowLength * modelScale, CV_8UC3, 1.0);

    //--------------
    //--| Points |--
    //--------------
    //-- Ground Corners
    Point topLeft(0, 0);
    Point downRight(windowLength * modelScale - lineSize, windowWidth * modelScale - lineSize);
    //-- Field Corners, Middle Line and Middle Circle
    Point fieldCorner1(fieldPadding * modelScale, fieldPadding * modelScale);
    Point fieldCorner2((fieldPadding + fieldLength) * modelScale, (fieldPadding + fieldWidth) * modelScale);
    Point middleLineTop((windowLength * half) * modelScale, fieldPadding * modelScale);
    Point middleLineDown((windowLength * half) * modelScale, (fieldPadding + middleLine) * modelScale);
    Point middle((fieldPadding + fieldLength * half) * modelScale, (fieldPadding + fieldWidth * half) * modelScale);
    //-- Penalty Areas Corners
    //- Team :
    Point penaltyCornerTop1(fieldPadding * modelScale, (windowWidth - penaltyAreaWidth) * half * modelScale);
    Point penaltyCornerDown1((fieldPadding + penaltyAreaLength) * modelScale, (windowWidth + penaltyAreaWidth) * half * modelScale);
    //- Enemy :
    Point penaltyCornerTop2((windowLength - fieldPadding) * modelScale, (windowWidth - penaltyAreaWidth) * half * modelScale);
    Point penaltyCornerDown2((windowLength - fieldPadding - penaltyAreaLength) * modelScale, (windowWidth + penaltyAreaWidth) * half * modelScale);
    //-- Goal Areas Corners
    //- Team :
    Point goalAreaCornerTop1(fieldPadding * modelScale, (windowWidth - goalAreaWidth) * half * modelScale);
    Point goalAreaCornerDown1((fieldPadding + goalAreaLength) * modelScale, (windowWidth + goalAreaWidth) * half * modelScale);
    //- Enemy :
    Point goalAreaCornerTop2((windowLength - fieldPadding) * modelScale, (windowWidth - goalAreaWidth) * half * modelScale);
    Point goalAreaCornerDown2((windowLength - fieldPadding - goalAreaLength) * modelScale, (windowWidth + goalAreaWidth) * half * modelScale);
    //-- Goals Corners
    //- Team :
    Point goalCornerTop1(fieldPadding * modelScale, (windowWidth - goalWidth) * half * modelScale);
    Point goalCornerDown1((fieldPadding - goalDepth) * modelScale, (windowWidth + goalWidth) * half * modelScale);
    //- Enemy :
    Point goalCornerTop2((windowLength - fieldPadding) * modelScale, (windowWidth - goalWidth) * half * modelScale);
    Point goalCornerDown2((windowLength - fieldPadding + goalDepth) * modelScale, (windowWidth + goalWidth) * half * modelScale);

    //------------------------
    //--| Draw with Points |--
    //------------------------
    //-- Ground
    rectangle(Ground, topLeft, downRight, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);

    //-- Field
    rectangle(Ground, fieldCorner1, fieldCorner2, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);

    //-- Middle
    line(Ground, middleLineTop, middleLineDown, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);
    circle(Ground, middle, middleCircle1 * modelScale / 2, Scalar(fieldBlue, fieldGreen, fieldRed), -1, 8, 0);
    circle(Ground, middle, middleCircle2 * modelScale / 2, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);

    //-- Penalty Areas
    rectangle(Ground, penaltyCornerTop1, penaltyCornerDown1, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);
    rectangle(Ground, penaltyCornerTop2, penaltyCornerDown2, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);

    //-- Goal Areas
    rectangle(Ground, goalAreaCornerTop1, goalAreaCornerDown1, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);
    rectangle(Ground, goalAreaCornerTop2, goalAreaCornerDown2, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);    
    //-- Goals
    rectangle(Ground, goalCornerTop1, goalCornerDown1, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);
    rectangle(Ground, goalCornerTop2, goalCornerDown2, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);    
    imshow("Play Ground", Ground);
}