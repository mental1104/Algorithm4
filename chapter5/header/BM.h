#ifndef BOYER_MOORE_SUBSTRING_SEARCH_5_7
#define BOYER_MOORE_SUBSTRING_SEARCH_5_7

#include <string>
using std::string;
#include <vector>
using std::vector;

class BoyerMoore{
public:
    BoyerMoore(string pat);
    ~BoyerMoore(){}
    int search(string txt);
private:
    vector<int> _right;
    string _pat;
};

BoyerMoore::BoyerMoore(string pat):_pat(pat){
    int M = pat.length();
    int R = 256;
    _right.resize(256);
    for(int c = 0; c < R; c++)
        _right[c] = -1;
    for(int j = 0; j < M; j++)
        _right[pat[j]] = j;
}

int 
BoyerMoore::search(string txt){
    int N = txt.length();
    int M = _pat.length();
    int skip;
    for(int i = 0; i <= N-M; i+=skip){
        skip = 0;
        for(int j = M-1; j>=0; j--)
            if(_pat[j] != txt[i+j]){
                skip = j - _right[txt[i+j]];
                if (skip < 1) skip = 1;
                break;
            }
        if(skip == 0) return i;
    }
    return N;
}

#endif