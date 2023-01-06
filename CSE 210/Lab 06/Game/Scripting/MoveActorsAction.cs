using System.Collections.Generic;
using Unit05.Game.Casting;
using Unit05.Game.Services;
using System;
using Raylib_cs;


namespace Unit05.Game.Scripting
{
    /// <summary>
    /// <para>An update action that moves all the actors.</para>
    /// <para>
    /// The responsibility of MoveActorsAction is to move all the actors.
    /// </para>
    /// </summary>
    public class MoveActorsAction : Operation
    {
        /// <summary>
        /// Constructs a new instance of MoveActorsAction.
        /// </summary>
        public MoveActorsAction()
        {
        }

        /// <inheritdoc/>
        public void Execute(Cast cast, Script script)
        {
            List<Actor> actors = cast.GetAllActors();
            Bullet bullet = (Bullet)cast.GetFirstActor("Bullet");
            List<Actor> liveRounds = bullet.GetLiveRounds();
            Alien aliens = (Alien)cast.GetFirstActor("Aliens");
            List<Actor> alienList = aliens.GetAlienList();
            foreach (Actor actor in actors)
            {
                actor.MoveNext();
            }
            foreach (Actor round in liveRounds)
            {
                round.MoveNext();
            }
            foreach (Actor alien in alienList)
            {
                double elapsedTime = Math.Round(Raylib.GetTime(), 1);
                if (elapsedTime % 2 == 0)
                {
                    alien.MoveNext();
                }
                
            }
        }
    }
}