// Hilo
// Dallin Olson
// CSE210-02


using CSE210_02.Classes;

namespace CSE210_02
{
    // Primary program class.
    public class Program
    {
        // Main method that starts the game.
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
