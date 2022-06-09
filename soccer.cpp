#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace cv;
using namespace std;
//=================================
class base{
    protected:
        Mat world;
        int base_size;
    public:
        void set_feild_size();
        base(int size=1000):base_size(size){}
        base(const base &b){ base_size=b.base_size; }
        ~base(){}

};
void base :: set_feild_size() {
    int size;
    cout<<"Enter base feild size : ";
    cin>>size;
    base_size = size;
    world = Mat( size*8/11 , size,CV_8UC3 , 0.0 );
//===============================
    //declaring feild's point
    Point base_start(0,0);
    Point base_finish(base_size - 1 , base_size * 8/11 - 1);
    Point feild_start(base_size * 1/11 , base_size * 1/11);
    Point feild_finish(base_size * 10/11 , base_size * 7/11 );
    Point mline_start(base_size / 2.0 , base_size * 1/11);
    Point mline_finish(base_size / 2.0 , base_size * 7/11);
    Point middle_point(base_size / 2.0 , base_size * 4/11);
    Point r_penalty_start(base_size * 1/11 , base_size * 1.5/11);
    Point r_penalty_finish(base_size * 3/11 , base_size * 6.5/11);
    Point l_penalty_start(base_size * 10/11 , base_size * 6.5/11);
    Point l_penalty_finish(base_size * 8/11 , base_size * 1.5/11);
    Point r_goalarea_start(base_size * 1/11 , base_size * 2.5/11);
    Point r_goalarea_finish(base_size * 2/11 , base_size * 5.5/11);
    Point l_goalarea_start(base_size * 10/11 , base_size * 2.5/11);
    Point l_goalarea_finish(base_size * 9/11 , base_size * 5.5/11);
    Point r_goal_start(base_size * 0.4/11 , base_size * 2.7/11);
    Point r_goal_finish(base_size * 1/11 , base_size * 5.3/11);
    Point l_goal_start(base_size * 10/11 , base_size * 2.7/11);
    Point l_goal_finish(base_size * 10.6/11 , base_size * 5.3/11);
    //creat feild shapes
    rectangle(world, base_start , base_finish , Scalar(255,255,255) , 2, 8, 0);
    rectangle(world, feild_start , feild_finish , Scalar(255,255,255) , 2, 8, 0);
    line(world, mline_start , mline_finish , Scalar(255,255,255) , 2, 8, 0);
    circle(world, middle_point,(base_size * 1.5 / 22) , Scalar(255,255,255) ,2, 8, 0);
    rectangle(world, r_penalty_start , r_penalty_finish , Scalar(255,255,255) , 2, 8, 0);
    rectangle(world, l_penalty_start , l_penalty_finish , Scalar(255,255,255) , 2, 8, 0);
    rectangle(world, l_goal_start , l_goal_finish , Scalar(0,255,255) , 2, 8, 0);
    rectangle(world, r_goal_start , r_goal_finish ,Scalar(255,255,0) , 2, 8, 0);
    rectangle(world, r_goalarea_start , r_goalarea_finish , Scalar(255,255,255) , 2, 8, 0);
    rectangle(world, l_goalarea_start , l_goalarea_finish , Scalar(255,255,255) , 2, 8, 0);
}
//=================================
class robot : public base {

    private:

        Mat Arrow;
        double robot_size;
        double center_x, center_y;
        double rigth_x, rigth_y;
        double left_x, left_y;
        double main_x, main_y;
        double robot_angel;
        int rotation_speed,move_speed;

    public:

        void set_data();
        void robot_shape();
        double Radian(double);
        int display_robot_automatic();
        int display_robot_manual();
        int check_boudary();
};
//=================================
void robot :: set_data() {
    
    robot_size = base_size * 0.3 / 11;
    center_x = base_size * 5/10;
    center_y = base_size * 4/11;
    robot_angel = 1;
    rotation_speed = 0;
    move_speed = 0;
}
//=================================
void robot :: robot_shape() {

    //creat a Arrow as a robot
    world.copyTo(Arrow);

    //declaring center point
    Point center(center_x, center_y);

    //declaring main line of Arrow
    main_x = center_x + robot_size * cos(Radian(robot_angel));
    main_y = center_y + robot_size * sin(Radian(robot_angel));
    Point main(main_x, main_y);

    //declaring right point of Arrow
    rigth_x = center_x + robot_size * cos(Radian(robot_angel - 140));
    rigth_y = center_y + robot_size * sin(Radian(robot_angel - 140));
    Point rigth(rigth_x, rigth_y);

    //declaring left point of Arrow
    left_x = center_x + robot_size * cos(Radian(robot_angel + 140));
    left_y = center_y + robot_size * sin(Radian(robot_angel + 140));
    Point left(left_x, left_y);

    //creat main lines of Arrow
    line(Arrow, main,rigth, Scalar(0,0,240), 2, 8, 0);
    line(Arrow, left, main, Scalar(0,0,240), 2, 8, 0);
    
    //creat sub lines
    line(Arrow, center, left, Scalar(0,0,240), 2, 8, 0);
    line(Arrow, rigth, center, Scalar(0,0,240), 2, 8, 0);

    imshow("soccer feild",Arrow);
}
double robot ::  Radian(double angel)
{
    angel *= 0.0174533;
    return angel;
}
//=================================
int robot :: display_robot_automatic() {
    
    if(check_boudary()==0) {
        robot_shape();
        switch(waitKey(1)) {

            case 97 :{
                // change robot rotation
                rotation_speed--;
                break;
            }
            case 100 :{
                // change robot rotation
                rotation_speed++;
                break;
            }
            case 119 :{
                // change robot position
                move_speed++;

                break;
            }
            case 115 :{
                // change robot position
                move_speed--;
                break;
            }
            case 114 :{
                // reset case
                move_speed = 0;
                rotation_speed = 0;
                break;
            }
            case 113 :{
                // To quit the window
                destroyAllWindows();
                return 0;
                break;
            }
        }
        usleep(5000);
        if(move_speed<=0) {
            center_x -= 1 * -move_speed * cos(Radian(robot_angel));
            center_y -= 1 * -move_speed * sin(Radian(robot_angel));
        }
        else {
            center_x += 1 * move_speed * cos(Radian(robot_angel));
            center_y += 1 * move_speed * sin(Radian(robot_angel));
        }
        //====================
        if(rotation_speed<=0) {
            robot_angel += 1 * -rotation_speed;
        }
        else if(rotation_speed>0) {
            robot_angel -= 1 * rotation_speed;
        }
    }
   else {
        cout<<"\nMovement is out of feild !!\n";
    }
    display_robot_automatic();
    return 0;
}
//=================================
int robot :: display_robot_manual() {
    
    if(check_boudary()==0) {
        robot_shape();
        switch(waitKey(0)) {

            case 97 :{
                // change robot rotation
                robot_angel -= 3;
                break;
            }
            case 100 :{
                // change robot rotation
                robot_angel += 3;
                break;
            }
            case 119 :{
                // change robot position
                center_x += 5 * cos(Radian(robot_angel));
                center_y += 5 * sin(Radian(robot_angel));
                break;
            }
            case 115 :{
                // change robot position
                center_x -= 5 * cos(Radian(robot_angel));
                center_y -= 5 * sin(Radian(robot_angel));
                break;
            }
            case 113 :{
                // To quit the window
                return 0;
                break;
            }
            default : cout<<"\nWrong key try again\n";
            display_robot_manual();
        }
    }
   else {
        cout<<"\nMovement is out of feild !!\n";
    }
    display_robot_manual();
    return 0;
}
//=================================
int robot :: check_boudary() {

    if(center_x <= base_size * 1/11) {
        center_x += base_size * 0.01/22;
        return 1;
    }
    else if(center_y <= base_size * 1/11) {
        center_y += base_size * 0.01/22;
        return 1;
    }
    else if(center_x >= base_size * 10/11) {
        center_x -= base_size * 0.01/22;
        return 1;
    }
    else if(center_y >= base_size * 7/11) {
        center_y -= base_size * 0.01/22;
        return 1;
    }
    return 0;
}
//=================================
int main()
{
    robot r1;
    int mode;

    cout<<"1:manual mode\n2:automatic mode\n";cin>>mode;

    r1.set_feild_size();
    r1.set_data();

    if(mode == 1)
        r1.display_robot_manual();
    else 
        r1.display_robot_automatic();

    return 0;
}
