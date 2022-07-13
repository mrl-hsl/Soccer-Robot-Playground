<h1 align="center">
  <br>
  <a href="https://github.com/maze80/Soccer-Robot-Playground"><img src="https://s6.uupload.ir/files/hsl_0dhk.png" alt="HSL" width="200"></a>
  <br>
  Humanoid Soccer Robot 
  <br>
</h1>

<b><h4 align="center">.:: Soccer-Robot-Playground ::.</h4></b>

<p align="center">
<a href="https://github.com/maze80/Soccer-Robot-Playground"><img src="https://img.shields.io/badge/Version-1.2.1-brightgreen" alt="HSL" width="100"></a>
<a href="https://github.com/maze80/Soccer-Robot-Playground"><img src="https://img.shields.io/badge/Platform-linux--64-blue" alt="HSL" width="130"></a>
<a href="https://github.com/maze80/Soccer-Robot-Playground/blob/main/LICENSE.md"><img src="https://img.shields.io/badge/LICENSE-GNU-red" alt="HSL" width="110"></a>
<a href="https://github.com/maze80/Soccer-Robot-Playground/network/members"><img src="https://img.shields.io/badge/Developers-2-lightgrey" alt="HSL" width="100"></a>
</p>

# Table Switch

- [Introduction](#introduction)
- [Primary Dependencies](#dependencies)
- [Program Headers](#program-headers)
- [How To Run](#how-to-run)
- [Developers](#developers)
  
# Introduction

  Soccer Robot Playground is a simulation of world model which includes two section of grounds.
  
  - Real World : 
    - In this scope , program display the soccer field with an agent (a robot sample) inside it.\
    Field's coordinate is based on RoboCup soccer humanoid league laws 2022 and the agent is surrounded by a border that consist the absolute 
    playground area.\
    The features of the Real World are Movement by keyboard , Transition by mouse and a Helpwindow for declaring the keys 
    and represent the robot exact location on screen.
      
  - Model World :
    - Robot modeling is a part of program which make a simple shape of an agent and switch the location of shape into the original one.\
    To comprehend that what does modeling exactly do , consider the airplane's radar so that the radar make a shape of airplane on 
    it's screen nearby the own system.\
    But the impotant note is that the modeling system will upgrade only by agent's location in every frames !!
    
  To get more information and explanation about the World Model , refer to the Document of project.
  

# Dependencies

This project is completely based on [C++ language](https://cplusplus.com/) and we have hardly tried to write the codes with simple syntax to make it
easier for understanding and help beginners to develop it much better.\
Most part of the program is powered by OpenCV version 4 in C++ form. To make it install , you can use 
this [orientation](https://dev.to/swervin/how-to-install-opencv-4-2-0-on-ubuntu-18-04-3i7l).\
   - All of the libraries are contained in this project :\
    ```
     <iostream> <sstream> <iomanip> <string> <chrono> <thread> <vector> <cmath> 
    ```\
They are totaly exist in Config.hpp and declaring inside every headers.
    


# Program Headers
# How To Run
# Developers
