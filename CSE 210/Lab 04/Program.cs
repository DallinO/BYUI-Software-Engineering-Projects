using System;
using Unit04.Game.Casting;
using Unit04.Game.Directing;
using Unit04.Game.Services;


namespace Unit04
{
    /// <summary>
    /// The program's entry point.
    /// </summary>
    class Program
    {
        private static int FRAME_RATE = 30;
        private static int MAX_X = 900;
        private static int MAX_Y = 600;
        private static int CELL_SIZE = 15;
        private static int FONT_SIZE = 15;
        private static int COLS = 60;
        private static int ROWS = 40;
        private static string CAPTION = "Greed";
        private static Color WHITE = new Color(255, 255, 255);


        /// <summary>
        /// Starts the program using the given arguments.
        /// </summary>
        /// <param name="args">The given arguments.</param>
        static void Main(string[] args)
        {
            // create the cast
            Cast cast = new Cast();

            // create the banner
            Actor banner = new Actor();
            banner.SetText("");
            banner.SetFontSize(FONT_SIZE);
            banner.SetColor(WHITE);
            banner.SetPosition(new Point(CELL_SIZE, 0));
            cast.AddActor("banner", banner);

            Actor gameover = new Actor();
            gameover.SetText("");
            gameover.SetFontSize(FONT_SIZE);
            gameover.SetColor(new Color(255, 133, 133));
            gameover.SetPosition(new Point((MAX_X / 2 - 50), MAX_Y / 2));
            cast.AddActor("gameover", gameover);


            // create the player
            Actor player = new Actor();
            player.SetText("#");
            player.SetFontSize(FONT_SIZE);
            player.SetColor(WHITE);
            player.SetPosition(new Point(MAX_X / 2, 585));
            cast.AddActor("player", player);

            // create the Actors
            Random random = new Random();
            for (int i = 0; i < 70; i++)
            {
                int x = random.Next(1, COLS);
                int y = random.Next(1, ROWS);
                Point position = new Point(x, y);
                position = position.Scale(CELL_SIZE);

                int r = random.Next(0, 256);
                int g = random.Next(0, 256);
                int b = random.Next(0, 256);
                Color color = new Color(r, g, b);
                string text = "";

                Actor actor = new Actor();
                if (i < 25)
                {
                    text = "*";
                    actor.SetColor(color);
                    
                }
                if (i >= 25)
                {
                    text = "O";
                    actor.SetColor(WHITE);
                }
                
                actor.SetText(text);
                actor.SetFontSize(FONT_SIZE);
                actor.SetPosition(position);
                cast.AddActor("actor", actor);
            }

            // start the game
            KeyboardService keyboardService = new KeyboardService(CELL_SIZE);
            VideoService videoService 
                = new VideoService(CAPTION, MAX_X, MAX_Y, CELL_SIZE, FRAME_RATE, false);
            Director director = new Director(keyboardService, videoService);
            director.StartGame(cast);
        }
    }
}