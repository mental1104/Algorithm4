#ifndef QUICK_SORT_2_5
#define QUICK_SORT_2_5

#include<vector>
#include<random>
#include<chrono>
#include<algorithm>

using namespace::std;

class Quick{
private: 
    static int compareTo(int a,int b){
        if(a<b) return -1;
        else if(a>b) return 1;
        else return 0;
    }

    static void exch(vector<int>&a, int lo, int hi){
        int temp = a[lo];
        a[lo] = a[hi];
        a[hi] = temp;
    }
    
    static int partition(vector<int>& a,int lo, int hi){
        int i = lo, j = hi+1;
        int v = a[lo];
        while(true)
        {
            while(a[++i] < v) if(i==hi) break;
            while(v < a[--j]) if(j==lo) break;
            if(i>=j) break;

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        int temp = a[lo];
        a[lo] = a[j];
        a[j] = temp;
        return j;
    }

    static void sort(vector<int>& a, int lo, int hi){
        if(hi<=lo) return;
        int j = partition(a,lo,hi);
        sort(a,lo,j-1);
        sort(a,j+1,hi);
    }

    static void quick3way(vector<int>& a, int lo, int hi){
        if(hi<=lo) return;
        int lt = lo, i = lo+1, gt = hi;
        int v = a[lo];
        while(i<=gt)
        {
            int cmp = compareTo(a[i],v);
            if      (cmp<0) exch(a,lt++,i++);
            else if (cmp>0) exch(a,i,gt--);
            else            i++;
        }
        quick3way(a,lo,lt-1);
        quick3way(a,gt+1,hi);
    }


public:

    static void sort(vector<int>& a){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(a.begin(), a.end(), std::default_random_engine(seed));//shuffle the sequence.
        sort(a,0,a.size()-1);
    }

    static void quick3way(vector<int>& a){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(a.begin(), a.end(), std::default_random_engine(seed));//shuffle the sequence.
        quick3way(a,0,a.size()-1);
    }

};

#endif