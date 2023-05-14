#ifndef INSERTION_SORT_2_2
#define INSERTION_SORT_2_2

#include<vector>

using namespace::std;

class Insertion{
public:

    static void sort(vector<int> &a){
        int N = a.size();
        for(int i = 1; i < N; i++){
            for(int j = i;j>0&&(a[j]<a[j-1]);j--){
               int temp = a[j-1];
               a[j-1]=a[j];
               a[j]=temp; 
            }
        }
    }
};

#endif