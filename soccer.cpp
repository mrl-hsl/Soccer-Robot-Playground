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
