using System.Collections.Generic;
using Unit05.Game.Casting;
using Unit05.Game.Scripting;
using System;


namespace Unit05.Game.Scripting
{
    /// <summary>
    /// <para>An update action that moves all the actors.</para>
    /// <para>
    /// The responsibility of MoveActorsAction is to move all the actors.
    /// </para>
    /// </summary>
    public class HandleBulletCollision : Operation
    {
        List<Actor> removeAliens = new List<Actor>();
        List<Actor> removeBullets = new List<Actor>();
        public HandleBulletCollision()
        {
        }

        /// <inheritdoc/>
        public void Execute(Cast cast, Script script)
        {
            Player player = (Player)cast.GetFirstActor("Player");
            Point playerPosition = player.GetPosition();
            Bullet bullet = (Bullet)cast.GetFirstActor("Bullet");
            List<Actor> liveRounds = bullet.GetLiveRounds();
            Alien aliens = (Alien)cast.GetFirstActor("Aliens");
            List<Actor> alienList = aliens.GetAlienList();
            Score score = (Score)cast.GetFirstActor("Score");

            foreach (Actor alien in alienList)
            {
                foreach (Actor round in liveRounds)
                {
                    Color bulletType = round.GetColor();
                    Point alienPosition = alien.GetPosition();
                    int apx = alienPosition.GetX();
                    int apy = alienPosition.GetY();

                    Point roundPosition = round.GetPosition();
                    int rpx = roundPosition.GetX();
                    int rpy = roundPosition.GetY();

                    if ((rpx >= apx && rpx <= apx + 30) && (rpy >= apy && rpy <= apy) && bulletType == Constants.BLUE)
                    {
                        removeAliens.Add(alien);
                        removeBullets.Add(round);
                        score.AddPoint(100);
                    }

                    if (rpy > 585 || rpy < 15)
                    {
                        removeBullets.Add(round);
                    }
                }
            }

            foreach (Actor round in liveRounds)
            {
                Color bulletType = round.GetColor();
                Point roundPosition = round.GetPosition();
                int rpx = roundPosition.GetX();
                int rpy = roundPosition.GetY();
                int ppx = playerPosition.GetX();
                int ppy = playerPosition.GetY();

                if ((rpx >= ppx && rpx <= ppx + 30) && (rpy >= ppy && rpy <= ppy + 15) && bulletType == Constants.RED)
                {
                    player.SetLives(1);
                    removeBullets.Add(round);
                }
            }


            foreach (Actor alien in removeAliens)
            {
                alienList.Remove(alien);
                aliens.SetAlienAmount(1);
            }
            foreach (Actor round in removeBullets)
            {
                liveRounds.Remove(round);
            }

        }
    }
}