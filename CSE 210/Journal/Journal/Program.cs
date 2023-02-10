using System;

class Program
{
    static void Main(string[] args)
    {
        string[] scripturesArray = System.IO.File.ReadAllLines("Test.txt");
        List<Scripture> scripList = new List<Scripture>();

        int counter = 1;
        for (int i = 0; i < scripturesArray.Length; i += 2)
        { 
            Scripture scr = new Scripture(scripturesArray[i], scripturesArray[i + 1]);                                                                       // This adds every scripture and reference to the scriptureList array. 
            scripList.Add(scr);

            Console.WriteLine($"{counter++})");
            Console.WriteLine(scripturesArray[i]);
            Console.WriteLine(scripturesArray[i + 1]);
            Console.WriteLine("");

        }
         
        Console.Write("Select the scripture you desire to memorize: ");
        int index = Convert.ToInt32(Console.ReadLine()) - 1;
        Console.WriteLine(); 

        // Call the HideWords() method using the scriptureList[inputIndex] object. 
        Console.Clear();
        scripList[index].HideWords();
    }
}