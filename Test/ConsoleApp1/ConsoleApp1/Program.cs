using System;
class test
{  
    static public void Main()
    {
        DateTime startTime;
        DateTime endTime;
        startTime = DateTime.Now;
        Console.WriteLine(startTime.ToString());
        Console.ReadLine();
        endTime = DateTime.Now;
        Console.WriteLine(endTime.ToString());
        TimeSpan x = startTime.Subtract(endTime);
        Console.WriteLine(x.ToString());
        double y = x.TotalSeconds;
        Console.WriteLine(y.ToString());


    }
}
