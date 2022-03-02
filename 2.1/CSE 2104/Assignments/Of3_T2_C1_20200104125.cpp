//Quick Sort

#include<bits/stdc++.h>
using namespace std;

int arr[10] = {10, 16, 8, 12, 15, 6, 3, 9, 5, 9999};

int partition(int low, int high)
{
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    int temp=0;

    while(i<=j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }

        while(arr[j]>pivot)
        {
            j--;
        }

        if(i<=j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}

void quickSort(int low, int high)
{
    if(low < high)
    {
        int pos = partition(low, high);

        quickSort(low, pos);
        quickSort(pos+1, high);
    }
}

int main()
{
    quickSort(0,9);

    for(int i=0; i<9; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
