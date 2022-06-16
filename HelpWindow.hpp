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
        string status;
        string speedStatus;
    public:
        void updateHelpWindow();
        int activityCircle();
        HelpWindow();
        //-- Update Status of Changes
        void updateStatus(int, double);
};

#endif // HELPWINDOW_HPP
