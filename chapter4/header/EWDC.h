#ifndef EDGE_WEIGHT_DIRECTED_CYCLE
#define EDGE_WEIGHT_DIRECTED_CYCLE

#include <deque>
#include <cassert>
#include "EWDG.h"

using std::deque;
using std::cerr;
using std::cout;
using std::endl;

class EdgeWeightedDirectedCycle {
public:
    
    EdgeWeightedDirectedCycle(EdgeWeightedDigraph* G, int s);

    // check that algorithm computes either the topological order or finds a directed cycle
    void dfs(EdgeWeightedDigraph* G, int v);

    bool hasCycle() {  return !_cycle.empty(); }

    vector<DirectedEdge*> cycle() {  return _cycle; }

    deque<int> order() {    return _order;  }
    bool check();
private:
    deque<bool> _marked;             // marked[v] = has vertex v been marked?
    deque<DirectedEdge*> _edgeTo;        // edgeTo[v] = previous edge on path to v
    deque<bool> _onStack;            // onStack[v] = is vertex on the stack?
    vector<DirectedEdge*> _cycle;    // directed cycle (or null if no such cycle)
    deque<int> _order;

};

EdgeWeightedDirectedCycle::
EdgeWeightedDirectedCycle(EdgeWeightedDigraph* G, int s) {
    _marked.resize(G->V());
    _onStack.resize(G->V());
    _edgeTo.resize(G->V());
    for(int i = 0; i < G->V(); i++){
        _marked[i] = false;
        _onStack[i] = false;
    }

    dfs(G, s);

    for (int v = 0; v < G->V(); v++)
        if (!_marked[v]) dfs(G, v);

    // check that digraph has a cycle
    assert(check());
}

void 
EdgeWeightedDirectedCycle::dfs(EdgeWeightedDigraph* G, int v) {
    _onStack[v] = true;
    _marked[v] = true;
    for (DirectedEdge* e : G->adj(v)) {
        int w = e->to();

        // short circuit if directed cycle found
        if (!_cycle.empty()) {
            _order.clear();//if !hasCycle()  return the reverseOrder
            return;
        }

        // found new vertex, so recur
        else if (!_marked[w]) {
            _edgeTo[w] = e;
            dfs(G, w);
        }

        // trace back directed cycle
        else if (_onStack[w]) {
            DirectedEdge* f = e;
            while (f->from() != w) {
                _cycle.push_back(f);
                f = _edgeTo[f->from()];
                _cycle.push_back(f);
                return;
            }
        }
    }
    _onStack[v] = false;
    _order.push_front(v);
}

bool 
EdgeWeightedDirectedCycle::check() {
    if (hasCycle()) {
        // verify cycle
        DirectedEdge* first = nullptr, *last = nullptr;
        for (DirectedEdge* e : cycle()) {
            if (first == nullptr) first = e;
            if (last != nullptr) {
                if (last->to() != e->from()) {
                    cerr << "cycle edges " << last->toString() << " and " << e->toString() << " not incident\n" << endl;
                        return false;
                }
            }
            last = e;
        }

        if (last->to() != first->from()) {
            cerr << "cycle edges " << last->toString() << " and " << first->toString() << " not incident\n" << endl;
            return false;
        }
    }


    return true;
}

#endif