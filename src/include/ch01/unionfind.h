#ifndef UNIONFIND
#define UNIONFIND

#include<vector>
using std::vector;

class UnionFind{
public:
    UnionFind(int N);
    ~UnionFind() { delete[] id; delete[] sz; }
    

    int countNum(){ return count; }

    int findroot(int p);

    bool connected(int p, int q){   return findroot(p)==findroot(q);  }

    void w_union(int p, int q);

private:
    int* id;
    int* sz;
    int count;
};

UnionFind::UnionFind(int N):count(N){
    id = new int[N];
    sz = new int[N];
    for(int i=0;i<N;i++)
        id[i]=i;
}

int 
UnionFind::findroot(int p){
    while(p!=id[p])
        p = id[p];
    return p;
}

void 
UnionFind::w_union(int p, int q){
    int i = findroot(p);
    int j = findroot(q);
    if(i==j) return;

    if(sz[i]<sz[j]){ id[i]=j; sz[j]+=sz[i]; }
    else           { id[j]=i; sz[i]+=sz[j]; }
    count--;
}

#endif