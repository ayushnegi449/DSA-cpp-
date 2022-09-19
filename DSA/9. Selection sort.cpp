/*Selection Sort Algorithm with C++ Code | Sorting Algorithms | Data Structures & Algorithms

Selection Sort –
Selection sort is a sorting algorithm, specifically an in-place comparison sort.It has O(n^2) time complexity, making 
it inefficient on large lists. The algorithm divides the input list into two parts: the sublist of items already sorted,
which is built up from left to right at the front (left) of the list, and the sublist of items remaining to be 
sorted that occupy the rest of the list. Initially, the sorted sublist is empty and the unsorted sublist is 
the entire input list.The algorithm proceeds by finding the smallest (or largest, depending on sorting order)
element in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element (putting it in sorted order),
and moving the sublist boundaries one element to the right.


Selection Sort Algorithm –
for i=0 to n-1   // outer for loop
min = i   // set min value to i
for j=i+1 to n   // inner loop
if arr[j] less than arr[min] then   // check which element is smaller
min=j   // store index of smallest element to min
end for   // inner loop
if min not equal to i then   // swap if min does not match to i
swap arr[min] with arr[i]  // swapping
end for   // outer for loop


C++ Program to Implement Selection Sort –*/

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min]) // for ascending order
            // for descending order just write :  "if (arr[j] > arr[min])"
            {
                min = j;
            }
        }

        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
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
    selectionSort(array, size);

    // after sorting
    cout << "After sorting elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}