using Jumper.Classes;


namespace Jumper
{
    // Main program class.
    public class Program
    {   
        // Starting method. Prompts the user if they want to play the game and
        // then calls the "Game" class.
        static void Main(string[] args)
        {
            Console.Write("Do you want to start a New Game? ");
            string answer = Console.ReadLine();
            if (answer == "Y")
            {
                Game game = new Game();
                game.StartGame();
            }
        }
    }
}