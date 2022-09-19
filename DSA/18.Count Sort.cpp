// Counting Sort Algorithm with C++ Code | Sorting Algorithms | Data Structures & Algorithms

// Count/Counting Sort –

// Counting sort is a sorting algorithm that sorts the elements of an array by counting the number of occurrences of
// each unique element in the array/list/data structure.
// The count is stored in an auxiliary array and the sorting is done by mapping the count as an index of the auxiliary array.
// This mapping is done by performing arithmetic calculations on those counts to determine the positions of each
// key value(unique element) in the output sequence.
// Its running time is linear in the number of items and the difference between the maximum and minimum key values,
// so it is only suitable for direct use in situations where the variation in keys is not significantly greater than the number of items.
// It is often used as a subroutine in another sorting algorithm, radix sort, that can handle larger keys more efficiently.

// Because counting sort uses key values as indexes into an array, it is not a comparison sort, and the Ω(n log n) lower bound
// for comparison sorting does not apply to it.

// Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input.
// Auxiliary Space: O(n+k)

// Working –

// Step 1 – Take input array & range(no of unique integer values involved)
// Step 2 – Create the output array of size same as input array. Create count array with size equal to the range & initialize values to 0.
// Step 3 – Count each element in the input array and place the count at the appropriate index of the count array
// Step 4 – Modify the count array by adding the previous counts(cumulative). The modified count array indicates the position of 
//          each object/element in the output array.
// Step 5 – Output each object from the input array into the sorted output array followed by decreasing its count by 1.
// Step 6 – Print the sorted output array.

// // Counting Sort Algorithm –
// // take input_array[size]
// // create output_array[size]
// // take range (or no of unique elements)
// // create count_array[range] & initialize all values to 0
// // for(int i=0 to i<range)
// // count_array[i] = 0
// // Count each element & place it in the count_array
// // for(int i = 0 to i<size)
// // ++count_array[input_array[i]]
// // Modify count_array[] to store previous counts (cumulative)
// // for(int i = 1 to i < range)
// // count_array[i]=count_array[i]+count_array[i-1]
// // Place elements from input_array[] to output_array[] using this count_array[] that has the actual positions of elements
// // for(int i=0 to i<size)
// // output_array[–count_array[input_array[i]]] = input_array[i]
// // Transfer sorted values from output_array[] to input_array[]
// // for(i=0 to i<size)
// // input_array[i]=output_array[i]

// C++ Program to Implement Counting Sort –

#include <iostream>
using namespace std;

// counting sort sorting algorithm
void CountingSort(int input_array[], int s, int r)
{

    int output_array[s];

    int count_array[r];

    // initialize all elements to 0 in count array
    for (int i = 0; i < r; i++)
    {
        count_array[i] = 0;
    }

    // to take a count of all elements in the input array
    for (int i = 0; i < s; i++)
    {
        ++count_array[input_array[i]];
    }

    // cummulative count of count array to get the
    // positions of elements to be stored in the output array
    for (int i = 1; i < r; i++)
    {
        count_array[i] = count_array[i] + count_array[i - 1];
    }

    // placing input array elements into output array in proper
    //  positions such that the result is a sorted array in ASC order
    for (int i = 0; i < s; i++)
    {
        output_array[--count_array[input_array[i]]] = input_array[i];
    }

    // copy output array elements to input array
    for (int i = 0; i < s; i++)
    {
        input_array[i] = output_array[i];
    }
}

int main()
{

    int size = 0;

    int range = 10;

    cout << "Enter Size of array: " << endl;
    cin >> size;

    int myarray[size];

    cout << "Enter " << size << " integers in any order in range of 0-9: " << endl;

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

    CountingSort(myarray, size, range); // counting sort called

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }

    return 0;
}