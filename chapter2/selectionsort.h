#ifndef SELECTION_SORT_2_1
#define SELECTION_SORT_2_1

#include<vector>

using namespace::std;

class Selection{
public:
    static void sort(vector<int> &a){
        int N = a.size();
        for(int i =0; i<N; i++){
            int min = i;
            for(int j=i+1; j<N; j++)
                if(a[j]<a[min]) min =j;
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
};

#endif