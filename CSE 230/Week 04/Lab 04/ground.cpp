/***********************************************************************
 * Source File:
 *    Ground : Represents the ground in the lunar lander game
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Where the ground is located and where the landing pad is located
 ************************************************************************/

#include "ground.h"   // for the Ground class definition
#include "uiDraw.h"   // for random() and drawLine()
#include <cassert>

const int    LZ_SIZE = 30;
const double MAX_SLOPE = 2.7; // steapness of the features. Smaller number is flatter
const double LUMPINESS = 1.0; // size of the hills. Smaller number is bigger features
const double TEXTURE = 3.0;   // size of the small features such as rocks

 /************************************************************************
  * GROUND constructor
  * Create a new grond object
  ************************************************************************/
Ground::Ground(const Point & ptUpperRight) : ptUpperRight(ptUpperRight)
{
   assert(ptUpperRight.getX() > 0.0);
   assert(ptUpperRight.getY() > 0.0);

   // allocate the array
   ground = new double[(int)ptUpperRight.getX()];

   reset();
}

/************************************************************************
 * RESET
 * Create a new ground
 ************************************************************************/
 void Ground :: reset()
 {
   // determine the landing location
   iLZ = (int)random(ptUpperRight.getX() * 0.1, 
                     ptUpperRight.getX() * 0.9 - (double)LZ_SIZE);

   // give each location on the ground an elevation
   ground[0] = ptUpperRight.getY() / 4.0; // the initial elevation is in the middle.
   double dy = 0.0;         // the initial slope is heavily biased to up
   for (int i = 1; i < int(ptUpperRight.getX()); i++)
   {
      // if we are in the LZ, make the ground flat
      if (i >= iLZ && i < iLZ + LZ_SIZE)
      {
         // the landing zone (LZ) is flat
         ground[i] = ground[i - 1];
      }
      // otherwise, vary the slope
      else
      {
         // 0% is the bottom - favor sloping up to avoid the bottom
         // 100% is the top - favor sloping down to avoid the top
         double percent = ground[i - 1] / (ptUpperRight.getY() / 2.0) * 0.5;

         // dy is the slope. positive is up, negative is down
         dy += random(LUMPINESS * (0.25 - percent),
                      LUMPINESS * (0.75 - percent));

         // make sure the slop is not too steep
         if (dy > MAX_SLOPE)
            dy = MAX_SLOPE;
         if (dy < -MAX_SLOPE)
            dy = -MAX_SLOPE;

         // determine the elevation according to the slope
         ground[i] = ground[i - 1] + dy + random(-TEXTURE, TEXTURE);
      }
   }
}

/***********************************************************
 * HTI GROUND
 * Did the lander hit the ground?
 **********************************************************/
bool Ground::hitGround(const Point& position, int landerWidth) const
{
   // find the extent of the lander
   int xMin = (int)(position.getX() - (double)landerWidth / 2.0);
   int xMax = (int)(position.getX() + (double)landerWidth / 2.0);

   xMin = (xMin < 0 ? 0 : xMin);
   xMax = (xMax > (int)ptUpperRight.getX() - 1 ? (int)ptUpperRight.getX() - 1 :  xMax);

   double maxElevation = ground[xMin];
   for (int i = xMin + 1; i <= xMax; i++)
      if (ground[i] > maxElevation)
         maxElevation = ground[i];

   return position.getY() < maxElevation;
}

/************************************************************************
 * ON PLATFORM
 * Have we landed on the platform?
 ************************************************************************/
bool Ground :: onPlatform(const Point & position, int landerWidth) const
{
   // not on the platform if we are too high
   if (getElevation(position) > 1.0)
      return false;

   // not on the platform if we hit the ground
   if (getElevation(position) < 0.0)
      return false;

   // not on the platform if we are too far left
   if (position.getX() + landerWidth / 2.0 < (double)iLZ)
      return false;

   // not on the platform if we are too far right
   if (position.getX() - landerWidth / 2.0 > (double)(iLZ + LZ_SIZE))
      return false;

   return true;
}

/*****************************************************************
 * DRAW
 * Draw the ground on the screen
 ****************************************************************/
void Ground::draw(ogstream & gout) const
{
   // iterate through the entire ground and draw it all
   for (int i = 0; i < (int)ptUpperRight.getX(); i++)
      gout.drawRectangle(Point((double)i, 0.0), 
                         Point((double)(i + 1), ground[i]), 
                         0.3 /*red*/, 0.2 /*green*/, 0.1 /*blue*/);

   // draw the landing pad
   gout.drawRectangle(Point((double)iLZ, ground[iLZ]),
                      Point((double)(iLZ + LZ_SIZE), ground[iLZ] - 2.0),
                      0.0 /*red*/, 0.0 /*green*/, 1.0 /*blue*/);

}
