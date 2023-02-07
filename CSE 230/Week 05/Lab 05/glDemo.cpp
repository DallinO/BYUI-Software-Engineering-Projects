/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "lm.h"

#define LM_WIDTH	20.0

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(const Point& ptUpperRight) :
          angle(0.0),
          ptStar(),
          ground(ptUpperRight),
          lm(ptUpperRight.getY() - 50, ptUpperRight.getX()/ 2, 0, 0, angle)
   { 
       for (int x = 0; x < 50; x++) {
           Point star(random(0, 400), random(0, 400));
           ptStar[x] = star;
       }
   }

   // this is just for test purposes.  Don't make member variables public!        
   Point ptUpperRight;   // size of the screen
   double angle;         // angle the LM is pointing
   unsigned char phase;  // phase of the star's blinking
   Ground ground;
   Point ptStar[50];
   LM lm;
   bool x = true;
   
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void * p)
{
   ogstream gout;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo * pDemo = (Demo *)p;  

   // draw our little star
   for (int x = 0; x < 50; x++) {
       pDemo->phase = random(0, 255);
       gout.drawStar(pDemo->ptStar[x], pDemo->phase++);
   }

   if (pDemo->x == true)
   {
       // move the ship around
       if (pUI->isLeft()) {
           pDemo->lm.angle += 0.1;
           pDemo->lm.burnRotateFuel();
       }
       if (pUI->isRight()) {
           pDemo->lm.angle -= 0.1;
           pDemo->lm.burnRotateFuel();
       }
       if (pUI->isUp()) {
           pDemo->lm.applyThrust();
       }

       pDemo->lm.applyGravity();
       pDemo->lm.applyInertia();
   }   
   // draw the ground
    pDemo->ground.draw(gout);

    // draw the lm and its flames
    gout.drawLander(Point(pDemo->lm.x, pDemo->lm.y) /*position*/, pDemo->lm.angle /*angle*/);
    gout.drawLanderFlames(Point(pDemo->lm.x, pDemo->lm.y), pDemo->lm.angle, /*angle*/
        pUI->isUp(), pUI->isLeft(), pUI->isRight());
   

   // put some text on the screen
   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(2);
   gout.setPosition(Point(20.0, 370.0));
   gout << "lm: " << pDemo->lm.fuel << " lbs\n";
   gout << "Speed: " << pDemo->lm.totalVelocity()<< " m/s\n";
   gout << "Altitude: " << (int)pDemo->ground.getElevation(Point(pDemo->lm.x, pDemo->lm.y)) << " meters\n";
   // 
   if (pDemo->ground.hitGround(Point(pDemo->lm.x, pDemo->lm.y), LM_WIDTH)) {
       gout.setPosition(Point(200, 200));
       gout << "Crash!" << endl;
       pDemo->x = false;

   }
   if (pDemo->ground.onPlatform(Point(pDemo->lm.x, pDemo->lm.y), LM_WIDTH)) {
       gout.setPosition(Point(130, 200));
       gout << "The Eagle has landed!" << endl;
       pDemo->x = false;
   }
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance, 
   _In_opt_ HINSTANCE hPrevInstance, 
   _In_ PWSTR pCmdLine, 
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char ** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Point ptUpperRight(400.0, 400.0);
   Interface ui(0, NULL, 
                "Lab 05", 
                 ptUpperRight);
   // Initialize the game class
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);             

   return 0;
}
