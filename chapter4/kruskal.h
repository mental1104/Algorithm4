#ifndef KRUSKAL_MST_4_8
#define KRUSKAL_MST_4_8

#include <vector>
#include <queue>
#include "weightededge.h"
#include "EWG.h"
#include "../chapter1/UnionFind.h"
using namespace::std;


class KruskalMST{
public:
    KruskalMST(EdgeWeightedGraph* G);
    vector<Edge*> edges() { return mst;}
    double weight();
private:
    vector<Edge*> mst;
    priority_queue<Edge*, vector<Edge*>, cmp> pq;
};


KruskalMST::KruskalMST(EdgeWeightedGraph* G){
    for(Edge* e: G->edges())
        pq.push(e);
    UnionFind* uf = new UnionFind(G->V());
    while(!pq.empty() && mst.size() < G->V()-1){
        Edge* e = pq.top();
        pq.pop();
        int v =e->either(), w = e->other(v);
        if(uf->connected(v,w)) 
            continue;
        uf->w_union(v ,w);
        mst.push_back(e);
    }
    delete uf;
    
}

double 
KruskalMST::weight(){
    double sum = 0.0;
    for(Edge* e: mst)
        sum += e->weight();
    return sum;
}

#endif