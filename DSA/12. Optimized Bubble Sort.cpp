#include <iostream>
using namespace std;

void optimizedBubbleSort(int arr[], int n)
{
    int rounds = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        rounds++;
        for (int j = 0; j < (n - i - 1); j++)
        {

            if (arr[j + 1] < arr[j])
            {
                flag = true;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
    cout << "Number of rounds = " << rounds << endl;
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
    cout << endl
         << endl;

    optimizedBubbleSort(array, size);

    // after sorting
    cout << "\nAfter sorting elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}