#include "World.hpp"
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
#include <cmath>

World::World(){
    // state = 1;
    // counter = 0;
    // stopStateValue = 0;
    // activeStateValue = 0;

    Field field;
    // HelpWindow status;
    worldCreate();
}

void World::worldCreate(){
    //-- Update Window Frames Rate :
    sleep_for(milliseconds(20));
    field.makeField();
    // status.updateHelpWindow();
    waitKey(0);
    destroyAllWindows();
    worldCreate();
}