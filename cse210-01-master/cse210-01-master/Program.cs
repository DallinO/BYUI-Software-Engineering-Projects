/*

Dallin Olson
Tic-Tac-Toe

*/


using System;

namespace CSE210_01
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to Tic-Tac-Toe!\n");
            List<string> positionValues = new List<string>();
            for (int index = 1; index < 10; index++)
            {
                positionValues.Add(index.ToString());
            }

            List<int> chosenPositions = new List<int>();
            chosenPositions.Add(0);

            float turn = 1;
            Display(positionValues, turn, chosenPositions);
            

        }   

        static void Display(List<string> positionValues, float turn, List<int> chosenPositions)
        {
            Console.WriteLine("");
            Console.WriteLine($"\t {positionValues[0]} | {positionValues[1]} | {positionValues[2]}");
            Console.WriteLine($"\t---+---+---");
            Console.WriteLine($"\t {positionValues[3]} | {positionValues[4]} | {positionValues[5]}");
            Console.WriteLine($"\t---+---+---");
            Console.WriteLine($"\t {positionValues[6]} | {positionValues[7]} | {positionValues[8]}\n");

            while (turn != 10)
            {
                Turn(positionValues, turn, chosenPositions);
            }
            Console.WriteLine("Its a draw!");

            

        }

        static void Turn(List<string> positionValues, float turn, List<int> chosenPositions)
        {

            if ((positionValues[0] == "X" && positionValues[1] == "X" && positionValues[2] == "X")
               || (positionValues[0] == "X" && positionValues[3] == "X" && positionValues[6] == "X")
               || (positionValues[6] == "X" && positionValues[7] == "X" && positionValues[8] == "X")
               || (positionValues[2] == "X" && positionValues[5] == "X" && positionValues[8] == "X")
               || (positionValues[6] == "X" && positionValues[4] == "X" && positionValues[2] == "X")
               || (positionValues[0] == "X" && positionValues[4] == "X" && positionValues[8] == "X"))
            {
                Console.WriteLine("Player X wins!");
                Environment.Exit(0);
            }
            if ((positionValues[0] == "O" && positionValues[1] == "O" && positionValues[2] == "O")
               || (positionValues[0] == "O" && positionValues[3] == "O" && positionValues[6] == "O")
               || (positionValues[6] == "O" && positionValues[7] == "O" && positionValues[8] == "O")
               || (positionValues[2] == "O" && positionValues[5] == "O" && positionValues[8] == "O")
               || (positionValues[6] == "O" && positionValues[4] == "O" && positionValues[2] == "O")
               || (positionValues[0] == "O" && positionValues[4] == "O" && positionValues[8] == "O"))
            {
                Console.WriteLine("Player O wins!");
                Environment.Exit(0);
            }
            else if (turn % 2 == 0)
            {
                Console.Write("O's turn to choose a square (1-9): ");
                int square = int.Parse(Console.ReadLine());
                if (square < 1 || square > 9)
                {
                    Console.WriteLine("Error: Value must be between 1 and 9.");
                    Turn(positionValues, turn, chosenPositions);
                }
                for (int index = 0; index < chosenPositions.Count; index++)
                {
                    if (square == chosenPositions[index])
                    {
                        Console.WriteLine("This square has already been used. Please select a different square.");
                        Turn(positionValues, turn, chosenPositions);
                    }
                    else if (index == (chosenPositions.Count - 1))
                    {
                        chosenPositions.Add(square);
                        break;
                    }
                }
                positionValues[square - 1] = "O"; 
                turn++;
                Display(positionValues, turn, chosenPositions);
            }
            else if (turn % 2 != 0)
            {
                Console.Write("X's turn to choose a square (1-9): ");
                int square = int.Parse(Console.ReadLine());
                if (square < 1 || square > 9)
                {
                    Console.WriteLine("Error: Value must be between 1 and 9.");
                    Turn(positionValues, turn, chosenPositions);
                }
                for (int index = 0; index < chosenPositions.Count; index++)
                {
                    
                    if (square == chosenPositions[index])
                    {
                        Console.WriteLine("This square has already been used. Please select a different square.");
                        Turn(positionValues, turn, chosenPositions);
                    }
                    else if (index == (chosenPositions.Count - 1))
                    {
                        
                        chosenPositions.Add(square);
                        break;
                    }
                }
                positionValues[square - 1] = "X";
                turn++;
                Display(positionValues, turn, chosenPositions);
            }




        }
    }
}