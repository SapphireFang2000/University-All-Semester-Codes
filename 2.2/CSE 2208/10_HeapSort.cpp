#include<bits/stdc++.h>

using namespace std;

int left_child(int parent){return (parent*2)+1;}
int right_child(int parent){return (parent*2)+2;}

void max_heapify(int heap[], int heap_size, int node)
{
    int large = node;
    int l = left_child(node);
    int r = right_child(node);

    if(l < heap_size && heap[l] > heap[large])
        large = l;

    if(r < heap_size && heap[r] > heap[large])
        large = r;

    if(large != node)
    {
        swap(heap[node],heap[large]);
        max_heapify(heap, heap_size, large);
    }
}

void build_max_heap(int heap[], int heap_size)
{
    for(int i = heap_size / 2 - 1; i >= 0; i--)
        max_heapify(heap, heap_size, i);
}

int main()
{
    int heap_size = 9;
    int heap[] = {12, 7, 19, 5, 10, 17, 1, 2, 3};

    build_max_heap(heap, heap_size);

    for(int i = heap_size - 1; i >= 0; i--)
    {
        swap(heap[0], heap[i]);
        max_heapify(heap, i, 0);
    }

    for(int i = 0; i < heap_size; i++)
        cout << heap[i] << " ";

    cout << endl;
}
