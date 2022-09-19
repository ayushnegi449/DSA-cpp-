/*Bubble Sort Algorithm with C++ Code | Sorting Algorithms | Data Structures & Algorithms

Bubble Sort –

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
This algorithm is suitable for small data sets
Its average and worst case complexity are of (n^2) where n is the number of items.
It is known as bubble sort, because with every complete iteration the largest element bubbles up towards the last place or the highest
index just like a water bubble rises up to the water surface.


Working –
Step 1 – Starting with the first element(index = 0), compare the current element with the next element of the array.
Step 2 – If the current element is greater than the next element of the array, swap them.
Step 3 – If the current element is less than the next element, move to the next element.
Step 4 – Repeat Step 1 till the list is sorted.


Bubble Sort Algorithm –
declare variables – i, j
loop : i = 0 to n – 1 // outer loop
loop : j = 0 to n -i- 1 // inner loop
if ( a[j]>a[j+1] ) then
swap a[j] & a[j+1]
end loop // inner loop
end loop // outer loop


C++ Program to Implement BubbleSort –*/

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            
            }
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
    bubbleSort(array, size);

    // after sorting
    cout << "After sorting elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}