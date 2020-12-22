#ifndef MERGE_SORT_2_4
#define MERGE_SORT_2_4

#include<vector>

using namespace::std;

class BottomUpMerge{
private:
    vector<int> aux;
    static int min(int a, int b){
        if(a<b) return a;
        else return b;
    }
public:
    void merge(vector<int>&a, int lo, int mid, int hi){
        int i = lo, j = mid + 1;

        for(int k = lo; k<=hi;k++)
            aux[k] = a[k];
        for(int k = lo; k<=hi;k++)
            if      (i > mid)       a[k] = aux[j++];
            else if (j > hi)        a[k] = aux[i++];
            else if (aux[j]<aux[i]) a[k] = aux[j++];
            else                    a[k] = aux[i++];

    }

    void sort(vector<int>& a){
        int N = a.size();
        aux.resize(N);
        for(int sz=1;sz<N;sz<<=1)
            for(int lo=0;lo<N-sz;lo+=sz+sz)
                merge(a,lo,lo+sz-1,min(lo+sz+sz-1,N-1));

    }
};

class TopDownMerge{
private:
    vector<int> aux;

    void sort(vector<int>& a, int lo, int hi){
        if(hi<=lo) return;
        int mid = lo + (hi -lo)/2;
        sort(a,lo,mid);
        sort(a,mid+1,hi);
        merge(a,lo,mid,hi);
    }

public: 
    void merge(vector<int>&a, int lo, int mid, int hi){
        int i = lo, j = mid + 1;

        for(int k = lo; k<=hi;k++)
            aux[k] = a[k];
        for(int k = lo; k<=hi;k++)
            if      (i > mid)       a[k] = aux[j++];
            else if (j > hi)        a[k] = aux[i++];
            else if (aux[j]<aux[i]) a[k] = aux[j++];
            else                    a[k] = aux[i++];

    }

    void sort(vector<int>& a){
        aux.resize(a.size());
        sort(a,0,a.size()-1);
    }
};

#endif