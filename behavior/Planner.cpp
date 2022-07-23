#include "Planner.hpp"
#include <vector>


void Behavior::behaviorVelocity() {
    vector <double> posGlobal(3, 0);
    posGlobal[0] = -(point.x - (windowLength * modelScale / 2)) / modelScale;
    posGlobal[1] = (point.y - (windowWidth * modelScale / 2)) / modelScale;
    // posGlobal[2] = 0;

    posGlobal[2] = atan2(arrowHead.y - point.y, arrowHead.x - point.x);
    // cout << posGlobal[2] << endl;
    
    vector <double> robotPos(3, 0);
    robotPos[0] = robot.accessX();
    robotPos[1] = robot.accessY();
    robotPos[2] = robot.accessTheta();
    
    vector <double> relative = poseRelative(posGlobal, robotPos);

    // cout<<"robot : "<<robot.accessX()<<" "<<robot.accessY()<<" "<<robot.accessTheta()<<endl;
    // cout<<"posGlobal : "<<posGlobal[0]<<" "<<posGlobal[1]<<" "<<posGlobal[2]<<endl;
    // cout<<"relative : "<<relative[0]<<" "<<relative[1]<<" "<<relative[2]<<endl;

    double vx,vy,vtheta;
    double vMax = 1,vThetaMax = 1;
    double result = sqrt(pow(relative[0], 2) + pow(relative[1], 2));
    
    vx = (relative[0] / result) * vMax;
    vy = (relative[1] / result) * vMax;
    vtheta = (relative[2] / M_PI) * vThetaMax;
    double thetaaa = atan2(relative[1], relative[0]);
    // cout << "theta: "<< thetaaa << endl;
    
    robot.setVelocity(vx, vy, thetaaa); 
}

void Behavior::setMousePoint(Point click, Point arrow) {
    point = click;
    arrowHead = arrow;
}


