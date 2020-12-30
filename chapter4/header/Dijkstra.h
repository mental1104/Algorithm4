#ifndef DIJKSTRAS_SHORTEST_PATHS_ALGORITHM_4_9
#define DIJKSTRAS_SHORTEST_PATHS_ALGORITHM_4_9

#include <queue>
#include <vector>
#include <list>
#include "EWDG.h"
#include "mapping.h"
using std::priority_queue;
using std::vector;
using std::list;

class DijkstraSP{
public:
    DijkstraSP(EdgeWeightedDigraph* G, int s);
    ~DijkstraSP();
    double distTo(int v) {  return _distTo[v]; }
    bool  hasPathTo(int v) {    return _distTo[v] < *reinterpret_cast<double*>(&infinity); }
    list<DirectedEdge*> pathTo(int v);
  

private:
    void relax(EdgeWeightedDigraph* G, int v);
    vector<DirectedEdge*> _edgeTo;
    vector<double> _distTo;
    priority_queue<mapping*, vector<mapping*>, cmp_prim> _pq;
    vector<mapping*> _vec; 
    unsigned long infinity = 0x7ff0000000000000;
};

DijkstraSP::DijkstraSP(EdgeWeightedDigraph* G, int s){
    _edgeTo.resize(G->V());
    _distTo.resize(G->V());
    _vec.resize(G->V());
    double inf = *reinterpret_cast<double*>(&infinity);
    for(int v = 0; v < G->V(); v++) 
        _distTo[v] = inf;
    _distTo[s] = 0.0;

    mapping* mp = new mapping(0, 0.0);

    _pq.push(mp);
    _vec.at(mp->_w) = mp;

    while(!_pq.empty()){
        mapping* temp = _pq.top();

        _pq.pop();
        for(auto iter = _vec.begin(); iter!=_vec.end(); iter++){
            if(*iter == temp) _vec.erase(iter);
            _vec.resize(G->V()); 
        }
            
        relax(G, temp->_w);
        delete temp;
    }
}

DijkstraSP::~DijkstraSP(){
    for(mapping* i: _vec)
        delete i;
}

void 
DijkstraSP::relax(EdgeWeightedDigraph* G, int v){
    for(DirectedEdge* e: G->adj(v)){
        int w = e->to();
        if(_distTo[w] > _distTo[v] + e->weight()){
            _distTo[w] = _distTo[v] + e->weight();
            _edgeTo[w] = e;
            if(_vec.at(w)!=nullptr) _vec.at(w)->_weight = _distTo[w];
            else{
                mapping* temp = new mapping(w, _distTo[w]);
                _pq.push(temp);
                _vec.at(w) = temp;
            }
        }
    }
}

list<DirectedEdge*> 
DijkstraSP::pathTo(int v){
    list<DirectedEdge*> path;
    if(!hasPathTo(v)) return path;
    for(DirectedEdge* e = _edgeTo[v]; e!=nullptr; e = _edgeTo[e->from()])
        path.push_front(e);
    return path;
}

#endif