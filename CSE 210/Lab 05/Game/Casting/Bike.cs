using System;
using System.Collections.Generic;
using System.Linq;

namespace Unit05.Game.Casting
{
    // The player entity
    public class Bike : Actor
    {
        private List<Actor> segments = new List<Actor>();

        /// <summary>
        /// Constructs a new instance of a Bike.
        /// </summary>
        public Bike(int x, int y, Color a)
        {
            Point position = new Point(x , y);
            Point velocity = new Point(1 * Constants.CELL_SIZE, 0);
            string text = "O";
            Color color = a;
            Actor segment = new Actor();
            segment.SetPosition(position);
            segment.SetVelocity(velocity);
            segment.SetText(text);
            segment.SetColor(color);
            segments.Add(segment);
        }

        /// <summary>
        /// Gets the bike's body segments.
        /// </summary>
        /// <returns>The body segments in a List.</returns>
        public List<Actor> GetBody()
        {
            return new List<Actor>(segments.Skip(1).ToArray());
        }

        /// <summary>
        /// Gets the bike head segment.
        /// </summary>
        /// <returns>The head segment as an instance of Actor.</returns>
        public Actor GetHead()
        {
            return segments[0];
        }

        /// <summary>
        /// Gets the bike trail segments (including the head).
        /// </summary>
        /// <returns>A list of snake segments as instances of Actors.</returns>
        public List<Actor> GetSegments()
        {
            return segments;
        }

        /// <summary>
        /// Grows the bike trail by the given number of segments.
        /// </summary>
        /// <param name="numberOfSegments">The number of segments to grow.</param>
        public void GrowTail(Color color)
        {
            Actor tail = segments.Last<Actor>();
            Point velocity = tail.GetVelocity();
            Point offset = velocity.Reverse();
            Point position = tail.GetPosition().Add(offset);

            Actor segment = new Actor();
            segment.SetPosition(position);
            segment.SetVelocity(velocity);
            segment.SetText("o");
            segment.SetColor(color);
            segments.Add(segment);
        }

        /// <inheritdoc/>
        public override void MoveNext()
        {
            foreach (Actor segment in segments)
            {
                segment.MoveNext();
            }

            for (int i = segments.Count - 1; i > 0; i--)
            {
                Actor trailing = segments[i];
                Actor previous = segments[i - 1];
                Point velocity = previous.GetVelocity();
                trailing.SetVelocity(velocity);
            }
        }

        /// <summary>
        /// Turns the head of the bike in the given direction.
        /// </summary>
        /// <param name="velocity">The given direction.</param>
        public void TurnHead(Point direction)
        {
            segments[0].SetVelocity(direction);
        }
    }
}