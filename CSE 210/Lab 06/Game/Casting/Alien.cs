using System.Collections.Generic;
using Raylib_cs;

namespace Unit05.Game.Casting
{
    public class Alien : Bullet
    {
        List<Actor> alienList = new List<Actor>();
        int alienAmount = 32;
        public Alien()
        {
            AddAliens();
        }

        private void AddAliens()
        {

            for (int i = 1; i <= 32; i++)
            {
                Actor alien = new Actor();
                if (i < 9)
                {
                    Point point = (new Point((i * 90) + Constants.CELL_SIZE, Constants.CELL_SIZE));
                    alien.SetPosition(point);
                    alien.SetText("<v>");
                    alien.SetColor(Constants.BLUE);
                }
                if (i > 8 && i < 17)
                {
                    Point point = (new Point(((i - 8) * 90) + Constants.CELL_SIZE, Constants.CELL_SIZE * 4));
                    alien.SetPosition(point);
                    alien.SetText("<v>");
                    alien.SetColor(Constants.GREEN);
                }
                if (i > 16 && i < 25)
                {
                    Point point = (new Point(((i - 16) * 90) + Constants.CELL_SIZE, Constants.CELL_SIZE * 8));
                    alien.SetPosition(point);
                    alien.SetText("<v>");
                    alien.SetColor(Constants.YELLOW);
                }
                if (i > 24)
                {
                    Point point = (new Point(((i - 24) * 90) + Constants.CELL_SIZE, Constants.CELL_SIZE * 12));
                    alien.SetPosition(point);
                    alien.SetText("<v>");
                    alien.SetColor(Constants.RED);
                }
                alienList.Add(alien);
            }

        }

        public List<Actor> GetAlienList()
        {
            return alienList;
        }

        public void SetAlienAmount(int input)
        {   
            alienAmount = alienAmount - input;
        }

        public override void MoveNext()
        {
            foreach (Actor alien in alienList)
            {
                alien.MoveNext();
            }
        }
    }
}