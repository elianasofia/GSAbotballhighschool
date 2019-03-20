#include <kipr/botball.h>

const int right = 0;
const int left = 1;
int timer = 0; // timer used for first half of first line

int main()
{
    mav(right, 1800); //push fireman to fire station
    mav(left, 2390);
    msleep(6400);
    mav(right, -1000); //leaves out of the fire station
    mav(left, -1190);
    msleep(900); 
    mav(right, 1500); // turns to face the black and silver tape
    mav(left, -1720);
    msleep(1200);
    mav(right, 4500); // drive toward the black ans silver tape
    mav(left, 4680);
    msleep(5500);
    mav(right, 1500); // lines up with the tape
    mav(left, -1610);
    msleep(1000);
    while(timer<=8000){
        msleep(100);
        timer=timer+100;
        if(analog(0)>=2000 && analog(1)>=3000)	// B S keep straight we're in the right place
        {
            mav(right, 1000);
            mav(left, 1000);
        }
        else if(analog(0)<=2000)	// left W, turn R back to the line  
        {
            mav(right, 1000);
            mav(left, 500);
        }else if (analog(1)<=2000)	//right W, turn L back to the line 
        {
            mav(right, 500);
            mav(left, 1000);		 
        }
    }
    mav(right, 2000);
    mav(left, -2000);
    msleep(1000);
    mav(right, 3500);
    mav(left, 3500);
    msleep(2000);
    return 0;
}
