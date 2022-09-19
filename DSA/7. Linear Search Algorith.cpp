/*Linear Search Algorithm with C++ Code | Data Structures & Algorithms


In computer science, a linear search algorithm or sequential search is a method for finding an element within a list.
It sequentially checks each element of the list until a match is found or the whole list has been searched.


Suppose we have an integer array data structure with some values.We want to search for the value (98) which is at 5th position in
this array. Since we are performing the linear search algorithm we start from the beginning of the array and check for matching values
till we find a match.


Algorithm to perform Linear Search –

1.Take the input array arr[] from user.
2.Take element(x) you want to search in this array from user.
3.Set flag variable as -1
4.LOOP : arr[start] -> arr[end]
5.if match found i.e arr[current_postion] == x then
6.Print “Match Found at position” current_position.
7.flag = 0
8.abort
9.After loop check flag variable.
10.if flag == -1
11.print “No Match Found”
12.STOP


C++ Program to Implement Linear Search –*/

#include <iostream>
using namespace std;


void linearSearch(int a[], int n)
{
    int temp = -1;

    for (int i = 0; i < 5; i++)
    {
        if (a[i] == n)
        {
            cout << "Element found at position: " << i + 1 << endl;
            temp = 0;
            break;
        }
    }

    if (temp == -1)
    {
        cout << "No Element Found" << endl;
    }
}

int main()
{
    int arr[5];
    cout << "Please enter 5 elements of the Array" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    cout << "Please enter an element to search" << endl;
    int num;
    cin >> num;

    linearSearch(arr, num);

    return 0;
}




// #include <bits/stdc++.h>
// using namespace std;

// void linear_search(int a[], int n ,int size)
// {
//     int temp = -1;
//     for (int i = 0; i < size; i++)
//     {
//         if (a[i] == n)
//         {
//             cout << "Element found at position: " << i + 1 << endl;
//             temp = 0;
//             break;
//         }
//     }
//     if (temp == -1)
//     {
//         cout << "No Element Found" << endl;
//     }
// }

// int main()
// {
//     int num;
//     cout << "enter the rows of the array"<<endl;
//     cin >> num;

//     int *array = new int[num];

//     cout << "Enter the array elements"<<endl;
//     for (int i = 0; i < num; i++)
//     {
//         cin >> array[i];
//     }
//     cout << "Please enter an element to search" << endl;
//     int nu;
//     cin >>nu;

//     linear_search(array, nu,num);
// }

