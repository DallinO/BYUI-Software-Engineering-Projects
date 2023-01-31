/***********************************************************************
 * Header File:
 *    Ground : Represents the ground in the lunar lander game
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Where the ground is located and where the landing pad is located
 ************************************************************************/

#pragma once

#include "point.h"   // for Point
#include "uiDraw.h"  // for ogstream


 /***********************************************************
  * GROUND
  * The ground class
  ***********************************************************/
class Ground
{
public:
   // the constructor generates the ground
   Ground(const Point & ptUpperRight);

   // reset the game
   void reset();

   // draw the ground on the screen
   void draw(ogstream & gout) const;

   // determine how high the Point is off the ground
   double getElevation(const Point & pt) const
   {
      if (pt.getX() >= 0.0 && pt.getX() < ptUpperRight.getX())
         return pt.getY() - ground[(int)pt.getX()];
      else
         return 0.0;
   }

   // on the platform
   bool onPlatform(const Point & position, int landerWidth) const;

   // hit the ground
   bool hitGround(const Point& position, int landerWidth) const;

private:
   double * ground;               // the ground array, expressed in elevation 
   int    iLZ;                    // the left-most location of the landing zone (LZ)
   Point ptUpperRight;            // the width and height of the world
};
