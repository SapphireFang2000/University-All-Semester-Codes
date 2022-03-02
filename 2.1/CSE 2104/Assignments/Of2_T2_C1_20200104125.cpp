//Selection Sort.

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int array[], int n)
{
  for(int j=0; j<n-1; j++)
  {
    int pos = j;
    int min = array[j];

    for(int i=j; i<n; i++)
    {
      if(array[i]<min)
      {
        min = array[i];
        pos = i;
      }
    }

    int temp = array[j];
    array[j] = array[pos];
    array[pos] = temp;
  }

  cout << "Sorted Array in Ascending Order: ";

  for(int i=0; i<8; i++)
  {
    cout << array[i] << " ";
  }

  cout << endl;
}

int main()
{
  int array[] = {4,2,7,5,1,8,6,3};

  int size = sizeof(array) / sizeof(array[0]);

  selectionSort(array, size);
}