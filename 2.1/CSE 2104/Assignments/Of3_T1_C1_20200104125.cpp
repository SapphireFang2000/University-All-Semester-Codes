//Merge Sort

#include<bits/stdc++.h>
using namespace std;

int a[11] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0 };
int b[10];

void merging(int low, int mid, int high)
{
    int l1, l2, i;

    for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
    {
        if(a[l1] <= a[l2])
        {
            b[i] = a[l1++];
        }
        else
        {
            b[i] = a[l2++];
        }
    }

    while(l1 <= mid)
    {
        b[i++] = a[l1++];
    }

    while(l2 <= high)
    {
        b[i++] = a[l2++];
    }

    for(i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void m_sort(int low, int high)
{
   int mid;

   if(low >= high)
   {
      return;
   }
   
   mid = (low + high) / 2;

   m_sort(low, mid);
   m_sort(mid+1, high);
   merging(low, mid, high);

}

int main()
{
   int i;

   m_sort(0, 10);

   for(i = 0; i < 11; i++)
   {
      cout << a[i] << " ";
   }

   cout << endl;
}