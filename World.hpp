#ifndef WORLD_HPP
#define WORLD_HPP

//-- Includes Needed Files
#include "Field.hpp"
#include "HelpWindow.hpp"
#include "Robot.hpp"

class World {
private:
    Field field;
    Robot robot;
    HelpWindow status;
    Mat Agent;
    double agentCenterX;
    double agentCenterY;
    double agentRotation;
    double agentLeftX;
    double agentLeftY;
    double agentRightX;
    double agentRightY;
    double agentDirectionX;
    double agentDirectionY;
public:
    World();
    void updateWindow();
    void robotCreate();
};

#endif // WORLD_HPP
