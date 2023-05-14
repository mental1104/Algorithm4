#ifndef HEAP_MaxPQ_2_6
#define HEAP_MaxPQ_2_6

#include<vector>
using std::vector;

class MaxPQ{
public: 
    MaxPQ() { }
    MaxPQ(int maxN) { pq.resize(maxN+1); }

    bool isEmpty(){  return N==0; }
    int size(){  return N;  }

    void insert(int v);

    int delMax();
private:
    vector<int> pq;
    int N = 0;
    void exch(int lo, int hi);

    void swim(int k);

    void sink(int k);
};

void 
MaxPQ::exch(int lo, int hi){
    int temp = pq[lo];
    pq[lo] = pq[hi];
    pq[hi] = temp;
}

void 
MaxPQ::swim(int k){
    while(k>1 && pq[k/2]<pq[k]){
        exch(k/2,k);
        k>>=1;
    }
}

void 
MaxPQ::sink(int k){
    while(2*k<=N)
    {
        int j = 2*k;
        if(j<N && pq[j]<pq[j+1]) j++;
        if(!(pq[k]<pq[j])) break;
        exch(k, j);
        k = j;
    }
}

void 
MaxPQ::insert(int v){ 
    pq[++N] = v;
    swim(N);
}

int 
MaxPQ::delMax(){
    int max = pq[1];
    exch(1,N--);
    auto iter = pq.begin()+N+1;
    pq.erase(iter);
    sink(1);
    return max;
}

#endif