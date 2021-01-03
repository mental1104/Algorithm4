#ifndef KNUTH_MORRIS_PRATT_SUBSTRING_SEARCH_5_6
#define KNUTH_MORRIS_PRATT_SUBSTRING_SEARCH_5_6

#include <string>
using std::string;
#include <vector>
using std::vector;

class KMP{
public:
    KMP(string pat);
    ~KMP(){}
    int search(string txt);
private:
    vector<vector<int>> _dfa;
    string _pat;
};

KMP::KMP(string pat):_pat(pat){
    int M = _pat.length(); 
    int R = 256;
    _dfa.resize(256);
    for(int i = 0; i<256; i++)
        _dfa[i].resize(M);
    _dfa[_pat[0]][0] = 1;
    for(int X = 0, j = 1; j < M; j++){
        for(int c = 0; c < R; c++){
            _dfa[c][j] = _dfa[c][X];
        }
        _dfa[_pat[j]][j] = j+1;
        X = _dfa[_pat[j]][X];
    }
}

int 
KMP::search(string txt){
    int i, j, N = txt.length(), M = _pat.length();
    for(i = 0, j = 0; i < N && j < M; i++){
        j = _dfa[txt[i]][j];
    }
    if (j == M) return i - M;
    else        return N;
}

#endif