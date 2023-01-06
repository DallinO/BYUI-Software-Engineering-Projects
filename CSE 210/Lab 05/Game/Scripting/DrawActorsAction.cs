using System.Collections.Generic;
using Unit05.Game.Casting;
using Unit05.Game.Services;


namespace Unit05.Game.Scripting
{
    /// <summary>
    /// <para>An output action that draws all the actors.</para>
    /// <para>The responsibility of DrawActorsAction is to draw each of the actors.</para>
    /// </summary>
    public class DrawActorsAction : Action
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
            Bike user = (Bike)cast.GetFirstActor("user");
            List<Actor> user_segments = user.GetSegments();
            List<Actor> messages = cast.GetActors("gameover");
            Bike program = (Bike)cast.GetFirstActor("program");
            List<Actor> program_segments = program.GetSegments();

            videoService.ClearBuffer();
            videoService.DrawActors(user_segments);
            videoService.DrawActors(messages);
            videoService.DrawActors(program_segments);
            videoService.FlushBuffer();
        }
    }
}