using System.Collections.Generic;
using Raylib_cs;

namespace Unit05.Game.Casting
{
    public class Score : Actor
    {
        int points = 0;
        public Score()
        {
        }

        public void AddPoint(int point)
        {
            points = points + point;
        }

        public int GetScore()
        {
            return points;
        }

    }

}