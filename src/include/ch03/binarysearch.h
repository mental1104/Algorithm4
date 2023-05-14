#ifndef BINARY_SEARCH_3_2
#define BINARY_SEARCH_3_2

#include<vector>
#include<string>
#include<fstream>

using std::vector;
using std::string;
using std::ostream;
using std::endl;

class BinarySearchST{
private:
    vector<string> keys;
    vector<int> vals;
    int N = 0;

public:
    BinarySearchST(int capacity) { keys.resize(capacity), vals.resize(capacity); }

    int size(){ return N; }

    int rank(string key);

    int get(string key);

    void put(string key);

    string min() { return keys[0]; }

    string max() { return keys[N-1]; }

    string select(int k) {return keys[k]; }

    string ceiling(string key) { int i = rank(key); return keys[i]; }

    vector<string> region(string lo, string hi);

    void traverse(ostream& os);
};

int
BinarySearchST::rank(string key){
    int lo = 0, hi = N-1;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        int cmp = key.compare(keys[mid]);
        if      (cmp < 0) hi = mid-1;
        else if (cmp > 0) lo = mid+1;
        else return mid;
    }
    return lo;
}

int 
BinarySearchST::get(string key){
    if(keys.empty()) return -1;
    int i = rank(key);
    if(i < N && keys[i].compare(key) == 0) return vals[i];
    else                                   return -1;
}

vector<string>
BinarySearchST::region(string lo, string hi){
    vector<string> vec;
    for(int i = rank(lo); i < rank(hi); i++)
        vec.push_back(keys[i]);
    if(keys[rank(hi)] == hi)
        vec.push_back(keys[rank(hi)]);
    return vec;
}

void
BinarySearchST::put(string key){
    int i = rank(key);
    if(i < N && keys[i].compare(key) == 0){
        vals[i]++;
        return;
    }
    for(int j = N; j>i; j--){
        keys[j] = keys[j-1];
        vals[j] = vals[j-1];
    }
    keys[i] = key;
    vals[i] = 1;
    N++;
}

void 
BinarySearchST::traverse(ostream& os){
    for(int i = 0; i<N; i++)
        os << keys[i] << "\t\t\t\t" << vals[i] << endl;
}

#endif