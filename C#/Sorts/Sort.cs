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
    public static int[] QuickSort(int[] input)
    {
        throw new NotImplementedException();
    }

    public static int[] BunbbleSort(int[] input)
    {
        throw new NotImplementedException();
    }
}

public static class MergeSort
{
    public static void RunSort(this int[] input, int startIndex, int lastIndex)
    {
        if (ValidationInput(input, startIndex, lastIndex))
        {
            var middle = (startIndex + lastIndex) / 2;
            RunSort(input, startIndex, middle);
            RunSort(input, middle + 1, lastIndex);
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
    
    private static bool ValidationInput(int[] input, int startIndex, int lastIndex)
        => input is not null &&
            input.Length > 0 &&
            startIndex < lastIndex &&
            startIndex >= 0 && 
            lastIndex < input.Length;
}