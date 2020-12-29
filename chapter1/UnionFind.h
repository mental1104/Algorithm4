#ifndef UNIONFIND
#define UNIONFIND

#include<vector>
using std::vector;

class UnionFind{
private:
    vector<int> id;
    vector<int> sz;
    int count;

public:
    UnionFind(int N):count(N){
        id.resize(N);
        sz.resize(N,1);
        for(int i=0;i<id.size();i++)
            id[i]=i;
    }

    int countNum(){
        return count;
    }

    int findroot(int p){
        while(p!=id[p])
            p = id[p];
        return p;
    }

    bool connected(int p, int q){
        return findroot(p)==findroot(q);
    }

    void w_union(int p, int q){
        int i = findroot(p);
        int j = findroot(q);
        if(i==j) return;

        if(sz[i]<sz[j]){ id[i]=j; sz[j]+=sz[i]; }
        else           { id[j]=i; sz[i]+=sz[j]; }
        count--;
    }
};

#endif