using System.Collections.Generic;
using Unit04.Game.Casting;
using Unit04.Game.Services;
using System;


namespace Unit04.Game.Directing
{
    /// <summary>
    /// <para>A person who directs the game.</para>
    /// <para>
    /// The responsibility of a Director is to control the sequence of play.
    /// </para>
    /// </summary>
    public class Director
    {
        private KeyboardService keyboardService = null;
        private VideoService videoService = null;
        Color color = new Color(0, 0, 0);
        Random random = new Random();
        int score = 0;
        bool gameover = false;

        /// <summary>
        /// Constructs a new instance of Director using the given KeyboardService and VideoService.
        /// </summary>
        /// <param name="keyboardService">The given KeyboardService.</param>
        /// <param name="videoService">The given VideoService.</param>
        public Director(KeyboardService keyboardService, VideoService videoService)
        {
            this.keyboardService = keyboardService;
            this.videoService = videoService;
        }

        /// <summary>
        /// Starts the game by running the main game loop for the given cast.
        /// </summary>
        /// <param name="cast">The given cast.</param>
        public void StartGame(Cast cast)
        {
            videoService.OpenWindow();
            while (videoService.IsWindowOpen())
            {
                GetInputs(cast);
                if (gameover == false)
                {
                    DoUpdates(cast);
                }
                DoOutputs(cast);
            }
            videoService.CloseWindow();
        }

        /// <summary>
        /// Gets directional input from the keyboard and applies it to the robot.
        /// </summary>
        /// <param name="cast">The given cast.</param>
        private void GetInputs(Cast cast)
        {
            Actor robot = cast.GetFirstActor("player");
            Point velocity = keyboardService.GetDirection();
            robot.SetVelocity(velocity);
        }

        /// <summary>
        /// Updates the robot's position and resolves any collisions with artifacts.
        /// </summary>
        /// <param name="cast">The given cast.</param>
        private void DoUpdates(Cast cast)
        {
            Actor banner = cast.GetFirstActor("banner");
            Actor robot = cast.GetFirstActor("player");
            List<Actor> actor = cast.GetActors("actor");
            Actor gameoverdisplay = cast.GetFirstActor("gameover");

            banner.SetText("POINTS: " + score);
            int maxX = videoService.GetWidth();
            int maxY = videoService.GetHeight();
            robot.MoveNext(maxX, maxY);
            foreach (Actor x in actor)
            {
                x.MoveNext(maxX, maxY);
                if (x.GetText() == "O")
                {
                    x.SetVelocity(new Point(0, 3));
                }
                if (x.GetText() == "*")
                {
                    x.SetVelocity(new Point(0, 5));
                }
            }

            foreach (Actor x in actor)
            {
                if (robot.GetPosition().Equals(x.GetPosition()))
                {
                    if (x.GetText() == "*")
                    {
                        score = score + 1;
                        x.SetText("");
                    }
                    if (x.GetText() == "O")
                    { 
                        gameoverdisplay.SetText("GAME OVER");
                        gameover = true;
                    }
                }
            }
        }

        /// <summary>
        /// Draws the actors on the screen.
        /// </summary>
        /// <param name="cast">The given cast.</param>
        public void DoOutputs(Cast cast)
        {
            List<Actor> actors = cast.GetAllActors();
            videoService.ClearBuffer();
            videoService.DrawActors(actors);
            videoService.FlushBuffer();
        }

    }
}