using System;

internal class Memorizer
{
    public void HideWords(Scripture scripture)
    {
        Random rnd = new Random();
        if (DisplayNPrompt(scripture))
            System.Environment.Exit(0);

        while (true)
        {
            List<Word> _wordsLeft = scripture.GetVisableWords();
            if (_wordsLeft.Count() == 0)
                break;

            for (int i = 0; i < 3; i++)
            {
                int index = rnd.Next(_wordsLeft.Count());
                _wordsLeft[index].Set_IsHidden(true);
                       
            }

            if (DisplayNPrompt(scripture))
                break;
        }
    }

    public bool DisplayNPrompt(Scripture scripture)
    {
        scripture.DisplayWords();
        Console.WriteLine();
        Console.WriteLine("Press Enter to continue or Quit to finish.");
        string userInput = Console.ReadLine();
        if (userInput.ToLower() == "quit")
        {
            return true;
        }
        else
        {
            Console.Clear();
            return false;
        }
            
        
    }

}

