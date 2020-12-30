#ifndef LAZY_PRIM_IN_ALGORITHM_FOURTH
#define LAZY_PRIM_IN_ALGORITHM_FOURTH

#include <queue>
#include <deque>
#include <vector>
#include "EWG.h"

using namespace::std;

class LazyPrimMST{
public:
    LazyPrimMST(EdgeWeightedGraph* G);
    ~LazyPrimMST() {}

    void visit(EdgeWeightedGraph* G, int v);
    vector<Edge*> edges() { return _mst; }
    double weight();

private:
    deque<bool> _marked;
    vector<Edge*> _mst;
    priority_queue<Edge*, vector<Edge*>, cmp> _pq;
};

LazyPrimMST::LazyPrimMST(EdgeWeightedGraph* G){
    _marked.resize(G->V());
    for(int i = 0; i < G->V(); i++)
        _marked[i] = false;

    visit(G, 0);
    while(!_pq.empty()){
        Edge* e = _pq.top();
        _pq.pop();

        int v = e->either(), w = e->other(v);
        if(_marked[v] && _marked[w]) continue;

        _mst.push_back(e);
        if(!_marked[v]) visit(G, v);
        if(!_marked[w]) visit(G, w);
    }
}




void 
LazyPrimMST::visit(EdgeWeightedGraph* G, int v){
    _marked[v] = true;
    for(Edge* e: G->adj(v))
        if(!_marked[e->other(v)]) _pq.push(e);
}

double
LazyPrimMST::weight(){
    double sum = 0;
    for(Edge* i: _mst)
        sum += i->weight();
    return sum;
}
#endif