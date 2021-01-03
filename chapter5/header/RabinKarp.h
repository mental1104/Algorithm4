#ifndef RABIN_KARP_FINGERPRINT_SUBSTRING_SEARCH
#define RABIN_KARP_FINGERPRINT_SUBSTRING_SEARCH

#include<string>
using std::string;

class RabinKarp{
public:
    RabinKarp(string pat);
    ~RabinKarp(){}
    bool check(string txt, int i);
    int search(string text);

private:
    long hash(string key, int M);
    
    string _pat;
    long _patHash;
    int M;
    long Q = 0x7FFFFFFF;//biggest prime num in 4 bytes long type.
    int R = 256;
    long RM;
};

bool
RabinKarp::check(string txt, int i){
    for (int j = 0; j < M; j++) 
        if (_pat[j] != txt[i + j]) 
            return false; 
    return true;
}

long
RabinKarp::hash(string key, int M){
    long h = 0;
    for (int j = 0; j<M; j++)
        h = (R * h + key[j]) % Q;
    return h;
}

RabinKarp::RabinKarp(string pat):_pat(pat),M(pat.length()){
    RM = 1;
    for(int i = 1; i <= M-1; i++)
        RM = (R * RM) % Q;
    _patHash = hash(_pat, M);
}

int
RabinKarp::search(string txt){
    int N = txt.length();
    long txtHash = hash(txt, M);
    if(_patHash == txtHash) return 0;
    for(int i = M; i < N; i++){
        txtHash = (txtHash + Q - RM*txt[i-M] % Q) % Q;
        txtHash = (txtHash*R + txt[i]) % Q;

        int offset = i - M + 1;
        if((_patHash == txtHash) && check(txt, offset))
            return offset;
    }
    return N;
}
#endif 