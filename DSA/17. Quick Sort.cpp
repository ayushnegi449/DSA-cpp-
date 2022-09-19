// Quick Sort Algorithm (with Example) with C++ Code | Sorting Algorithms | Data Structures & Algorithms

// > Quick Sort Algorithm is a Divide & Conquer algorithm.
// It divides input array in two partitions, calls itself for the two partitions(recursively)
// and performs in-place sorting while doing so. A separate partition() function is used for performing this
// in-place sorting at every iteration. Quick sort is one of the most efficient sorting algorithms.

// >> Time Complexity: θ(nlog(n))
// >> Space Complexity: O(log(n))

// Working –
// There are 2 Phases (3 major steps) in the Quick Sort Algorithm –

// 1.Division Phase –
// a.Divide the array(list) into 2 halves by finding the pivot point to perform the partition of the array(list).
// The in-place sorting happens in this partition process itself.

// 2.Recursion Phase –
// b.Call Quick Sort on the left partition (sub-list)
// c.Call Quick Sort on the right partition (sub-list)

// C++ Program to Implement Quick Sort –

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pIndex = s;
    int pivot = arr[e];

    for (int i = s; i < e; i++)
    {
        if (arr[i] < pivot)
        {
            int temp = arr[pIndex];
            arr[pIndex] = arr[i];
            arr[i] = temp;
            pIndex++;
        }
    }
    int temp1 = arr[pIndex];
    arr[pIndex] = pivot;
    arr[e]= temp1;

    return pIndex;
}

void quickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e);

        quickSort(arr, s, p - 1);
        quickSort(arr, p + 1, e);
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

    quickSort(array,0,size -1 );

    // after sorting
    cout
        << "After sorting elements using merge sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}