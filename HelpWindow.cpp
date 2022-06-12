#include "HelpWindow.hpp"

int HelpWindow::activityCircle()
{
    Mat helpWin(helpWindowWidth * modelScale, helpWindowLength * modelScale, CV_8UC3, 1.0);
    int _temp1 = activeStateValue;
    int _temp2 = stopStateValue;
    if (_move_speed == 0 && _rotate_speed == 0)
    {
        activeStateValue = 0;
        stopStateValue = stopStateValue + state * 17;
        if (counter % 1 == 0)
        {
            if (stopStateValue > 255)
            {
                state = -1;
            }
            else if (stopStateValue < 0)
            {
                state = 1;
                stopStateValue = _temp2;
            }
        }
        else if (counter > 100)
        {
            counter = 0;
        }
    }
    else
    {
        stopStateValue = 0;
        activeStateValue = activeStateValue + state * 17; //- bug maybe will be here if i run the program
        if (counter % 1 == 0)
        {
            if (activeStateValue > 255)
            {
                state = -1;
                // -or here i need the _temp 
            }
            else if (activeStateValue < 0)
            {
                state = 1;
                activeStateValue = _temp1;
            }   
        }
        else if (counter > 100)
        {
            counter = 0;
        }
    }
    counter++;
    return activeStateValue;
}