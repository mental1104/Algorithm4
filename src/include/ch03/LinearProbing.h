#ifndef HASH_TABLE_LINEAR_PROBING_3_6
#define HASH_TABLE_LINEAR_PROBING_3_6

#include<string>

using namespace::std;

struct Entry{
    string key;
    int val;
    Entry():key("-1"),val(-1){}
    Entry& operator=(const Entry& rhs){
        this->key = rhs.key;
        this->val = rhs.val;
        return *this;
    }
};

class LinearProbing{
public:
    int N = 0;
    int M = 16;
    Entry* entry;

    int hashCode(string key);

    void resize(int cap);

public:

    LinearProbing() {   entry = new Entry[M](); }
    ~LinearProbing() {  delete[] entry; }
    
    //void put(Entry* c, string key);

    void put(string key);

    int get(string key);

    void traverse(ostream& os);

};

void 
LinearProbing::resize(int cap){
    Entry* t = new Entry[cap]();
    for(int i = 0; i < M; i++)
        if(entry[i].key!="-1")
            t[i] = entry[i];
    delete[] entry;
    entry = t;
    M = cap;
}

int
LinearProbing::hashCode(string key){
    int seed = 17;
    int hash = 0;
    for(auto iter = key.cbegin(); iter!=key.cend(); iter++)
        hash = hash*seed + *iter;
    return (hash & 0x7FFFFFFF)%M;
}

void 
LinearProbing::put(string key){
    if(N > M/2) resize(2*M);

    int i;
    for(i = hashCode(key); entry[i].key!="-1"; i = (i + 1)%M){
        if(entry[i].key == key) entry[i].val++;
        return;
    }
    entry[i].key = key;
    entry[i].val = 1;
    N++;
}

/*
void 
LinearProbing::put(Entry* t, string key){
    int i;
    for(i = hashCode(key); t[i].key!="-1"; i = (i + 1)%M){
        if(t[i].key == key) t[i].val++;
        return;
    }
    t[i].key = key;
    t[i].val = 1;
}*/

int
LinearProbing::get(string key){
    int i;
    for(i = hashCode(key); entry[i].key!="-1"; i = (i + 1)%M)
        if(entry[i].key == key) return entry[i].val;
    return -1;
}

void
LinearProbing::traverse(ostream& os){
    for(int i = 0; i<M; i++)
        os << entry[i].key << "\t\t\t\t" << entry[i].val << endl;
}

#endif