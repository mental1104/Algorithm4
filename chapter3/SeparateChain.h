#ifndef HASH_TABLE_SEPARATE_CHAIN_3_5
#define HASH_TABLE_SEPARATE_CHAIN_3_5

#include<vector>
#include<string>
#include<fstream>

using namespace::std;

struct S_Entry{
    string key;
    int val;
    S_Entry* next;
    S_Entry(string k, int i, S_Entry* e):key(k),val(i),next(e){}
};

class SeparateChain{
private:
    int N;
    int M;
    S_Entry** st;

    int hashCode(string key);

public:
    SeparateChain():SeparateChain(997){}
    SeparateChain(int M);
    ~SeparateChain();

    int get(string key);

    void put(string key);

    void traverse(ofstream& os);
};

SeparateChain::SeparateChain(int capacity):M(capacity){
    st = new S_Entry*[M];
    for(int i = 0; i < M; i++)
        st[i] = nullptr;
}

SeparateChain::~SeparateChain(){
    for(int i = 0; i < M; i++)
        for(S_Entry* iter = st[i]; iter!=nullptr;){
            S_Entry* old = iter;
            iter = iter->next;
            delete(old);
        }
}

int
SeparateChain::hashCode(string key){
    int seed = 17;
    int hash = 0;
    for(auto iter = key.cbegin(); iter!=key.cend(); iter++)
        hash = hash*seed + *iter;
    return (hash & 0x7FFFFFFF)%M;
}

void
SeparateChain::put(string key){
    if(st[hashCode(key)]==nullptr){
        st[hashCode(key)] = new S_Entry(key,1,nullptr);
        return;
    }


    S_Entry* iter = st[hashCode(key)];

    if(key == iter->key){
        iter->val++;
        return;
    }
    
    while(iter->next!=nullptr){
        if(iter->next->key == key){
            iter->next->val++;
            return;
        }
        iter = iter->next;
    }

    iter->next = new S_Entry(key,1,nullptr);
}

int
SeparateChain::get(string key){
    S_Entry* iter = st[hashCode(key)];

    while(iter!=nullptr){
        if(key == iter->key)
            return iter->val;
        iter = iter->next;
    }
    
    return -1;
}

void 
SeparateChain::traverse(ofstream& os){
    for(int i = 0; i < M; i++){
        S_Entry* iter = st[i];
        while(iter!=nullptr){
            os << iter->key << "\t\t\t\t" << iter->val << endl;
            iter = iter->next;
        }
    }
}

#endif