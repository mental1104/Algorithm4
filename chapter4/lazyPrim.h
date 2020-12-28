#ifndef LAZY_PRIM_IN_ALGORITHM_FOURTH
#define LAZY_PRIM_IN_ALGORITHM_FOURTH

#include <queue>
#include <vector>
#include "EWG.h"
#include "weightededge.h"

using namespace::std;

class LazyPrimMST{
public:
    LazyPrimMST(EdgeWeightedGraph* G);
    ~LazyPrimMST() { delete[] marked; }

    void visit(EdgeWeightedGraph* G, int v);
    vector<Edge*> edges() { return mst; }
    double weight();

private:
    bool* marked;
    vector<Edge*> mst;
    priority_queue<Edge*, vector<Edge*>, cmp> pq;
};

LazyPrimMST::LazyPrimMST(EdgeWeightedGraph* G){
    marked = new bool[G->V()];
    for(int i = 0; i < G->V(); i++)
        marked[i] = false;

    visit(G, 0);
    while(!pq.empty()){
        Edge* e = pq.top();
        pq.pop();

        int v = e->either(), w = e->other(v);
        if(marked[v] && marked[w]) continue;

        mst.push_back(e);
        if(!marked[v]) visit(G, v);
        if(!marked[w]) visit(G, w);
    }
}




void 
LazyPrimMST::visit(EdgeWeightedGraph* G, int v){
    marked[v] = true;
    for(Edge* e: G->adj(v))
        if(!marked[e->other(v)]) pq.push(e);
}

double
LazyPrimMST::weight(){
    double sum = 0;
    for(Edge* i: mst)
        sum += i->weight();
    return sum;
}
#endif