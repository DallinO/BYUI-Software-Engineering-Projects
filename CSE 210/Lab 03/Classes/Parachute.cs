using System;
using System.Collections.Generic;

namespace Jumper.Classes
{
    // This class generates and returns the parachute display.
    public class Parachute
    {
        // Variables
        private List<string> parachute = new List<string>();

        // Generates parachute string list.
        public Parachute()
        {
            parachute.Add(" ___ ");
            parachute.Add("/___\\");
            parachute.Add("\\   /");
            parachute.Add(" \\ / ");
            parachute.Add("  O  ");
            parachute.Add(" /|\\ ");
            parachute.Add(" / \\ ");
            parachute.Add("     ");
        }

        // Returns the parachute list.
        public List<string> GetParachute()
        {
            return(parachute);
        }
    }
}