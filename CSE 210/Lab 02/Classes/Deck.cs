using System;
using System.Collections.Generic;

namespace CSE210_02.Classes
{
    // Creates a new deck.
    public class Deck
    {
        // Variables.
        public List<string> hashList = new List<string>();
        public Dictionary<string, int> deck = new Dictionary<string, int>();
        
        // Creates Deck object.
        public Deck()
        {
            List<string> suite = new List<string>();
            suite.Add("Heart");
            suite.Add("Spade");
            suite.Add("Diamond");
            suite.Add("Club");

            List<string> faceCard = new List<string>();
            faceCard.Add("J");
            faceCard.Add("Q");
            faceCard.Add("K");
            faceCard.Add("A");

            for (int x = 0; x < 4; x++)
            {
                string deckLiteral;
                int yankee;
                int zulu;

                for (yankee = 2; yankee <= 10; yankee++)
                {
                    deckLiteral = (yankee.ToString() + " " + suite[x]);
                    int deckNumerical = yankee;
                    deck.Add(deckLiteral, deckNumerical);
                    hashList.Add(deckLiteral);

                }
                yankee = 10;
                for (zulu = 0; zulu < 4; zulu++)
                {
                    deckLiteral = (faceCard[zulu] + " " + suite[x]);
                    yankee = yankee + 1;
                    int deckNumerical = yankee;
                    deck.Add(deckLiteral, deckNumerical);
                    hashList.Add(deckLiteral);

                }
            }
        }

        // Returns deck.
        public Dictionary<string, int> GetDeck()
        {
            return(deck);
        }

        // Returns deck hash list.
        public List<string> GetHash()
        {
            return(hashList);
        }
    }
}
