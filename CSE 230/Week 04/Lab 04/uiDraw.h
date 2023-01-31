/***********************************************************************
 * Header File:
 *    User Interface Draw : put pixels on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This is the code necessary to draw on the screen. We have a collection
 *    of procedural functions here because each draw function does not
 *    retain state. In other words, they are verbs (functions), not nouns
 *    (variables) or a mixture (objects)
 ************************************************************************/

#pragma once

#include <string>     // To display text on the screen
#include <cmath>      // for M_PI, sin() and cos()
#include <algorithm>  // used for min() and max()
#include <sstream>    // for OSTRINGSTRING
#include "point.h"    // Where things are drawn
using std::string;
using std::min;
using std::max;


/*************************************************************************
 * GRAPHICS STREAM
 * A graphics stream that behaves much like COUT except on a drawn screen.
 * Special methods are added to facilitate drawing simulator elements.
 *************************************************************************/
class ogstream : public std::ostringstream
{
public:
   ogstream()                : pt()   {          }
   ogstream(const Point& pt) : pt(pt) {          }
   ~ogstream()                        { flush(); }
   
   // Methods specific to drawing text on the screen
   void flush();
   void setPosition(const Point& pt) { flush(); this->pt = pt; }
   ogstream& operator = (const Point& pt)
   {
      setPosition(pt);
      return *this;
   }
   
   // Methods specific to drawing simulator elements on the screen
   virtual void drawLander(      const Point& pt = Point(),
                                 double angle = 0.0);

   virtual void drawLanderFlames(const Point& pt = Point(),
                                 double angle = 0.0,
                                 bool bottom = false,
                                 bool left = false,
                                 bool right = false);

   virtual void drawStar(        const Point& pt = Point(),
                                 unsigned char phase = 0);

   virtual void drawRectangle(   const Point & begin,
                                 const Point & end,
                                 double red = 1.0,
                                 double green = 1.0,
                                 double blue = 1.0) const;

   virtual void drawLine(        const Point & begin,
                                 const Point & end,
                                 double red = 1.0,
                                 double green = 1.0,
                                 double blue = 1.0) const;
protected:
   Point pt;
   
private:
   Point rotate(const Point & origin, double x, double y,
                double rotation = 0.0) const;
   
   void drawText(const Point & topLeft, const char * text) const;

};

/******************************************************************
 * RANDOM
 * This function generates a random number.  The user specifies
 * The parameters 
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer
 ****************************************************************/
int    random(int    min, int    max);
double random(double min, double max);

