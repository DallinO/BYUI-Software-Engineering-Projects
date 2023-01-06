using System;
using System.Collections.Generic;

namespace Jumper.Classes
{
    // This is the primary class that facilitates the game, creating objects
    // and housing the main variables that are used.
    public class Game
    {
        // Variables
        public List<string> characterList = new List<string>();
        public List<string> parachuteList = new List<string>();
        public List<string> guessList = new List<string>();
        private Parachute parachute = new Parachute();
        private Word word = new Word();
        public int gameOver = 0;
        public int win = 0;
        private Terminal display = new Terminal();

        // The class constructor. Creates a parachute and word object.
        public Game()
        {
            parachuteList = parachute.GetParachute();
            string newWord = word.GetWord();
            characterList = word.getCharacterList();
        }

        // This method is responsible for the guess action of the game and
        // dtermines if the guess is correct or wrong.
        public void Guess()
        {
            display.guessPrompt();
            string guess = Console.ReadLine();
            guessList.Add(guess);
            bool correct = false;

            foreach (string letter in characterList)
            {
                if (letter.ToUpper() == guess.ToUpper())
                {
                    correct = true;
                }
            }
            if (correct == false)
            {
                gameOver = gameOver + 1;
                parachuteList.Remove(parachuteList[0]);
            }
            if (correct == true)
            {
                win = win + 1;
            }
        }

        // This method creates the loop responsible for keeping the game going
        // until the user loses or wins.
        public void StartGame()
        {
            while (gameOver != 4 && win != 5)
            {
                display.displayWord(this);
                display.displayParachute(this);
                Guess();
            }
            display.EndScreen(this);
        }


    }
}