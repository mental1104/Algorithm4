#ifndef HEAP_MinPQ_2_6
#define HEAP_MinPQ_2_6

#include<vector>
#include<climits>

using namespace::std;

class MinPQ{
private:
    vector<int> pq;
    int N = 0;
    void exch(int lo, int hi){
        int temp = pq[lo];
        pq[lo] = pq[hi];
        pq[hi] = temp;
    }

    void exch(vector<int>& a, int lo, int hi){
        int temp = a[lo];
        a[lo] = a[hi];
        a[hi] = temp;
    }

    void swim(int k){
        while(k>1 && pq[k/2]>pq[k]){
            exch(k/2,k);
            k>>=1;
        }
    }

    void sink(int k){
        while(2*k<=N)
        {
            int j = 2*k;
            if(j<N && pq[j]>pq[j+1]) j++;
            if(!(pq[k]>pq[j])) break;
            exch(k, j);
            k = j;
        }
    }

    void sink(vector<int>& a, int k, int size){
        while(2*k<=size)
        {
            int j = 2*k;
            if(j<size && a[j]>a[j+1]) j++;
            if(!(a[k]>a[j])) break;
            exch(a, k, j);
            k = j;
        }
    }

    
public: 
    MinPQ() {}
    MinPQ(int maxN) { pq.resize(maxN+1); }

    bool isEmpty(){
        return N==0;
    }
    int size(){
        return N;
    }

    void insert(int v){
        pq[++N] = v;
        swim(N);
    }

    int delMin(){
        int min = pq[1];
        exch(1,N--);
        pq[N+1] = INT_MAX;
        sink(1);
        return min;
    }

    void sort(vector<int>& a){ //to make other vector can be heapsorted.
        int size = a.size();
        for(int k = size/2;k>=1;k--)
            sink(a,k,size);
        while(size>1)
        {
            exch(a,1,size--);
            sink(a,1,size);
        }
    }
};

#endif