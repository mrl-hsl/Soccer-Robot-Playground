#include "include/Model.hpp"

//-- Set Default Robot Position
void Model::setPosition(double inputX, double inputY, double inputTheta) {
    x = inputX;
    y = inputY;
    theta = inputTheta;
    vX = 0;
    vY = 0;
    vTheta = 0;
}

//-- Pass Robot's Speed to Model
void Model::setVelocity(double inputX, double inputY, double inputTheta) {
    vX = inputX;
    vY = inputY;
    vTheta = inputTheta;
}

//-- Update Position
void Model::update() {
    double globalVX = vX * cos(theta) + vY * sin(-theta);
    double globalVY = vY * cos(-theta) + vX * sin(theta);
    theta += vTheta * refreshRate;
    x = x - globalVX * refreshRate;
    y = y - globalVY * refreshRate;
}


//-- Access Model's X
double Model::accessX() {
    return x;
}

//-- Access Model's Y
double Model::accessY() {
    return y;
}

//-- Access Model's Theta
double Model::accessTheta() {
    return theta;
}

//-- Access Model's Velocity in X Axis
double Model::accessVX() {
    return vX;
}

//-- Access Model's Velocity in Y Axis
double Model::accessVY() {
    return vY;
}

//-- Access Model's Velocity in Rotation
double Model::accessVTheta() {
    return vTheta;
}