#ifndef WORLD_HPP
#define WORLD_HPP

//-- Includes Needed Files
#include "HelpWindow.hpp"
#include "Field.hpp"
#include "Robot.hpp"
#include "Planner.hpp"
#include "Util.hpp"

class World {
private:
    Field field;
    Robot robot;
    HelpWindow status;
    Behavior behavior;
    Mat realWorld;
    int behaviourMode;
    double behaviorMode = -1;
    double moveSignal = 0;
    bool makeArrow = false;
    Point point;
    Point arrowHead;
    bool arrow = false;

public:
    World();
    int updateWindow();
    void create();
    static void mouseAttacher(int ,int ,int ,int ,void *);
    void Mouse(int ,int ,int ,int);
};

#endif // WORLD_HPP
