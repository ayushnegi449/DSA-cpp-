/*Shell Sort Algorithm with C++ Code | Sorting Algorithms | Data Structures & Algorithms

ShellSort is an in-place comparison sort.  It is mainly a variation of sorting by exchange (bubble sort) or sorting by insertion (insertion sort).
This algorithm avoids large shifts as in case of insertion sort, if the smaller value is to the far right and has to be moved to the far left.
The idea of shell sort is to allow exchange of far items. This spacing is termed as interval or gap. ShellSort is more efficient compared to
Insertion Sort or Bubble sort specially when –
1. Smaller value elements are towards the end of the array/list
2. Large sized array/list
3. Efficiency depends on how we select the GAP/interval

Time Complexity –
1. Best Case – Ω(n log(n))
2. Worst Case – O(n^2)
3. Average Case – θ(n log(n)2)
Space Complexity – O(1)

Working –
Step 1 − Initialize the value of gap/interval (here we take n/2 iteratively)
Step 2 − Compare 2 elements at the distance of gap at every iteration
Step 3 − if element at the left is smaller than element at the right, perform swap or shift(depending on whether you use bubble sort or insertion sort respectively)
Step 3 − Repeat until complete list is sorted.

C++ Program to Implement Shell Sort –*/

#include <bits/stdc++.h>
using namespace std;

void shellSort(int arr[], int size)
{
    for (int gap = (size / 2); gap > 0; gap /= 2)
    {
        for (int j = gap; j < size; j++)
        {
            int temp = arr[j];
            int i = 0;

            for (i = j; ((i >= gap) && (arr[i - gap] > temp)); i -= gap)
            {
                arr[i] = arr[i - gap];
            }

            arr[i] = temp;
        }
    }
}

int main()
{

    int size = 0;

    cout << "Enter Size of array: " << endl;
    cin >> size;

    int myarray[size];

    cout << "Enter " << size << " integers in any order: " << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> myarray[i];
    }

    cout << "Before Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }
    cout << endl;

    shellSort(myarray, size); // shellsort sort called

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }

    return 0;
}