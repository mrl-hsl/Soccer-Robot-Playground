#ifndef WORLD_HPP
#define WORLD_HPP

//-- Includes Needed Files
#include "HelpWindow.hpp"
#include "Field.hpp"
#include "Robot.hpp"
#include "Planner.hpp"

class World {
private:
    Field field;
    Robot robot;
    HelpWindow status;
    Mat realWorld;
    Planner planner;
    bool plannerMode;
public:
    World();
    int updateWindow();
    void create();
    static void mouseAttacher(int ,int ,int ,int ,void *);
    void Mouse(int ,int ,int ,int);
    cv::Point2d pixel2Meter(cv::Point pixel);
    cv::Point meter2Pixel(cv::Point2d meter);
};

#endif // WORLD_HPP
