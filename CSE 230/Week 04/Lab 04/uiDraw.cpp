/***********************************************************************
 * Source File:
 *    User Interface Draw : put pixels on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This is the code necessary to draw on the screen. We have a collection
 *    of procedural functions here because each draw function does not
 *    retain state. In other words, they are verbs (functions), not nouns
 *    (variables) or a mixture (objects)
 ************************************************************************/

#include <string>     // need you ask?
#include <sstream>    // convert an integer into text
#include <cassert>    // I feel the need... the need for asserts
#include <time.h>     // for clock


#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_18
#endif // __APPLE__

#ifdef __linux__
#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // __linux__

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>         // OpenGL library we copied 
#define _USE_MATH_DEFINES
#include <math.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // _WIN32

#include "point.h"
#include "uiDraw.h"

using namespace std;

#define deg2rad(value) ((M_PI / 180) * (value))

/********************************************************
 * PT
 * Ultra-simple point used to draw shapes
 ********************************************************/
struct PT
{
   int x;
   int y;
};

/*************************************************************************
 * GL VERTEXT POINT
 * Just a more convenient format of glVertext2f
 *************************************************************************/
inline void glVertexPoint(const Point& point)
{
   glVertex2f((GLfloat)point.getX(), (GLfloat)point.getY());
}

/*************************************************************************
 * DISPLAY the text in the buffer on the screen
 *************************************************************************/
void ogstream::flush()
{
   string sOut;
   string sIn = str();

   // copy everything but the newlines
   for (string::iterator it = sIn.begin(); it != sIn.end(); ++it)
      // newline triggers an buffer flush and a move down
      if (*it == '\n')
      {
         drawText(pt, sOut.c_str());
         sOut.clear();
         pt.addY(-18);
      }
   // othewise append
      else
         sOut += *it;

   // put the text on the screen
   if (!sOut.empty())
   {
      drawText(pt, sOut.c_str());
      pt.addY(-18);
   }

   // reset the buffer
   str("");
}

/*************************************************************************
 * DRAW TEXT
 * Draw text using a simple bitmap font
 *   INPUT  topLeft   The top left corner of the text
 *          text      The text to be displayed
 ************************************************************************/
void ogstream::drawText(const Point& topLeft, const char* text) const
{
   void* pFont = GLUT_TEXT;

   // prepare to draw the text from the top-left corner
   glRasterPos2f((GLfloat)topLeft.getX(), (GLfloat)topLeft.getY());

   // loop through the text
   for (const char* p = text; *p; p++)
      glutBitmapCharacter(pFont, *p);
}

/************************************************************************
 * DRAW STAR
 * Draw a star that twinkles
 *   INPUT  POINT     The position of the beginning of the star
 *          PHASE     The phase of the twinkling
 *************************************************************************/
void ogstream::drawStar(const Point& point, unsigned char phase)
{
   // use the current point if the default parameter is used
   if (point != Point())
      *this = point;

   // Get ready...

   // most of the time, it is just a pale yellow dot
   if (phase < 128)
   {
      glBegin(GL_POINTS);
      glColor3f((GLfloat)0.5 /* red % */, (GLfloat)0.5 /* green % */, (GLfloat)0.0 /* blue % */);
      glVertex2f((GLfloat)(pt.getX() + 0.0), (GLfloat)(pt.getY() + 0.0));
   }
   // transitions to a bright yellow dot
   else if (phase < 160 || phase > 224)
   {
      glBegin(GL_POINTS);
      glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)0.0 /* blue % */);
      glVertex2f((GLfloat)(pt.getX() + 0.0), (GLfloat)(pt.getY() + 0.0));
   }
   // transitions to a bright yellow dot with pale yellow corners
   else if (phase < 176 || phase > 208)
   {
      glBegin(GL_LINES);
      glColor3f((GLfloat)0.5 /* red % */, (GLfloat)0.5 /* green % */, (GLfloat)0.0 /* blue % */);
      glVertex2f((GLfloat)(pt.getX() + 1.0), (GLfloat)(pt.getY() + 0.0));
      glVertex2f((GLfloat)(pt.getX() - 1.0), (GLfloat)(pt.getY() + 0.0));
      glVertex2f((GLfloat)(pt.getX() + 0.0), (GLfloat)(pt.getY() + 1.0));
      glVertex2f((GLfloat)(pt.getX() + 0.0), (GLfloat)(pt.getY() - 1.0));
      glEnd();

      glBegin(GL_POINTS);
      glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)0.0 /* blue % */);
      glVertex2f((GLfloat)(pt.getX() + 0.0), (GLfloat)(pt.getY() + 0.0));
   }
   // the biggest yet
   else
   {
      glBegin(GL_LINES);
      glColor3f((GLfloat)0.5 /* red % */, (GLfloat)0.5 /* green % */, (GLfloat)0.0 /* blue % */);
      glVertex2f((GLfloat)(pt.getX() + 2.0), (GLfloat)(pt.getY() + 0.0));
      glVertex2f((GLfloat)(pt.getX() - 2.0), (GLfloat)(pt.getY() + 0.0));
      glVertex2f((GLfloat)(pt.getX() + 0.0), (GLfloat)(pt.getY() + 2.0));
      glVertex2f((GLfloat)(pt.getX() + 0.0), (GLfloat)(pt.getY() - 2.0));
      glEnd();

      glBegin(GL_LINES);
      glColor3f((GLfloat)0.7 /* red % */, (GLfloat)0.7 /* green % */, (GLfloat)0.0 /* blue % */);
      glVertex2f((GLfloat)(pt.getX() + 1.0), (GLfloat)(pt.getY() + 0.0));
      glVertex2f((GLfloat)(pt.getX() - 1.0), (GLfloat)(pt.getY() + 0.0));
      glVertex2f((GLfloat)(pt.getX() + 0.0), (GLfloat)(pt.getY() + 1.0));
      glVertex2f((GLfloat)(pt.getX() + 0.0), (GLfloat)(pt.getY() - 1.0));
      glEnd();

      glBegin(GL_POINTS);
      glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)0.0 /* blue % */);
      glVertex2f((GLfloat)(pt.getX() + 0.0), (GLfloat)(pt.getY() + 0.0));
   }

   // Complete drawing
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
}

/************************************************************************
 * DRAW LINE
 * Draw a line on the screen from the beginning to the end.
 *   INPUT  begin     The position of the beginning of the line
 *          end       The position of the end of the line
 *************************************************************************/
void ogstream::drawLine(const Point& begin, const Point& end,
   double red, double green, double blue) const
{
   // Get ready...
   glBegin(GL_LINES);
   glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);

   // Draw the actual line
   glVertexPoint(begin);
   glVertexPoint(end);

   // Complete drawing
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
}

/************************************************************************
 * DRAW RECTANGLE
 * Draw a rectangle on the screen from the beginning to the end.
 *   INPUT  begin     The position of the beginning of the rectangle
 *          end       The position of the end of the rectangle
 *************************************************************************/
void ogstream::drawRectangle(const Point& begin, const Point& end,
   double red, double green, double blue) const
{
   // Get ready...
   glBegin(GL_QUADS);
   glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);

   // Draw the actual line
   glVertex2f((GLfloat)begin.getX(), (GLfloat)begin.getY());
   glVertex2f((GLfloat)begin.getX(), (GLfloat)end.getY());
   glVertex2f((GLfloat)end.getX(), (GLfloat)end.getY());
   glVertex2f((GLfloat)end.getX(), (GLfloat)begin.getY());

   // Complete drawing
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
}

/***********************************************************************
 * DRAW Lander
 * Draw a moon-lander spaceship on the screen at a given point
 ***********************************************************************/
void ogstream::drawLander(const Point& point, double angle)
{
   // use the current point if the default parameter is used
   if (point != Point())
      *this = point;

   //
   // Landing legs
   //
   glBegin(GL_LINE_STRIP);
   PT ptsLegs[] =
   {
      {-10,0}, {-6,0}, {-9,1}, {-9,8}, {-5,3}, {-9,8}, {-5,6},
      {5,6},   {9,8},  {5,3},  {9,8},  {9,1},  {6,0},  {10,0}
   };
   glColor3f((GLfloat)1.0, (GLfloat)1.0, (GLfloat)1.0);
   for (int i = 0; i < sizeof(ptsLegs) / sizeof(PT); i++)
      glVertexPoint(rotate(pt, ptsLegs[i].x, ptsLegs[i].y, angle));
   glEnd();

   //
   // Habitat module
   //

   // gold engine unit
   glBegin(GL_QUADS);
   glColor3f((GLfloat)0.8, (GLfloat)0.8, (GLfloat)0.0);
   glVertexPoint(rotate(pt, -5, 3, angle));
   glVertexPoint(rotate(pt, -5, 7, angle));
   glVertexPoint(rotate(pt, 5, 7, angle));
   glVertexPoint(rotate(pt, 5, 3, angle));

   // engine
   glColor3f((GLfloat)0.4, (GLfloat)0.4, (GLfloat)0.4);
   glVertexPoint(rotate(pt, -4, 1, angle));
   glVertexPoint(rotate(pt, -2, 3, angle));
   glVertexPoint(rotate(pt, 2, 3, angle));
   glVertexPoint(rotate(pt, 4, 1, angle));

   // horizontal thrusters
   glVertexPoint(rotate(pt, -8, 12, angle));
   glVertexPoint(rotate(pt, -8, 11, angle));
   glVertexPoint(rotate(pt, 8, 11, angle));
   glVertexPoint(rotate(pt, 9, 12, angle));
   glEnd();

   // main habitat
   glBegin(GL_TRIANGLE_FAN);
   PT ptsCenter[] =
   {
      {0,10},
      {3,7}, {-3, 7}, {-5,9}, {-5,12}, {-3, 16},
      {3,16}, {5,12}, {5,9}, {3,7}
   };
   glColor3f((GLfloat)0.7, (GLfloat)0.7, (GLfloat)0.7);
   for (int i = 0; i < sizeof(ptsCenter) / sizeof(PT); i++)
      glVertexPoint(rotate(pt, ptsCenter[i].x, ptsCenter[i].y, angle));
   glEnd();

   // window
   glBegin(GL_TRIANGLES);
   glColor3f((GLfloat)0.2, (GLfloat)0.2, (GLfloat)0.2);
   glVertexPoint(rotate(pt, 3, 15, angle));
   glVertexPoint(rotate(pt, 4, 11, angle));
   glVertexPoint(rotate(pt, 0, 12, angle));
   glEnd();

   // storage units
   glColor3f((GLfloat)0.92, (GLfloat)0.92, (GLfloat)0.92);
   glBegin(GL_QUADS);
   glVertexPoint(rotate(pt, -1, 7, angle));
   glVertexPoint(rotate(pt, -5, 10, angle));
   glVertexPoint(rotate(pt, -5, 12, angle));
   glVertexPoint(rotate(pt, -1, 12, angle));
   glEnd();

   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
}

/***********************************************************************
 * DRAW Lander Flame
 * Draw the flames coming out of a moonlander for thrust
 ***********************************************************************/
void ogstream::drawLanderFlames(const Point& point, double angle,
   bool bottom,
   bool clockwise,
   bool counterClockwise)
{
   // use the current point if the default parameter is used
   if (point != Point())
      *this = point;

   // bottom thrust
   if (bottom)
   {
      glBegin(GL_TRIANGLES);
      glColor3f(1.0 /* red % */, 0.0 /* green % */, 0.0 /* blue % */);
      glVertexPoint(rotate(pt, -3, 1, angle));
      glVertexPoint(rotate(pt, random(-5.0, 5.0), random(-15.0, -5.0), angle));
      glVertexPoint(rotate(pt, 3, 1, angle));
      glVertexPoint(rotate(pt, -3, 1, angle));
      glVertexPoint(rotate(pt, random(-5.0, 5.0), random(-15.0, -5.0), angle));
      glVertexPoint(rotate(pt, 3, 1, angle));
      glEnd();
   }

   // right thrust
   if (counterClockwise)
   {
      glBegin(GL_LINES);
      glColor3f(1.0 /* red % */, 0.0 /* green % */, 0.0 /* blue % */);
      glVertexPoint(rotate(pt, 6, 12, angle));
      glVertexPoint(rotate(pt, random(6.0, 8.0), random(15.0, 18.0), angle));
      glVertexPoint(rotate(pt, 8, 12, angle));
      glVertexPoint(rotate(pt, -6, 11, angle));
      glVertexPoint(rotate(pt, random(-8.0, -6.0), random(7.0, 10.0), angle));
      glVertexPoint(rotate(pt, -8, 11, angle));
      glEnd();
   }

   // left thrust
   if (clockwise)
   {
      glBegin(GL_LINES);
      glColor3f(1.0 /* red % */, 0.0 /* green % */, 0.0 /* blue % */);
      glVertexPoint(rotate(pt, 6, 11, angle));
      glVertexPoint(rotate(pt, random(6.0, 8.0), random(7.0, 10.0), angle));
      glVertexPoint(rotate(pt, 8, 11, angle));
      glVertexPoint(rotate(pt, -6, 12, angle));
      glVertexPoint(rotate(pt, random(-8.0, -6.0), random(15.0, 18.0), angle));
      glVertexPoint(rotate(pt, -8, 12, angle));
      glEnd();
   }

   // reset the color back to white when done
   if (bottom || clockwise || counterClockwise)
      glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
}

/************************************************************************
 * ROTATE
 * Rotate a given point (point) around a given origin (center) by a given
 * number of degrees (angle).
 *    INPUT  origin   The center point we will rotate around
 *           x,y      Offset from center that we will be rotating
 *           rotation Rotation in degrees
 *    OUTPUT point    The new position
 *************************************************************************/
Point ogstream::rotate(const Point& origin,
   double x, double y, double rotation) const
{
   // the only element that rotates is the lunar landar
   // and it has the center of rotation at (0, 8)

   y -= 8;
   // because sine and cosine are expensive, we want to call them only once
   double cosA = cos(rotation);
   double sinA = sin(rotation);

   // start with our original point
   Point ptReturn(origin);

   // find the new values
   ptReturn.addX(x * cosA - y * sinA);
   ptReturn.addY(y * cosA + x * sinA + 8 /*center of rotation*/);

   return ptReturn;
}

/******************************************************************
 * RANDOM
 * This function generates a random number.
 *
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer
 ****************************************************************/
int random(int min, int max)
{
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);

   return num;
}

/******************************************************************
 * RANDOM
 * This function generates a random number.
 *
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the double
 ****************************************************************/
double random(double min, double max)
{
   assert(min <= max);
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));

   assert(min <= num && num <= max);

   return num;
}
