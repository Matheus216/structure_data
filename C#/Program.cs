
using System.Diagnostics;
using Sorts;

var random = new Random();
var stop = new Stopwatch();
int[] generalInput = [.. Enumerable.Range(0, 300_000).Select(x => random.Next(0, 999999))];
//int[] generalInput = [20, 12, 3, 323, 32, 1, 7, 43];
int[] clone1 = (int[])generalInput.Clone();
int[] clone2 = (int[])generalInput.Clone();
int[] clone3 = (int[])generalInput.Clone();
TimeSpan ts;
string elapsedTime = "";

stop.Start();
clone1.InsertionSearch();
stop.Stop();

LogMessage("InsertationSort", false);

stop.Reset();
stop.Start();
clone2.SelectionSearch();
stop.Stop();

LogMessage("SelectionSort", false);

stop.Reset();
stop.Start();
clone3.RunSort(0, clone3.Length - 1);
stop.Stop();

LogMessage("Merge Sort", false, generalInput, clone3);

void LogMessage(string title, bool showArrays = false, int[] input = null, int[] output = null)
{
    ts = stop.Elapsed;
    Console.WriteLine($"----------- {title} ---------");
    if (showArrays)
    {
        Console.WriteLine($"Parameter: {string.Join(',', input)}");
        Console.WriteLine($"Ordered: {string.Join(',', output)}");
    }
    elapsedTime = String.Format("{0:00}:{1:00}:{2:00}.{3:00}",
                ts.Hours, ts.Minutes, ts.Seconds, ts.Milliseconds / 10);
    Console.WriteLine("RunTime " + elapsedTime);
    Console.WriteLine($"Elapsed milliseconds: {stop.ElapsedMilliseconds}");
    Console.WriteLine($"Elapsed ticks: {stop.ElapsedTicks}\n\n");
}
