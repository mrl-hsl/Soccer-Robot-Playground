#ifndef PLANNER_HPP
#define PLANNER_HPP

#include "HelpWindow.hpp"
#include "Field.hpp"
#include "Robot.hpp"
#include "Util.hpp"

class Behavior {
private:
    Robot robot;
    Point point;
    Point arrowHead;

public:

    void behaviorVelocity();
    void setMousePoint(Point, Point);

};

#endif // PLANNER_HPP
