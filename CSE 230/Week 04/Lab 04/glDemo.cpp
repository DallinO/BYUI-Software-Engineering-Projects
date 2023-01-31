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
#include "physics.h"
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
          ptLM(ptUpperRight.getX() / 2.0, ptUpperRight.getY() - 50),
          preLM(ptUpperRight.getX() / 2.0, ptUpperRight.getY() - 50),
          ground(ptUpperRight),
          lm()
   { 
       for (int x = 0; x < 50; x++) {
           Point star(random(0, 400), random(0, 400));
           ptStar[x] = star;
       }
   }

   // this is just for test purposes.  Don't make member variables public!
   Point preLM;
   Point ptLM;           // location of the LM on the screen
   Point ptUpperRight;   // size of the screen
   double angle;         // angle the LM is pointing
   unsigned char phase;  // phase of the star's blinking
   Ground ground;
   Point ptStar[50];
   LM lm;
   Physics phy;
   int frame = 0;
   
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

   // move the ship around
   if (pUI->isRight())
      pDemo->angle -= 0.1;
      
   if (pUI->isLeft())
      pDemo->angle += 0.1;
      
   if (pUI->isRight()) {
       pDemo->ptLM.addX(1.0);
       pDemo->lm.burnRotateFuel();
   }
   if (pUI->isLeft()) {
       pDemo->ptLM.addX(-1.0);
       pDemo->lm.burnRotateFuel();
   }
   if (pUI->isUp()) {
       pDemo->ptLM.addY(1.0);
       pDemo->lm.burnFuel();
   }
   if (pUI->isDown()) {
       pDemo->ptLM.addY(-1.0);
   }
   // draw the ground
   pDemo->ground.draw(gout);

   // draw the lander and its flames
   gout.drawLander(pDemo->ptLM /*position*/, pDemo->angle /*angle*/);
   gout.drawLanderFlames(pDemo->ptLM, pDemo->angle, /*angle*/
                    pUI->isUp(), pUI->isLeft(), pUI->isRight());

   // put some text on the screen
   pDemo->phy.setPosDif(pDemo->preLM, pDemo->ptLM, pDemo->frame % 30);
   pDemo->phy.getSpeed(pDemo->frame % 30);
   gout.setPosition(Point(20.0, 370.0));
   gout << "Fuel: " << pDemo->lm.fuel << " lbs\n";
   gout << "Speed: " << pDemo->phy.speed << "\n";
   gout << "Altitude: " << (int)pDemo->ground.getElevation(pDemo->ptLM) << " meters\n";
   if (pDemo->frame % 30 == 29) {
       pDemo->preLM = pDemo->ptLM;
   }
   pDemo->frame++;
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
                "Open GL Demo", 
                 ptUpperRight);

   // Initialize the game class
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);             

   return 0;
}
