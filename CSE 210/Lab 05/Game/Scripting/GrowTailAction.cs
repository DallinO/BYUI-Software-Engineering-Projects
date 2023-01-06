using System.Collections.Generic;
using Unit05.Game.Casting;
using Unit05.Game.Services;


namespace Unit05.Game.Scripting
{
    /// <summary>
    /// <para>An output action that draws all the actors.</para>
    /// <para>The responsibility of DrawActorsAction is to draw each of the actors.</para>
    /// </summary>
    public class GrowTailAction : Action
    {
        public GrowTailAction()
        {
        }
        
        public void Execute(Cast cast, Script script)
        {
            Bike user = (Bike)cast.GetFirstActor("user");
            Bike program = (Bike)cast.GetFirstActor("program");
            HandleCollisionsAction hca = (HandleCollisionsAction)script.GetAction("update", "HCA");
            GameOver gameOver = (GameOver)cast.GetFirstActor("gameover");
            bool isGameOver = gameOver.GetGameOverStatus();

            if (isGameOver == true)
            {
                user.GrowTail(Constants.WHITE);
                program.GrowTail(Constants.WHITE);
            }
            else
            {
                user.GrowTail(Constants.LIGHT_BLUE);
                program.GrowTail(Constants.YELLOW);
            }
        }
    }
}