using System.Globalization;

namespace Sorts;

public static class Sort
{
    public static void InsertionSearch(this int[] input)
    {
        for (int i = 1; i <= input.Length - 1; i++)
        {
            var key = input[i];
            var j = i - 1;
            while (j >= 0 && input[j] > key)
            {
                input[j + 1] = input[j];
                j--;
            }
            input[j + 1] = key;
        }
    }

    public static void SelectionSearch(this int[] input)
    {
        for (int i = 0; i < input.Length; i++)
        {
            int minor = i;
            for (int j = i + 1; j < input.Length; j++)
                if (input[minor] > input[j])
                    minor = j;

            (input[minor], input[i]) = (input[i], input[minor]);
        }
    }
    public static int[] BubbleSort(int[] input)
    {
        throw new NotImplementedException();
    }
}

public static class MergeSort
{
    public static void Merge(this int[] input, int startIndex, int lastIndex)
    {
        if (ValidationInput(input, startIndex, lastIndex))
        {
            var middle = (startIndex + lastIndex) / 2;
            Merge(input, startIndex, middle);
            Merge(input, middle + 1, lastIndex);
            Merge(input, startIndex, middle, lastIndex);
        }
    }

    private static void Merge(int[] input, int startIndex, int middle, int lastIndex)
    {
        var aux = (int[])input.Clone();
        int i = startIndex;
        int j = middle + 1;
        int k = startIndex;

        while (i <= middle && j <= lastIndex)
        {
            if (aux[i] < aux[j])
            {
                input[k] = aux[i];
                i++;
            }
            else
            {
                input[k] = aux[j];
                j++;
            }
            k++;
        }

        while (i <= middle)
        {
            input[k] = aux[i];
            k++;
            i++;
        }

        while (j <= lastIndex)
        {
            input[k] = aux[j];
            j++;
            k++;
        }
    }

    public static void  MergeBook(int[] input, int start, int middle, int end)
    {
        var left = input[0..middle];
        var rigth = input[middle..end];

        int n1 = 0;
        int n2 = 0;
        int aux = 0;

        for (var i = start; i < end || i < end - middle; i++)
        {
            if (input[n1] < input[i])
            {
                aux = input[i];
                input[i] = input[n1];
            }
            else
            {
                aux = input[i];
                input[i] = input[n2];
            }
        }

        while (n1 <= end-middle)
        {
            input[];
            n1++; 
        }
    }

    private static bool ValidationInput(int[] input, int startIndex, int lastIndex)
        => input is not null &&
            input.Length > 0 &&
            startIndex < lastIndex &&
            startIndex >= 0 &&
            lastIndex < input.Length;
}

public static class QuickSortImplementation
{
    public static void QuickSort(this int[] array)
    {
        array.QuickSort(0, array.Length - 1);
    }
    private static void QuickSort(this int[] array, int start, int end)
    {
        if (end <= start) return;
        var pivot = Partition(array, start, end);
        array.QuickSort(start, pivot - 1);
        array.QuickSort(pivot + 1, end);
    }
    private static int Partition(this int[] array, int start, int end)
    {
        int pivot = start - 1;
        for (int j = start; j < end; j++)
        {
            if (array[j] < array[end])
            {
                pivot++;
                var temp = array[pivot];
                array[pivot] = array[j];
                array[j] = temp;
            }
        }
        pivot++;
        var tt = array[pivot];
        array[pivot] = array[end];
        array[end] = tt;

        return pivot;
    }
}
public static class BubbleSortImplementation
{
    public static void Bubbler(this int[] input)
    {
        bool finished = false; 
        for (int i = 0; i < input.Length; i++)
        {
            if (finished) break; 
            finished = true;
            for (int j = 0; j < input.Length - i - 1; j++)
            {
                if (input[j+1] < input[j])
                {
                    var temp = input[j];
                    input[j] = input[j+1];
                    input[j+1] = temp;
                    finished = false;  
                }
            }
        }
    }
}