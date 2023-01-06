using Unit05.Game.Casting;
using System.Collections.Generic;
using Raylib_cs;
using System;


namespace Unit05.Game.Casting
{
    public class Bullet : Actor
    {
        List<Actor> liveRounds = new List<Actor>();
        public Bullet()
        {
        }

        public void AddPlayerBullet(Player player)
        {
            Bullet bullet = new Bullet();
            bullet.SetText(".");
            Point playerPosition = player.GetPosition();
            int playerX = playerPosition.GetX();
            int playerY = playerPosition.GetY();
            bullet.SetPosition(new Point((playerX + 15), playerY));
            bullet.SetVelocity(new Point(0, -15));
            bullet.SetColor(Constants.BLUE);
            liveRounds.Add(bullet);
        }

        public void AddAlienBullet(Actor alien)
        {
            Bullet bullet = new Bullet();
            bullet.SetText(".");
            Point alienPosition = alien.GetPosition();
            int alienX = alienPosition.GetX();
            int alienY = alienPosition.GetY();
            bullet.SetPosition(new Point((alienX + 15), alienY));
            bullet.SetVelocity(new Point(0, 15));
            bullet.SetColor(Constants.RED);
            liveRounds.Add(bullet);
        }

        public void RemoveBullet(List<Actor> roundList)
        {
            foreach (Actor round in roundList)
            {
                Point bulletPosition = round.GetPosition();
                if (bulletPosition.GetY() < 15)
                {
                    round.SetText("");
                }
            }

        }

        public List<Actor> GetLiveRounds()
        {
            return liveRounds;
        }
    }
}