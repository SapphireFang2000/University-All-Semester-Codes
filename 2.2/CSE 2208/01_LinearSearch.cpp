#include <bits/stdc++.h>
using namespace std;

int search(int array[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if(array[i] == x)
        {
            return i+1;
        }
    }
    return -1;
}

int main()
{
    int array[] = {2, 4, 0, 1, 9};
    int x;

    cout << "Enter the Number You Want to Search: ";
    cin >> x;
    
    int n = sizeof(array) / sizeof(array[0]);

    int result = search(array, n, x);

    if(result == -1) 
    {
        cout << "Element Not Found" << endl;
    }
    else
    {
        cout << "Element Found at Index: " << result << endl;
    }
}
