#include "HelpWindow.hpp"

//---------------------------------
//--| Help Window Configuration |--
//---------------------------------
//-- Help Window Size
double helpWindowWidth = fieldLength / 1.3;
double helpWindowLength = fieldWidth / 2;
//-- Activity Circle Colors and Attributes
int activityStateValue = 0;
int stopStateValue = 0;
int counter = 0;
int state = 1;
//-- Help Window Background Color Config
int windowColorBlue = 20;
int windowColorGreen = 20;
int windowColorRed = 20;
//-- Help Window Font Size
int helpWindowFontSize;
//-- Help Window Text Colors
int helpWindowTextBlue = 255 ;
int helpWindowTextGreen = 255;
int helpWindowTextRed = 0;

//-- Constructor to Set Default Values
HelpWindow::HelpWindow(){
    double Scale = modelScale * 12;
    if (Scale >= 2500){
        helpWindowFontSize = 1.3;
    }
    else if (Scale > 1550 && Scale < 2500){
        helpWindowFontSize = 0.8;
    }
    else{
        helpWindowFontSize = 0.4;
    }
    positionW = 0.0625;
    positionS = 0.125;
    positionD = 0.1875;
    positionA = 0.25;
    positionP = 0.3125;
    positionC = 0.375;
    positionM = 0.4375;
    positionR = 0.5;
    positionQ = 0.5625;
    positionText = 0.0625;
    positionStatus = 0.40625;
}

void HelpWindow::updateHelpWindow(){
    //-- Creates Help Window
    helpWin = Mat(helpWindowWidth * modelScale, helpWindowLength * modelScale, CV_8UC3, 1.0);
    
    //-- Attributes are Defined Here
    Point helpWindowTopCorner(0, 0);
    Point helpWindowDownCorner(helpWindowLength * modelScale, helpWindowWidth * modelScale);
    Point helpWinStatus(helpWindowWidth * half * modelScale, (helpWindowLength * positionStatus) * modelScale); //-- Activity Text
    Point helpWinKeyW(helpWindowLength * positionText * modelScale, helpWindowWidth * positionW * modelScale);
    Point helpWinKeyS(helpWindowLength * positionText * modelScale, helpWindowWidth * positionS * modelScale);
    Point helpWinKeyD(helpWindowLength * positionText * modelScale, helpWindowWidth * positionD * modelScale);
    Point helpWinKeyA(helpWindowLength * positionText * modelScale, helpWindowWidth * positionA * modelScale);
    Point helpWinKeyP(helpWindowLength * positionText * modelScale, helpWindowWidth * positionP * modelScale);
    Point helpWinKeyC(helpWindowLength * positionText * modelScale, helpWindowWidth * positionC * modelScale);
    Point helpWinKeyM(helpWindowLength * positionText * modelScale, helpWindowWidth * positionM * modelScale);
    Point helpWinKeyR(helpWindowLength * positionText * modelScale, helpWindowWidth * positionR * modelScale);
    Point helpWinKeyQ(helpWindowLength * positionText * modelScale, helpWindowWidth * positionQ * modelScale);
    string keyW;
    string keyS;
    string keyD;
    string keyA;
    string keyP;
    string keyC;
    string keyM;
    string keyR;
    string keyQ;
    string keyReset;
    string status;

    //-- Background
    rectangle(helpWin, helpWindowTopCorner, helpWindowDownCorner, Scalar(windowColorBlue, windowColorGreen, windowColorRed), -1, 8, 0);
    
    //-- Help Window Acts According to Mode
    if (modelMode = 1){
        keyW = "W : Increase Movement Speed"; 
        keyS = "S : Decrease Movement Speed";
        keyD = "D : Increase Rotation Speed";
        keyA = "A : Decrease Rotation Speed";
        keyP = "P : Stops the Agent";
        keyC = "C : Change Speed :";
        keyM = " - M : Movement";
        keyR = " - R : Rotation";
        keyQ = "Q : Quit the Program";
        keyReset = "R : Reset Position to the Middle";
        status = "N/A";
        putText(helpWin, keyP, helpWinKeyP, FONT_HERSHEY_DUPLEX, helpWindowFontSize, Scalar(helpWindowTextBlue, helpWindowTextGreen, helpWindowTextRed));
        putText(helpWin, keyC, helpWinKeyC, FONT_HERSHEY_DUPLEX, helpWindowFontSize, Scalar(helpWindowTextBlue, helpWindowTextGreen, helpWindowTextRed));
        putText(helpWin, keyM, helpWinKeyM, FONT_HERSHEY_DUPLEX, helpWindowFontSize, Scalar(helpWindowTextBlue, helpWindowTextGreen, helpWindowTextRed));
        putText(helpWin, keyR, helpWinKeyR, FONT_HERSHEY_DUPLEX, helpWindowFontSize, Scalar(helpWindowTextBlue, helpWindowTextGreen, helpWindowTextRed));
        putText(helpWin, status, helpWinStatus, FONT_HERSHEY_DUPLEX, helpWindowFontSize, Scalar(0, 255, 255));
        //status circle here
    }
    else if (modelMode = 0){
        keyW = "W : Go Forward"; 
        keyS = "S : Go Backward";
        keyD = "D : Rotate Right";
        keyA = "A : Rotate Left";
        keyQ = "Q : Quit the Program";
        keyReset = "R : Reset Position to the Middle";
    }
    else if (modelMode != 0 && modelMode != 1){
        rectangle(helpWin, helpWindowTopCorner, helpWindowDownCorner, Scalar(0, 0, 40), -1, 8, 0);
        line(helpWin, helpWindowTopCorner, helpWindowDownCorner, Scalar(0, 0, 255), 5, 8 ,0);
        status = " No Data";
        putText(helpWin, status, helpWinStatus, FONT_HERSHEY_DUPLEX, 0.8, Scalar(0, 255, 255));
    }

    //-- Window Texts
    putText(helpWin, keyW, helpWinKeyW, FONT_HERSHEY_DUPLEX, helpWindowFontSize, Scalar(helpWindowTextBlue, helpWindowTextGreen, helpWindowTextRed));
    putText(helpWin, keyS, helpWinKeyS, FONT_HERSHEY_DUPLEX, helpWindowFontSize, Scalar(helpWindowTextBlue, helpWindowTextGreen, helpWindowTextRed));
    putText(helpWin, keyD, helpWinKeyD, FONT_HERSHEY_DUPLEX, helpWindowFontSize, Scalar(helpWindowTextBlue, helpWindowTextGreen, helpWindowTextRed));
    putText(helpWin, keyA, helpWinKeyA, FONT_HERSHEY_DUPLEX, helpWindowFontSize, Scalar(helpWindowTextBlue, helpWindowTextGreen, helpWindowTextRed));
    putText(helpWin, keyQ, helpWinKeyQ, FONT_HERSHEY_DUPLEX, helpWindowFontSize, Scalar(helpWindowTextBlue, helpWindowTextGreen, helpWindowTextRed));

imshow("Help Window", helpWin);

//las line is circle func
}

