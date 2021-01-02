#ifndef MSD_STRING_SORT_5_2
#define MSD_STRING_SORT_5_2

#include <vector>
#include <string>
using std::vector;
using std::string;

class MSD{
public:
    void sort(vector<string>& a);
private:
    void sort(vector<string>& a, int lo, int hi, int d);

    void insertionSort(vector<string>& a, int lo, int hi, int d);

    bool less(string v, string w, int d);
    char charAt(string s, int d);
    int R = 256;
    const int M = 15;
    vector<string> aux;
};

void
MSD::sort(vector<string>& a){
    int N = a.size();
    aux.resize(N);
    sort(a, 0, N-1, 0);
}

void
MSD::insertionSort(vector<string>& a, int lo, int hi, int d){
    for(int i = lo; i<=hi; i++)
        for(int j = i; j > lo && less(a[j], a[j-1], d); j--){
            string temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
        }
}

bool
MSD::less(string v,string w, int d){
    return v.substr(d) < w.substr(d);
}

void 
MSD::sort(vector<string>& a, int lo, int hi, int d){
    if(hi <= lo + M){
        insertionSort(a,lo,hi,d);
        return;
    }
    vector<int> count;
    count.resize(R+2);
    for(int i = lo; i <= hi; i++)
        count[charAt(a[i], d)+2]++;
    for(int r = 0; r < R+1; r++)
        count[r+1] += count[r];
    for(int i = lo; i <= hi; i++)
        aux[count[charAt(a[i],d)+1]++] = a[i];
    for(int i = lo; i <=hi; i++)
        a[i] = aux[i - lo];

    for(int r = 0; r < R; r++)
        sort(a, lo + count[r], lo + count[r+1]-1, d+1);
}

char
MSD::charAt(string s, int d){
    if(d < s.length()){
        return s[d];
    }else
        return -1;
}

#endif