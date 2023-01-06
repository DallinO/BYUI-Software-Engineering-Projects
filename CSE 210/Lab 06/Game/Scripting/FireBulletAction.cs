using Unit05.Game.Scripting;
using Unit05.Game.Casting;
using System.Collections.Generic;
using Raylib_cs;
using System;

namespace Unit05.Game.Scripting
{
    public class FireBullet : Operation
    {
        Random rnd = new Random();
        int iteration = 30;
        public FireBullet()
        {
        }
        public void Execute(Cast cast, Script script)
        {
            Alien aliens = (Alien)cast.GetFirstActor("Aliens");
            List<Actor> alienList = aliens.GetAlienList();
            Bullet bullet = (Bullet)cast.GetFirstActor("Bullet");
            Player player = (Player)cast.GetFirstActor("Player");
            int modulus = iteration % 30;
            

            foreach (Actor alien in alienList)
            {

                if (rnd.Next(300) == 0)
                {
                    bullet.AddAlienBullet(alien);
                }
            }

            if (modulus == 0)
            {
                bullet.AddPlayerBullet(player);
            }

            iteration++;
        }
    }
}