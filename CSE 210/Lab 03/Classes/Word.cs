using System;
using System.Collections.Generic;

namespace Jumper.Classes
{
    // The "Word" class returns a randomly selected word. 
    public class Word
    {
        // Variables
        private List<string> wordList = new List<string>();
        private string word;
        private Random rnd = new Random();
        
        // The constructor generates the list of words.
        public Word()
        {
            wordList.Add("Money");
            wordList.Add("Crazy");
            wordList.Add("Pizza");
            wordList.Add("Alone");
            wordList.Add("Breed");
            wordList.Add("Class");
            wordList.Add("Faith");
            wordList.Add("Jones");
            wordList.Add("North");
            wordList.Add("Motor");
        }

        // Returns a random word from the list.
        public string GetWord()
        {
            int x = rnd.Next(wordList.Count);
            word = wordList[x];
            return(word);
        }

        // Creates a character list from the selected word.
        public List<string> getCharacterList()
        {
            List<string> characterList = new List<string>();
            foreach (char letter in word)
            {
                characterList.Add(letter.ToString());
            }
            return(characterList);
        }
    }
}