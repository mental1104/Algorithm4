#ifndef SHELL_SORT_2_3
#define SHELL_SORT_2_3

#include<vector>

using namespace::std;

class Shell{
public:
    static void sort(vector<int>& a){
        int N = a.size();
        int h = 1;
        while(h < N/3) h = 3*h + 1;
        while(h >= 1){
            for(int i = h; i<N; i++){
                for(int j = i; j>=h&&(a[j]<a[j-h]); j-=h){
                    int temp = a[j-h];
                    a[j-h]=a[j];
                    a[j] = temp;
                }
            }
            h = h/3;
        }
    }
};

#endif