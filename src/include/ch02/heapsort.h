#ifndef HEAP_SORT_2_7
#define HEAP_SORT_2_7

#include<vector>

using namespace::std;

class Heap{
public:
    static void sort(vector<int>& a);
private:
    static void exch(vector<int>& a, int lo, int hi);

    static void sink(vector<int>& a, int k, int size);
};

void 
Heap::exch(vector<int>& a, int lo, int hi){
    int temp = a[lo];
    a[lo] = a[hi];
    a[hi] = temp;
}

void 
Heap::sink(vector<int>& a, int k, int size){
    while(2*k<=size)
    {
        int j = 2*k;
        if(j<size && a[j]<a[j+1]) j++;
        if(!(a[k]<a[j])) break;
        exch(a, k, j);
        k = j;
    }
}

void 
Heap::sort(vector<int>& a){
    int size = a.size();
    for(int k = size/2;k>=1;k--)
        sink(a,k,size);
    while(size>1)
    {
        exch(a,1,size--);
        sink(a,1,size);
    }
}

#endif