# Soccer-Robot-Playground
have to fix:

1) robot not moving
2) util not working properly

what has been added:
1) made an additional header file and cpp file for the bahavior mode.
2) some flags.
3) more mouse functions.

how does it work:
1) in the update window there is a bahavior option that you can click and enter to behavior mode.
2) when you make the "bahaviorMode = 1" you can click on the 'world' window and make points.
3) by clicking the left button on mouse, the points will be saved in "point".
4) after that by moving the mouse you make the "makeArrow = true" and then an arrow will be drawn. but it has a maximum size.
5) and when you put yout finger off of the left button you make the "moveSignal = 1" and in update window there is a if satement for it.
6) if "moveSignal is = 1" call "bahavior.setMousePoint(point, arrowHead)" to save the points in Bahavior class.
7) then by calling the other finction we are basically doing the following: first we are making vector elements to save global positions of the robot and destination. second we are saving the relative position of these two on another vectore, using util.cpp.
8) after all that we should just set the velocity.
9) by using some variables like max velicity we can change the bahavior of robot.

** sadly this does not work for now so I didn't explaine it fully.
