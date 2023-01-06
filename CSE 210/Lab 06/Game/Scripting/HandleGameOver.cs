using System.Collections.Generic;
using Unit05.Game.Casting;
using Unit05.Game.Services;
using System.Linq;


namespace Unit05.Game.Scripting
{
    public class HandleGameOver : Operation
    {
        public HandleGameOver()
        {
        }

        public void Execute(Cast cast, Script script)
        {
            // Create objects.
            Player player = (Player)cast.GetFirstActor("Player");
            Bullet bullet = (Bullet)cast.GetFirstActor("Bullet");
            Actor end = cast.GetFirstActor("EndGame");
            Alien aliens = (Alien)cast.GetFirstActor("Aliens");

            // Pull data from objects
            List<Operation> actions = script.GetActions("update");
            List<Actor> alienList = aliens.GetAlienList();
            List<Actor> liveRounds = bullet.GetLiveRounds();

            // Create local variables.
            bool isEmpty = !alienList.Any();
            int lives = player.GetLives();

            if (lives == 0)
            {
                end.SetText("GAME OVER!");
                script.RemoveAction("update");
                player.SetColor(Constants.WHITE);
                foreach (Actor _alien_ in alienList)
                {
                    _alien_.SetColor(Constants.WHITE);
                }
                foreach (Actor round in liveRounds)
                {
                    round.SetText("");
                }
            }

            foreach (Actor alien in alienList)
            {
                Point alienPosition = alien.GetPosition();
                int alienY = alienPosition.GetY();

                if (alienY >= 570)
                {
                    end.SetText("GAME OVER!");
                    script.RemoveAction("update");
                    player.SetColor(Constants.WHITE);
                    foreach (Actor _alien_ in alienList)
                    {
                        _alien_.SetColor(Constants.WHITE);
                    }
                    foreach (Actor round in liveRounds)
                    {
                        round.SetText("");
                    }

                    break;

                }
            }

            if (isEmpty)
            {
                end.SetText("GAME OVER!");
                script.RemoveAction("update");
                foreach (Actor round in liveRounds)
                {
                    round.SetText("");
                }
                player.SetColor(Constants.WHITE);
            }
        }
    }
}