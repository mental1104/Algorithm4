#ifndef BELLMAN_FORD_ALGORITHM_4_11
#define BELLMAN_FORD_ALGORITHM_4_11

#include <deque>
#include <queue>
#include <vector>
#include "EWDG.h"
#include "EWDC.h"
using std::deque;
using std::queue;
using std::vector;

class BellmanFordSP{
public:
    BellmanFordSP(EdgeWeightedDigraph* G, int s);
    

    double distTo(int v) {  return _distTo[v]; }
    bool hasPathTo(int v) {    return _distTo[v] < *reinterpret_cast<double*>(&infinity); }
    deque<DirectedEdge*> pathTo(int v);

    bool hasNegativeCycle(){    return !_cycle.empty();  }
    vector<DirectedEdge*> negativeCycle() { return _cycle; }

private:
    void findNegativeCycle();
    void relax(EdgeWeightedDigraph* G, int v);

    deque<double> _distTo;
    deque<DirectedEdge*> _edgeTo;
    deque<bool> _onQ;
    queue<int> _queue;
    int _cost = 0;
    vector<DirectedEdge*> _cycle;
    unsigned long infinity = 0x7ff0000000000000;
};

BellmanFordSP::BellmanFordSP(EdgeWeightedDigraph* G, int s){
    _distTo.resize(G->V());
    _edgeTo.resize(G->V());
    _onQ.resize(G->V());
    double inf = *reinterpret_cast<double*>(&infinity);
    for(int v = 0; v < G->V(); v++)
        _distTo[v] = inf;
    _distTo[s] = 0.0;
    _queue.push(s);
    _onQ[s] = true;
    while(!_queue.empty() && !hasNegativeCycle()){
        int v = _queue.front();
        _queue.pop();
        _onQ[v] = false;
        relax(G,v);
    }

}

void 
BellmanFordSP::relax(EdgeWeightedDigraph* G, int v){
    for(DirectedEdge* e: G->adj(v)){
        int w = e->to();
        if(_distTo[w] > _distTo[v] + e->weight()){
            _distTo[w] = _distTo[v] + e->weight();
            _edgeTo[w] = e;
            if(!_onQ[w]){
                _queue.push(w);
                _onQ[w] = true;
            }
        }
        if(_cost++ % G->V() == 0)
            findNegativeCycle();
    }
}

deque<DirectedEdge*>
BellmanFordSP::pathTo(int v){
    deque<DirectedEdge*> path;
    if(!hasPathTo(v)) return path;
    for(DirectedEdge* e = _edgeTo[v]; e!=nullptr; e = _edgeTo[e->from()])
        path.push_front(e);
    return path;
}

void
BellmanFordSP::findNegativeCycle(){
    int V = _edgeTo.size();
    EdgeWeightedDigraph* spt = new EdgeWeightedDigraph(V);
    for(int v = 0; v < V; v++)
        if(_edgeTo[v] != nullptr)
            spt->addEdge(_edgeTo[v]);
    
    EdgeWeightedDirectedCycle* cf = new EdgeWeightedDirectedCycle(spt, 0);

    _cycle = cf->cycle();
}


#endif