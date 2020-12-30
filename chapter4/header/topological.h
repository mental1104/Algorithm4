#ifndef TOPOLOGICAL_SORT_4_5
#define TOPOLOGICAL_SORT_4_5

#include<iostream>
#include<deque>
#include<fstream>
#include "./cycle.h"
#include "./dfo.h"
#include "./symboldigraph.h"
#include "./EWDC.h"

using namespace::std;

class Topological{
public:
    Topological(Digraph* G);
    Topological(EdgeWeightedDigraph* G, int s);

    deque<int> order() {  return _order; }

    bool isDAG() {  return _order.empty(); }

private:
    deque<int> _order;
};

Topological::Topological(Digraph* G){
    DirectedCycle* cyclefinder = new DirectedCycle(G);
    if(!cyclefinder->hasCycle())
    {
        DepthFirstOrder* dfs = new DepthFirstOrder(G);
        _order = dfs->reversePost();
        delete(dfs);
        dfs = nullptr;
    }
    delete(cyclefinder);
    cyclefinder = nullptr;
}

Topological::Topological(EdgeWeightedDigraph* G, int s) {
    EdgeWeightedDirectedCycle* finder = new EdgeWeightedDirectedCycle(G,s);
    if (!finder->hasCycle()) 
        _order = finder->order();
    delete finder;
    finder = nullptr;
}


#endif