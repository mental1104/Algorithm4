#ifndef THREE_WAY_STRING_QUICKSORT_5_3
#define THREE_WAY_STRING_QUICKSORT_5_3

#include <string>
using std::string;
#include <vector>
using std::vector;

class Quick3string{
public:
    void static sort(vector<string>& a) {  sort(a, 0, a.size()-1, 0); };
private:
    char static charAt(string s, int d);
    void static sort(vector<string>& a, int lo, int hi, int d);
    void static exch(vector<string>& a, int lo, int hi);
};

void 
Quick3string::exch(vector<string>& a, int lo, int hi){
    string temp = a[lo];
    a[lo] = a[hi];
    a[hi] = temp;
}

char 
Quick3string::charAt(string s, int d){
    if(d < s.size()) return s[d];
    else return -1;
}

void
Quick3string::sort(vector<string>& a, int lo, int hi, int d){
    if(hi <= lo) return;

    int lt = lo, gt = hi;
    int v = charAt(a[lo], d);
    int i = lo + 1;
    while(i <= gt)
    {
        int t = charAt(a[i], d);
        if      (t < v) exch(a, lt++, i++);
        else if (t > v) exch(a, i, gt--);
        else            i++;
    }

    sort(a, lo, lt-1, d);
    if(v >= 0) sort(a, lt, gt, d+1);
    sort(a, gt+1, hi, d);
}
#endif