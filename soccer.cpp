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
