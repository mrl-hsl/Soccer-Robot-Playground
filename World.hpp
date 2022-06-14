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
    double agentDirectionX;
    double agentDirectionY;
    double agentRightX;
    double agentRightY;
    double agentLeftX;
    double agentLeftY;
public:
    World();
    void updateWindow();
    void robotCreate();
};

#endif // WORLD_HPP
