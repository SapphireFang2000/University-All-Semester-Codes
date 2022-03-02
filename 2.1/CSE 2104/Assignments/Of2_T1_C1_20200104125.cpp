// Bubble Sort

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int array[], int n) 
{
  for (int j = 0; j < n - 1; j++) 
  {
    for (int i = 0; i < n - j - 1; i++) 
    {
      if (array[i] > array[i + 1]) 
      {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }

  cout << "Sorted Array in Ascending Order: ";

  for (int i = 0; i < n; i++) 
  {
    cout << array[i] << " ";
  }

  cout << endl;
}

int main() 
{
  int array[] = {-2, 45, 0, 11, -9};

  int size = sizeof(array) / sizeof(array[0]);

  bubbleSort(array, size);
}