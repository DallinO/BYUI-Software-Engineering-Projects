using System;

class Program
{
    static void Main(string[] args)
    {
        Reference scriptureReference = new Reference("Proverbs", "3", "5-6");
        Scripture scripture = new Scripture(scriptureReference, "Trust in the Lord with all thine heart; and lean not unto thine own understanding. In all thy ways acknowledge him, and he shall direct thy paths.");
        scriptureMemorizer scriptureMemorizer = new scriptureMemorizer(scripture);

        string userInput = " ";
        
        Console.Clear();
        Console.WriteLine(string.Format("{0} {1}", scriptureReference.toString(), scriptureMemorizer.toString()));
        Console.WriteLine("Please enter to continue or type 'quit' to finish:");

        userInput = Console.ReadLine();
        while (scriptureMemorizer.hasWordsLeft() == true){
            scriptureMemorizer.removeWordsFromText();
            Console.Clear();
            Console.WriteLine(string.Format("{0} {1}", scriptureReference.toString(), scriptureMemorizer.toString()));
            Console.WriteLine("Please enter to continue or type 'quit' to finish:");
            userInput = Console.ReadLine();
            if (userInput == ("quit")){
                break;
            }
        }

        Console.WriteLine("END");
    }
}