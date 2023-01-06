using System.Collections.Generic;
using Unit05.Game.Casting;
using Unit05.Game.Services;


namespace Unit05.Game.Casting
{
    // Holds the data related to ending the game.
    public class GameOver : Actor
    {
        bool isGameOver = false;
        public GameOver()
        {
        }
        
        public void DoGameOver(Cast cast)
        {
            if (isGameOver == true)
            {
                Bike user = (Bike)cast.GetFirstActor("user");
                Bike program = (Bike)cast.GetFirstActor("program");
                List<Actor> user_segments = user.GetSegments();
                List<Actor> program_segments = program.GetSegments();

                // create a "game over" message
                int x = (Constants.MAX_X / 2) - 30;
                int y = Constants.MAX_Y / 2;
                Point position = new Point(x, y);

                this.SetText("Game Over!");
                this.SetPosition(position);
                this.SetColor(Constants.RED);

                // make everything white
                foreach (Actor segment in user_segments)
                {
                    segment.SetColor(Constants.WHITE);
                }
                foreach (Actor segment in program_segments)
                {
                    segment.SetColor(Constants.WHITE);
                }
            }
        }

        // Return the status of the game.
        public bool GetGameOverStatus()
        {
            return isGameOver;
        }

        // Set the status of the game.
        public void SetGameOverStatus(bool status)
        {
            isGameOver = status;
        }
    }
}