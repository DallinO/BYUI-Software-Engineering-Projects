using System;
using System.Collections.Generic;

namespace CSE210_02.Classes
{
    // Creates a new Card object.
    // Primary function is to return a random card from the
    // deck object.
    public class Card
    {
        int index;
        Random rnd = new Random();
        string card;
        public Card(Game game)
        {
            int x = rnd.Next(game.hashList.Count);
            card = game.hashList[x];
            game.hashList.Remove(game.hashList[x]);
        }

        public string GetCard()
        {
            return(card);
        }
    }
}
