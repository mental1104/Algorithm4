#ifndef LSD_STRING_SORT_5_1
#define LSD_STRING_SORT_5_1

#include<string>
using std::string;
#include<vector>
using std::vector;

class LSD{
public:
    static void sort(vector<string> &a, int W){
        int N = a.size();
        int R = 256;
        vector<string> aux;
        aux.resize(N);

        for(int d = W-1; d>=0; d--)
        {
            vector<int> count;
            count.resize(R+1);
            for(int i = 0; i<N; i++){
                string temp = a[i];
                unsigned char c = *(unsigned char*)&temp[d];
                count[c+1]++;
            }
            for(int r = 0; r<R; r++)
                count[r+1] += count[r];
            for(int i = 0; i<N; i++){
                string temp = a[i];
                unsigned char c = *(unsigned char*)&temp[d];
                aux[count[c]++] = a[i];
            }
            for(int i = 0; i<N; i++)
                a[i] = aux[i];
        }
    }
};

#endif