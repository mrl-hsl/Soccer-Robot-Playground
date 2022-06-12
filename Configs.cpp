// #include "Configs.hpp"

  config::config()
  {
    modelScale = 222;
    modelMode = 1;
    fontSize = 1.2;
    lineSize = 6;
    fieldBlue = 100;
    fieldGreen = 100;
    fieldRed = 100;    
    robotSize = 0.2;
    robotSharpness = 140.0;
    xSpawn = 1/2;
    ySpawn = 4/11;
    robotMove = 2.0;
    robotRotation = 1.0;
    maxMovementSpeed = 20;
    maxRotationSpeed = 10;
    fieldWidth = 6;
    fieldLength = 9;
    fieldPadding = 1;
    penaltyAreaWidth = 5;
    penaltyAreaLength = 2;
    goalAreaWidth = 3;
    goalAreaLength = 1;
    goalWidth = 2.6;
    goalDepth = 0.6;
    middleCircle1 = 0.1;
    middleCircle2 = 1.5;
    middleLine = 6;
    half = 1/2;
    windowWidth = (fieldWidth + 2 * fieldPadding);
    windowLength = (fieldLength + 2 * fieldPadding);
    helpWindowWidth = fieldWidth / 2;
    helpWindowLength = fieldLength;
    cout << "\033[1;95mConfig Data ...... \033[1;37m[Done]\033[0m" << endl;
  }