#include<stdio.h>
int left(int i)
{
    return 2 * i;
}
int right(int i)
{
    return 2 * i + 1;
}

int parent(int i)
{
    return i / 2;
}

void max_heapify(int heap[], int heap_size, int i)
{
    int l,r,largest, t;
    l = left(i);
    r = right(i);

    if(l <= heap_size && heap[l] > heap[i]){
        largest = l;
    }else{
        largest = i;
    }

    if(r <= heap_size && heap[r] > heap[largest]){
        largest = r;
    }

    if(largest != i){
        t = heap[i];
        heap[i] = heap[largest];
        heap[largest] = t;
        max_heapify(heap, heap_size, largest);
    }
}

void build_max_heap(int heap[], int heap_size)
{
    int i;
    for(i = heap_size / 2; i >= 1; i--)
    {
        max_heapify(heap, heap_size, i);
    }
}

void print_heap(int heap[], int heap_size)
{
    int i;
    for(i = 1; i <= heap_size; i++){
        printf("%d ", heap[i]);
    }
    printf("\n\n");
}

int main()
{
    int heap_size = 9;
    int heap[] = {0,12,7,1,3,10,17,19,2,5};

    print_heap(heap, heap_size);

    max_heapify(heap, heap_size, 5);
    print_heap(heap, heap_size);

    build_max_heap(heap, heap_size);
    print_heap(heap, heap_size);

    return 0;
}
