//Find a Alphabet Using Binary Search.

#include <bits/stdc++.h>
using namespace std;

char a[]={'a','b','c','d','h','m','p','r','w','y','z'};

void search(char n)
{
    int start=0, end=sizeof(a), mid;
    while(start<=end)
    {
        mid = (start+end)/2;
        if(a[mid] == n)
        {
            cout << "Found at position " << mid+1 << endl;
            break;
        }
        else if(a[mid]<n)
            start=mid+1;
        else
            end=mid-1;
    }

    if(end<start)
    {
        cout << "Not Found" << endl;
    }
}

int main()
{
    char key;

    cout << "Enter An Alphabet : ";
    cin >> key;

    search(key);
    
    return 0;
}
