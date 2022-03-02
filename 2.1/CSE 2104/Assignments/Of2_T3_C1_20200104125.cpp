//Insertion Sort.

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int array[], int n)
{
  for(int i=1; i<n; i++)
  {
    int temp=array[i];
    int j=i-1;
    while((temp<array[j])&&(j>=0))
    {
      array[j+1]=array[j];
      j=j-1;
    }
    array[j+1]=temp;
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

  insertionSort(array, size);
}