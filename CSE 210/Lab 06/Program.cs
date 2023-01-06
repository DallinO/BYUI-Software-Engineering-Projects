using Unit05.Game.Services;
using Unit05.Game.Directing;
using Unit05.Game.Casting;
using Unit05.Game.Scripting;
using System.Collections.Generic;
using Unit05.Game;



namespace Unit05
{
    /// <summary>
    /// The program's entry point.
    /// </summary>
    class Program
    {
        static void Main(string[] args)
        {
            Cast cast = new Cast();

            // Create player.
            cast.AddActor("Player", new Player());
            Player player = (Player)cast.GetFirstActor("Player");
            player.SetPosition(new Point(435, 570));
            player.SetColor(Constants.WHITE);
            player.SetText("<^>" );

            // Creat aliens.
            cast.AddActor("Aliens", new Alien());
            Alien aliens = (Alien)cast.GetFirstActor("Aliens");
            List<Actor> alienList = aliens.GetAlienList();
        
            // Create lives display.
            cast.AddActor("Lives", new Actor());
            Actor lives = cast.GetFirstActor("Lives");
            lives.SetPosition(new Point(795, 15));
            lives.SetColor(Constants.WHITE);

            // Create score.
            cast.AddActor("Score", new Score());
            Score score = (Score)cast.GetFirstActor("Score");
            score.SetPosition(new Point(15, 15));
            score.SetText("SCORE: 0");

            cast.AddActor("EndGame", new Actor());
            Actor end = cast.GetFirstActor("EndGame");
            end.SetPosition(new Point((Constants.MAX_X / 2) - 90, Constants.MAX_Y / 2));
            end.SetColor(Constants.RED);
            


            // Create bullet.
            cast.AddActor("Bullet", new Bullet());
            Bullet bullet = (Bullet)cast.GetFirstActor("Bullet");

            KeyboardService keyboardService = new KeyboardService();
            VideoService videoService = new VideoService(false);

            // Create scripts.
            Script script = new Script();
            script.AddAction("input", new ControlActorsAction(keyboardService, player));
            script.AddAction("update", new MoveActorsAction());
            script.AddAction("update", new UpdateLivesAction());
            script.AddAction("update", new UpdateScoreAction());
            script.AddAction("update", new HandleBulletCollision());
            script.AddAction("update", new FireBullet());
            script.AddAction("update", new HandleGameOver());
            script.AddAction("output", new DrawActorsAction(videoService));

            // Create Director and start game.
            Director director = new Director(videoService);
            director.StartGame(cast, script);
            
            
        }
    }
}