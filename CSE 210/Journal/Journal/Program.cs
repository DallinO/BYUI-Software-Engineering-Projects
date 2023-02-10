using System;
using System.IO;
using System.Text.Json;
using System.Text.Json.Serialization;

class Program
{
    static void Main(string[] args)
    {
        
        string[] scripturesArray = System.IO.File.ReadAllLines("C:\\Users\\offic\\Documents\\Software Engineering\\BYUI-Software-Engineering-Projects\\CSE 210\\Journal\\Journal\\Test.txt");
        List<Scripture> scripList = new List<Scripture>();
        Memorizer mem = new Memorizer();

        int counter = 1;
        for (int i = 0; i < scripturesArray.Length; i += 2)
        { 
            Scripture scr = new Scripture(scripturesArray[i], scripturesArray[i + 1]);
            scripList.Add(scr);

            Console.WriteLine($"{counter++})");
            Console.WriteLine(scripturesArray[i]);
            Console.WriteLine(scripturesArray[i + 1]);
            Console.WriteLine("");

        }
         
        Console.Write("Select the scripture you desire to memorize: ");
        int index = Convert.ToInt32(Console.ReadLine()) - 1;
        Console.WriteLine();
        Console.Clear();
        mem.HideWords(scripList[index]);
    }
}