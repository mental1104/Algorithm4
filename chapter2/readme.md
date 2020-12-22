# Sort

`g++ sortTest.cpp`  
`./a.out`  

![conclusion](./conclusion.jpg)  


> For 32K random int: 

> [SelectionSort](./selectionsort.h):  3.60278s  

> [InsertionSort](./insertionsort.h):  4.17365s  0.86322 times faster than SelectionSort.  

> [ShellSort](./shellsort.h):  0.020904s  172.349 times faster than SelectionSort.  

> [MergeSort(BottomUp)](./mergesort.h):  0.011873s  303.443 times faster than SelectionSort.  

> [MergeSort(TopDown)](./mergesort.h):  0.012382s  290.969 times faster than SelectionSort.  

> [Quicksort](./quicksort.h):  0.010922s  329.864 times faster than SelectionSort.  

> [Quicksort(3way)](./quicksort.h):  0.017473s  206.191 times faster than SelectionSort.  

> [heapsort](./heapsort.h):  0.017072s  211.034 times faster than SelectionSort.  

## Some Important Conclusion  

### InsertionSort  

Average:    ~N^2/4 compares and ~N^2/4 exchanges  
worst case: ~N^2/4 compares and ~N^2/2 exchanges  
best case:   N-1   compares and 0      exchanges  

Owing to the times of its compare and exchange as O(n^2/4), InsertionSort is the best choice for small file.  

### ShellSort

> It's nothing but a optimized insertion sort.  

Shell is 600 times faster than Insertion.  

O(NlogN) on the average.  
unstable  
extra place O(1)  

### MergeSort  

Mergesort is a stable sorting algorithm.  

#### Top-down mergesort   
complexity: O(6NlogN)  
> 2N for copy  
> 2N for move back  
> at most 2N for compare  

Auxiliary space: O(N)  

#### Bottom-up mergesort  

benefit: non-recursive

1/2 NlgN - NlgN compares  
at most 6NlgN array accesses  

### QuickSort  

O(1.39NlgN) and unstable  
currently the fastest sorting algorithm  

### HeapSort 

O(NlgN)   
> 2NlgN + 2N compares  
> half that many changes  
  
It is rarely used in typical applications on modern systems because it has poor cache performance.   


