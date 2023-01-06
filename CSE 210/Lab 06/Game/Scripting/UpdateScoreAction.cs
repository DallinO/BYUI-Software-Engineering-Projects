using Unit05.Game.Casting;

namespace Unit05.Game.Scripting
{
    /// <summary>
    /// <para>An update action that moves all the actors.</para>
    /// <para>
    /// The responsibility of MoveActorsAction is to move all the actors.
    /// </para>
    /// </summary>
    public class UpdateScoreAction : Operation
    {
        /// <summary>
        /// Constructs a new instance of MoveActorsAction.
        /// </summary>
        public UpdateScoreAction()
        {
        }

        /// <inheritdoc/>
        public void Execute(Cast cast, Script script)
        {  
            Score score = (Score)cast.GetFirstActor("Score");
            int points = score.GetScore();
            score.SetText("SCORE: " + points);
        }
    }
}