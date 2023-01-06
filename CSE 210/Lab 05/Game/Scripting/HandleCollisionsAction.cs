using System;
using System.Collections.Generic;
using System.Data;
using Unit05.Game.Casting;
using Unit05.Game.Services;


namespace Unit05.Game.Scripting
{
    /// <summary>
    /// <para>An update action that handles interactions between the actors.</para>
    /// <para>
    /// The responsibility of HandleCollisionsAction is to handle the situation when the snake 
    /// collides with the food, or the snake collides with its segments, or the game is over.
    /// </para>
    /// </summary>
    public class HandleCollisionsAction : Action
    {

        /// <summary>
        /// Constructs a new instance of HandleCollisionsAction.
        /// </summary>
        public HandleCollisionsAction()
        {
        }

        /// <inheritdoc/>
        public void Execute(Cast cast, Script script)
        {
            GameOver gameOver = (GameOver)cast.GetFirstActor("gameover");

            if (gameOver.GetGameOverStatus() == false)
            {
                HandleBikeCollisions(cast);
                HandleSegmentCollisions(cast);
                HandleGameOver(cast);
            }
        }

        /// <summary>
        /// Sets the game over flag if the snake collides with one of its segments.
        /// </summary>
        /// <param name="cast">The cast of actors.</param>
        private void HandleSegmentCollisions(Cast cast)
        {
            Bike user = (Bike)cast.GetFirstActor("user");
            Actor head = user.GetHead();
            List<Actor> body = user.GetBody();
            GameOver gameOver = (GameOver)cast.GetFirstActor("gameover");

            foreach (Actor segment in body)
            {
                if (segment.GetPosition().Equals(head.GetPosition()))
                {
                    gameOver.SetGameOverStatus(true);
                }
            }

            Bike program = (Bike)cast.GetFirstActor("program");
            head = program.GetHead();
            body = program.GetBody();

            foreach (Actor segment in body)
            {
                if (segment.GetPosition().Equals(head.GetPosition()))
                {
                    gameOver.SetGameOverStatus(true);
                }
            }
        }

        private void HandleBikeCollisions(Cast cast)
        {
            Bike user = (Bike)cast.GetFirstActor("user");
            Bike program = (Bike)cast.GetFirstActor("program");
            Actor uhead = user.GetHead();
            Actor phead = program.GetHead();
            List<Actor> ubody = user.GetBody();
            List<Actor> pbody = program.GetBody();
            GameOver gameOver = (GameOver)cast.GetFirstActor("gameover");
            
            foreach (Actor segment in ubody)
            if (segment.GetPosition().Equals(phead.GetPosition()))
            {   
                gameOver.SetGameOverStatus(true);
            }

            foreach (Actor segment in pbody)
            if (segment.GetPosition().Equals(uhead.GetPosition()))
            {
                gameOver.SetGameOverStatus(true);
            }
        }

        private void HandleGameOver(Cast cast)
        {
            GameOver gameOver = (GameOver)cast.GetFirstActor("gameover");

            if (gameOver.GetGameOverStatus() == true)
            {
                gameOver.DoGameOver(cast);
            }
        }
    }
}