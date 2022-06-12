#include "Field.hpp"

Field::makeField(){

    //-- Creates the Window
    Ground = Mat(windowWidth * modelScale, windowLength * modelScale, CV_8UC3, 1.0);

    //--------------
    //--| Points |--
    //--------------
    //-- Ground Corners
    Point topLeft(0, 0);
    Point downRight(windowWidth * modelScale - lineSize, windowLength * modelScale - lineSize);
    //-- Field Corners, Middle Line and Middle Circle
    Point fieldCorner1(fieldPadding * modelScale, fieldPadding * modelScale);
    Point fieldCorner2((fieldPadding + fieldLength) * modelScale, (fieldPadding + fieldWidth) * modelScale);
    Point middleLineTop((fieldPadding + fieldLength * half) * modelScale, fieldPadding * modelScale);
    Point middleLineDown((fieldPadding + fieldLength * half) * modelScale, (fieldPadding + middleLine) * modelScale);
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
    goalCornerTop1(fieldPadding * modelScale, (windowWidth - goalWidth) * half * modelScale);
    goalCornerDown1((fieldPadding - goalDepth) * modelScale, (windowWidth + goalWidth) * half * modelScale);
    //- Enemy :
    goalCornerTop2((windowLength - fieldPadding) * modelScale, (windowWidth - goalWidth) * half * modelScale);
    goalCornerDown2((windowLength - fieldPadding + goalDepth) * modelScale, (windowWidth + goalWidth) * half * modelScale);

    //------------------------
    //--| Draw with Points |--
    //------------------------
    //-- Ground
    rectangle(Ground, topLeft, downRight, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);

    //-- Field
    rectangle(Ground, fieldCorner1, fieldCorner2, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);

    //-- Middle
    line(Ground, middleLineTop, middleLineDown, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);
    circle(Ground, middle, middleCircle1, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);
    circle(Ground, middle, middleCircle2, Scalar(fieldBlue, fieldGreen, fieldRed), lineSize, 8, 0);











}
