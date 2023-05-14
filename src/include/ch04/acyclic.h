#ifndef SHORTEST_PATHS_IN_EDGE_WEIGHTED_DAGS_4_10
#define SHORTEST_PATHS_IN_EDGE_WEIGHTED_DAGS_4_10

#include <deque>
#include "./EWDG.h"
#include "topological.h"
using std::deque;

class AcyclicSP{
public:
    AcyclicSP(EdgeWeightedDigraph* G, int s);
    double distTo(int v) {  return _distTo[v]; }
    bool  hasPathTo(int v) {    return _distTo[v] < *reinterpret_cast<double*>(&infinity); }
    list<DirectedEdge*> pathTo(int v);
private:
    void relax(EdgeWeightedDigraph* G, int v);
    deque<DirectedEdge*> _edgeTo;
    deque<double>  _distTo;
    unsigned long infinity = 0x7ff0000000000000;

    
};

AcyclicSP::AcyclicSP(EdgeWeightedDigraph* G, int s){
    _edgeTo.resize(G->V());
    _distTo.resize(G->V());
    double inf = *reinterpret_cast<double*>(&infinity);
    for(int v = 0; v < G->V(); v++)
        _distTo[v] = inf;
    _distTo[s] = 0.0;
    Topological* top = new Topological(G, s);
    for(int v: top->order())
        relax(G, v);
}

void
AcyclicSP::relax(EdgeWeightedDigraph* G, int v){
    for(DirectedEdge* e : G->adj(v)){
        int w = e->to();
        if(_distTo[w] > _distTo[v] + e->weight()){
            _distTo[w] = _distTo[v] + e->weight();
            _edgeTo[w] = e;
        }
    }
}

list<DirectedEdge*> 
AcyclicSP::pathTo(int v){
    list<DirectedEdge*> path;
    if(!hasPathTo(v)) return path;
    for(DirectedEdge* e = _edgeTo[v]; e!=nullptr; e = _edgeTo[e->from()])
        path.push_front(e);
    return path;
}


#endif