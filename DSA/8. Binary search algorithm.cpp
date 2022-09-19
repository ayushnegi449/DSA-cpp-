/* Binary Search Algorithm with C++ Code | Data Structures & Algorithms

Binary search algorithm falls under the category of interval search algorithms.This algorithm is much more efficient compared to 
linear search algorithm. Binary search only works on sorted data structures.This algorithm repeatedly target the center 
of the sorted data structure & divide the search space into half till the match is found.

The time complexity of binary search algorithm is O(Log n).

Working –
1. Search the sorted array by repeatedly dividing the search interval in half
2. Begin with an interval covering the whole array.
3. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
4. Otherwise narrow it to the upper half.
5. Repeatedly check until the value is found or the interval is empty.

Algorithm to perform Binary Search –
Take input array, left, right & x
START LOOP – while(left greater than or equal to right)
mid = left + (right-left)/2
if(arr[mid]==x) then
return m
else if(arr[mid] less than x) then
left = m + 1
else
right= mid – 1
END LOOP
return -1


C++ Program to Implement Binary Search – */

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int size;
    int search;
    cout << "Enter the size of the array : " << endl;
    cin >> size;
    int *array = new int[size];

    cout << "Enter " << size << " elements in ascending order : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "Now enter the element you want to search inside the entered array :" << endl;
    cin >> search;

    int output = binarySearch(array, 0, size - 1, search);

    if (output != -1)
    {
        cout << "The searched element : " << search << " is stored at index number : " << output << endl;
    }
    else
    {
        cout << "Searched element doesn't exist in the given array " << endl;
    }

    return 0;
}