#include <bits/stdc++.h>
using namespace std;

int maxFreq(int arr[], int size)
{
    int maxfreq = 0;
    int ans = 0;
    unordered_map<int, int> count;

    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
        maxfreq = max(maxfreq, count[arr[i]]);
    }

    for (int i = 0; i < size; i++)
    {
        if (maxfreq == count[arr[i]])
        {
            ans = arr[i];
            return ans;
        }
    }
}

int main()
{

    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int mf = maxFreq(arr, size);

    cout << mf << endl;

    return 0;
}