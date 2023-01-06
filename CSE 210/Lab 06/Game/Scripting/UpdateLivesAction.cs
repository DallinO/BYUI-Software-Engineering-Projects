using System.Collections.Generic;
using Unit05.Game.Casting;
using Unit05.Game.Services;
using Raylib_cs;
using System;


namespace Unit05.Game.Scripting
{
    /// <summary>
    /// <para>An update action that moves all the actors.</para>
    /// <para>
    /// The responsibility of MoveActorsAction is to move all the actors.
    /// </para>
    /// </summary>
    public class UpdateLivesAction : Operation
    {
        /// <summary>
        /// Constructs a new instance of MoveActorsAction.
        /// </summary>
        public UpdateLivesAction()
        {
        }

        /// <inheritdoc/>
        public void Execute(Cast cast, Script script)
        {
            Actor lives = (Actor)cast.GetFirstActor("Lives");
            Player player = (Player)cast.GetFirstActor("Player");
            int hp = player.GetLives();
            lives.SetText("HP: " + hp);
        }
    }
}