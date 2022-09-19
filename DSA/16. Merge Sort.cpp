/*Merge Sort Algorithm (with Example) with C++ Code | Sorting Algorithms | Data Structures & Algorithms

> Merge Sort Algorithm is a Divide & Conquer algorithm. It divides input array in two halves,
calls itself for the two halves(recursively) and then merges the two sorted halves.
A separate merge() function is used for merging two halves. Merge sort is one of the most efficient sorting algorithms.

>> Time Complexity: O(nlog(n))

Working –

There are 3 Phases (4 major steps) in the Merge Sort Algorithm –

1.Division Phase –
Divide the array(list) into 2 halves by finding the midpoint of the array(list).
Midpoint (m) = (left + right)/ 2
Here left is the starting index & right is the last index of the array(list)

2.Recursion Phase –
Call Merge Sort on the left sub-array (sub-list)
Call Merge Sort on the right sub-array (sub-list)

3.Merge Phase –
Call merge function to merge the divided sub-arrays back to the original array.
Perform sorting of these smaller sub arrays before merging them back.

Merge Sort Algorithm(Pseudo Code) –

mergeSort(arr[],l,r)  //arr is array, l is left, r is right
{
   if(l<r)
   {
      midpoint = (l+r)/2
      mergeSort(arr,l,m)
      mergeSort(arr,m+1,r)
      merge(arr,l,m,r)
   }
}


C++ Program to Implement Merge Sort(with fixed size of array) */

#include <bits/stdc++.h>
using namespace std;

merge(int arr[], int l, int m, int r, int size)
{
    int i = l;
    int j = m + 1;
    int k = l;

    // creating a temporary array
    int *temp = new int[size];

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    } 
    
    // Copy the remaining elements of first half, if there are any
    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy the temp array to original array
    for (int p = l; p <= r; p++)
    {
        arr[p] = temp[p];
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
mergeSort(int arr[], int l, int r, int number)
{
    if (l < r)
    {
        // find midpoint
        int m = (l + r) / 2;

        // recurcive mergesort firstand second halves
        mergeSort(arr, l, m, number);
        mergeSort(arr, m + 1, r, number);

        // merge
        merge(arr, l, m, r, number);
    }
}

int main()
{
    int size;

    cout << "Enter the size of the array : " << endl;
    cin >> size;

    int *array = new int[size];

    cout << "Enter " << size << " elements in random order : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    // before sorting
    cout << "Before sorting elements using merge sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    mergeSort(array, 0, (size - 1), size);

    // after sorting
    cout
        << "After sorting elements using merge sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}