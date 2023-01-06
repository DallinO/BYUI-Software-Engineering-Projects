using System;
using System.Collections.Generic;



namespace Jumper.Classes
{
    //  This class's function is to facilitate interaction between the display
    //   terminal and the user.
    public class Terminal
    {
        // Displays the parachute.
        public void displayParachute(Game game)
        {
           foreach (string line in game.parachuteList)
           {
               Console.WriteLine(line);
           }
        }

        // Displays the word one letter at a time if the user has guessed the
        // letter, otherwise it displays an underscore.
        public void displayWord(Game game)
        {
            foreach (string letter1 in game.characterList)
            {
                bool correct = false;
                foreach (string letter2 in game.guessList)
                {
                    if (letter1.ToUpper() == letter2.ToUpper())
                    {
                        Console.Write($"{letter1} ");
                        correct = true;
                    }
                }
                if (correct == false)
                {
                    Console.Write("_ ");
                }
                
            }
            Console.WriteLine("\n");
        }

        // Displays the guess prompt
        public void guessPrompt()
        {
            Console.Write("Guess a letter [a-z]: ");
        }

        // Displays an endscreen depending on whether the user won or lost.
        public void EndScreen(Game game)
        {
            
            if (game.gameOver == 4)
            {
                displayParachute(game);
                Console.WriteLine("GAME OVER!");
            }
            else
            {
                displayWord(game);
                Console.WriteLine("YOU WIN!");
            }
        }
    }
}