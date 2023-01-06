using System.Collections.Generic;
using Unit05.Game.Casting;
using Unit05.Game.Services;


namespace Unit05.Game.Scripting
{
    /// <summary>
    /// <para>An output action that draws all the actors.</para>
    /// <para>The responsibility of DrawActorsAction is to draw each of the actors.</para>
    /// </summary>
    public class DrawActorsAction : Operation
    {
        private VideoService videoService;

        /// <summary>
        /// Constructs a new instance of ControlActorsAction using the given KeyboardService.
        /// </summary>
        public DrawActorsAction(VideoService videoService)
        {
            this.videoService = videoService;
        }

        /// <inheritdoc/>
        public void Execute(Cast cast, Script script)
        {
            Player player = (Player)cast.GetFirstActor("Player");
            Bullet bullet = (Bullet)cast.GetFirstActor("Bullet");
            Alien aliens = (Alien)cast.GetFirstActor("Aliens");
            Actor lives = (Actor)cast.GetFirstActor("Lives");
            Actor score = (Actor)cast.GetFirstActor("Score");
            Actor end = cast.GetFirstActor("EndGame");
            List<Actor> liveRounds = bullet.GetLiveRounds();
            List<Actor> alienList = aliens.GetAlienList();

            videoService.ClearBuffer();
            bullet.RemoveBullet(liveRounds);
            videoService.DrawActor(player);
            videoService.DrawActors(liveRounds);
            videoService.DrawActors(alienList);
            videoService.DrawActor(score);
            videoService.DrawActor(end);
            videoService.DrawActor(lives);
            videoService.FlushBuffer();                                                                
        }
    } 
}