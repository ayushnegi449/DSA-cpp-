/*Insertion Sort Algorithm with C++ Code | Sorting Algorithms | Data Structures & Algorithms

Insertion Sort -

Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.
Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time.
Time Complexity: O(n*2)
Efficient for (quite) small data sets, much like other quadratic sorting algorithms
More efficient in practice than most other simple quadratic (i.e., O(n2)) algorithms such as selection sort or bubble sort


Working -

Step 1 - Pick next element
Step 2 - Compare with all elements in the sorted sub-list on the left
Step 3 - Shift all the elements in the sorted sub-list that is greater than the value to be sorted.
Step 4 - Insert the value
Step 5 - Repeat until list is sorted

Insertion Sort Algorithm -

declare variables - i, key, j
loop : i = 1 to n - 1 // outer loop
key = a[i] //pick the next element
j = i - j; // decrement j value
loop : (j>=0 && a[j]>key) // inner loop
arr[j+1] = arr[j]
j = j - 1
end loop // inner loop
arr[j+1] = ke
end loop // outer loop


C++ Program to Implement Selection Sort -*/

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    int key = 0;
    int j = 0;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
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
    cout << "Before sorting elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    insertionSort(array, size);

    // after sorting
    cout << "After sorting elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}