#ifndef WORLD_HPP
#define WORLD_HPP

//-- Includes Needed Files
// #include "Configs.hpp"
#include "Field.hpp"
#include "HelpWindow.hpp"
#include "Robot.hpp"
// #include "Robot.hpp"
// #include "HelpWindow.hpp"

class World {
private:
    Field field;
    Robot robot;
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
    void worldCreate();
    void robotCreate();
};

#endif // WORLD_HPP
