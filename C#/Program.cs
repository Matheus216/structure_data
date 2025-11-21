
using System.Diagnostics;
using Sorts;

var random = new Random();

// int[] generalInput = [.. Enumerable.Range(0, 300_000_00).Select(x => random.Next(0, 999999))];
int[] generalInput = [8,2,4,7,1,3,9, 6, 5];
int[] clone1 = (int[])generalInput.Clone();
int[] clone2 = (int[])generalInput.Clone();
int[] clone3 = (int[])generalInput.Clone();
int[] clone4 = (int[])generalInput.Clone();
int[] clone5 = (int[])generalInput.Clone();

// var stop = new Stopwatch();
// stop.Start();
// clone5.Bubbler();
// stop.Stop();

var stop = new Stopwatch();
stop.Start();
clone3.Merge(0, clone3.Length - 1);
stop.Stop();

LogMessage("MergeSort", false, generalInput, clone3, stop);

Task.WaitAll([
    // Task.Run(() =>
    // {
    //     var stop = new Stopwatch();
    //     stop.Start();
    //     clone1.InsertionSearch();
    //     stop.Stop();

    //     LogMessage("InsertationSort", false, generalInput, clone1, stop);
    // }),
    //     Task.Run(() =>  {
    //     var stop = new Stopwatch();
    //     stop.Start();
    //     clone2.SelectionSearch();
    //     stop.Stop();

    //     LogMessage("SelectionSearch", false, generalInput, clone2, stop);
    // }),
    // Task.Run(() =>  {
    //     var stop = new Stopwatch();
    //     stop.Start();
    //     clone3.RunSort(0, clone3.Length - 1);
    //     stop.Stop();

    //     LogMessage("MergeSort", false, generalInput, clone3, stop);
    // }),
    // Task.Run(() =>  {
    //     var stop = new Stopwatch();
    //     stop.Start();
    //     clone4.QuickSort();
    //     stop.Stop();

    //     LogMessage("QuickSort", false, generalInput, clone4, stop);
    // }),
    // Task.Run(() => {
    //     var stop = new Stopwatch();
    //     stop.Start();
    //     var r = clone5.OrderBy(x => x).ToArray();
    //     stop.Stop();
    //     LogMessage(".NET Sort", false, generalInput, r, stop);     
    // })
]);


void LogMessage(string title, bool showArrays, int[] input, int[] output, Stopwatch sp)
{
    var ts = sp.Elapsed;
    if (showArrays)
    {
        Console.WriteLine($"Parameter: {string.Join(',', input)}");
        Console.WriteLine($"Ordered: {string.Join(',', output)}");
    }
    var elapsedTime = String.Format("{0:00}:{1:00}:{2:00}.{3:00}",
                ts.Hours, ts.Minutes, ts.Seconds, ts.Milliseconds / 10);
    Console.WriteLine($"RunTime - {title} " + elapsedTime);
}
