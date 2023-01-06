using System;
using System.Collections.Generic;

namespace CSE210_02.Classes
{
    
    // The Game class facilitates the game.
    public class Game
    {
        public Dictionary<string, int> newDeck;
        public List<string> hashList;
        Deck deck = new Deck();
        
        // Creates new game object
        public Game()
        {
            newDeck = deck.GetDeck();
            hashList = deck.GetHash();
        }
        
        // Directs the game.
        public void StartGame()
        {
            bool win = false;
            int points = 500;

            while (win == false)
            {
                bool guess = false;
                Card card1 = new Card(this);
                string cardOne = card1.GetCard();

                Console.WriteLine("**************************");
                Console.WriteLine($"The card is: {cardOne}");

                Console.Write("Higher or Lower (H/L): ");
                string answer = Console.ReadLine();
                
                Card card2 = new Card(this);
                string cardTwo = card2.GetCard();
                Console.WriteLine($"The Next card was: {cardTwo}");

                if (((newDeck[cardOne] > newDeck[cardTwo]) && answer == "L")
                    || (newDeck[cardOne] < newDeck[cardTwo]) && answer == "H")
                {
                    points = points + 100;
                    guess = true;
                }
                else if (guess == false)
                {
                    points = points - 75;
                }

                Console.WriteLine($"Your score is: {points}");
                Console.Write("Play again (Y/N)? ");
                answer = Console.ReadLine();
                if (answer == "N" || points <= 0 || hashList.Count == 0)
                {
                    Environment.Exit(0);
                }
                Console.WriteLine("**************************");
            }
        }
    }
}
