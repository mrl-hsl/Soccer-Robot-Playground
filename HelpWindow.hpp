#ifndef HELPWINDOW_HPP
#define HELPWINDOW_HPP

#include "Configs.hpp"

//-- Help Window Class
class HelpWindow {
    private:
        Mat helpWin;
        double noWindowInfo;
        double positionW;
        double positionS;
        double positionD;
        double positionA;
        double positionP;
        double positionC;
        double positionM;
        double positionR;
        double positionQ;
        double positionText;
        double positionStatus;
        double positionSpeed;
        double positionError;
        double positionStatusCircle;
        double Scale;
        string status;
        string error;
        string speedStatus;
        int activeValue;
        int stoppedValue;
        bool active;
        int state;
        int fadingFluency;
        int fadingSpeed;
        int counter;
        int statusCircleSize;
    public:
        void updateHelpWindow(bool);
        int activityCircle();
        HelpWindow();
        //-- Update Status of Changes
        void updateStatus(int, double);
        void updateError(string);
        int Fader();
        void resetError();
};

#endif // HELPWINDOW_HPP
