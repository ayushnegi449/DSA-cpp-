/*Radix Sort Algorithm with C++ Code | Sorting Algorithms | Data Structures & Algorithms

DEFINITION
Radix sort is a non-comparative sorting algorithm. It avoids comparison by creating and distributing elements
into buckets according to their radix. For elements with more than one significant digit, this bucketing process
is repeated for each digit, while preserving the ordering of the prior step, until all digits have been considered.
For this reason, radix sort has also been called bucket sort and digital sort. Typically Radix sort uses counting
sort as a subroutine to sort. Radix sort has linear time complexity which is better than O(nlog n) of comparative
sorting algorithms.

Time complexity: O(d(n+k))
Space complexity: O(n+k)
Where d is the no of max digits of the largest no in the digit, n is the no of elements in the list and k is the range of unique elements.
Note - This time & space complexity is applicable for those Radix sort algorithms that use Counting Sort as sub routine internally.

Working -
Step 1 - Take input array and find MAX number in the array
Step 2 - Define 10 queues each representing a bucket for each digit from 0 to 9.
Step 3 - Consider the least significant digit of each number in the list which is to be sorted.
Step 4 - Insert each number into their respective queue based on the least significant digit.
Step 5 - Group all the numbers from queue 0 to queue 9 in the order they have inserted into their respective queues.
Step 6 - Repeat from step 3 based on the next least significant digit.
Step 7 - Repeat from step 2 until all the numbers are grouped based on the most significant digit.

Radix Sort Pseudocode

RadixSort(arr[], size) -

take input array & its size as - arr[size]

Get max element from this array
m = GetMax(arr, size)

Call counting sort d times based on the no of digits in the max number m.
for (int div = 1; m/div > 0; div *= 10)
CountingSort(arr, size, div)

Counting Sort Pseudocode
CountingSort(arr[], size, div) -

take arr[size]
create output array called - output[size]

take range (or no of unique elements. Default value 10 in our case)
create count array called - count[range] & initialize all values to 0

for(int i=0 to i<range)
count[i] = 0

Count each element & place it in the count[] array
for(int i = 0 to i<size)
count[ (arr[i]/div)%10 ]++

Modify count[] array to store previous counts (cumulative)
for(int i = 1 to i < range)
count[i] += count[i - 1];

Place elements from input array arr[] to output array output[] using this count[] array that has the actual positions of elements
for(int i=0 to i<size)
output[count[ (arr[i]/div)%10 ] - 1] = arr[i]
count[ (arr[i]/div)%10 ]–

Transfer sorted values from output[] array to input array arr[]
for(i=0 to i<size)
arr[i] = output[i]

C++ Program to Implement Radix Sort -*/

#include <iostream>
using namespace std;

int maxValue(int arr[], int size)
{
    int m = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > m)
        {
            m = arr[i];
        }
    }

    return m;
}

void countingSort(int arr[], int size, int div)
{
    int range = 10;
    int count_array[range] = {0};
    int output_array[size];

    for (int i = 0; i < size; i++)
    {
        ++count_array[(arr[i] / div) % 10];
    }

    for (int i = 1; i < range; i++)
    {
        count_array[i] = count_array[i] + count_array[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output_array[--count_array[(arr[i] / div) % 10]] = arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output_array[i];
    }
}

void radixSort(int arr[], int size)
{
    int max = maxValue(arr, size);

    for (int div = 1; (max / div) > 0; div *= 10)
    {
        countingSort(arr, size, div);
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

    radixSort(myarray, size); // counting sort called

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }

    return 0;
}