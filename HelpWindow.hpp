#ifndef HELPWINDOW_HPP
#define HELPWINDOW_HPP

#include "Configs.hpp"

//-- Help Window Class
class HelpWindow {
    private:
        Mat helpWin;
        Mat directionArrow;
        int activeStateValue; // fadeing
        int stopStateValue; // inactive
        int counter;
        int state;
    public:
        void updateHelpWindow();
        int activityCircle();
};

#endif // HELPWINDOW_HPP
