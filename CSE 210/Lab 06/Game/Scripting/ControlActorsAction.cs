using Unit05.Game.Casting;
using Unit05.Game.Services;
using Raylib_cs;
using System.Collections.Generic;
using System;


namespace Unit05.Game.Scripting
{
    /// <summary>
    /// <para>An input action that controls the snake.</para>
    /// <para>
    /// The responsibility of ControlActorsAction is to get the direction and move the snake's head.
    /// </para>
    /// </summary>
    public class ControlActorsAction : Operation
    {
        private KeyboardService keyboardService;
        private Point direction;
        int iteration = 0;

        /// <summary>
        /// Constructs a new instance of ControlActorsAction using the given KeyboardService.
        /// </summary>
        public ControlActorsAction(KeyboardService keyboardService, Player player)
        {
            this.keyboardService = keyboardService;
            this.direction = player.GetPosition();
        }

        /// <inheritdoc/>
        public void Execute(Cast cast, Script script)
        {
            Bullet bullet = (Bullet)cast.GetFirstActor("Bullet");
            Alien aliens = (Alien)cast.GetFirstActor("Aliens");
            List<Actor> alienList = aliens.GetAlienList();
            int modulus = iteration % 180;

            // left
            if (keyboardService.IsKeyDown("left"))
            {
                direction = new Point(direction.GetX() - Constants.CELL_SIZE, direction.GetY());
            }

            // right
            if (keyboardService.IsKeyDown("right"))
            {
                direction = new Point(direction.GetX() + Constants.CELL_SIZE, direction.GetY());
            }

            Player player = (Player)cast.GetFirstActor("Player");
            player.SetPosition(direction);

            foreach (Actor alien in alienList)
            {
                Point alienPosition = alien.GetPosition();
                int ax = alienPosition.GetX();
                int ay = alienPosition.GetY();
                if (modulus == 60 || modulus == 120)
                {
                    alien.SetPosition(new Point(ax + 15, ay));
                }
                if (modulus == 30 || modulus == 90)
                {
                    alien.SetPosition(new Point(ax, ay + 15));
                }
                if (modulus == 0 || modulus == 150)
                {
                    alien.SetPosition(new Point(ax - 15, ay));
                }

            }

            iteration++;
        }
    }
}