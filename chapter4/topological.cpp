#ifndef TOPOLOGICAL_SORT_4_5
#define TOPOLOGICAL_SORT_4_5

#include<iostream>
#include<deque>
#include<fstream>
#include "./header/cycle.h"
#include "./header/dfo.h"
#include "./header/symboldigraph.h"

using namespace::std;

class Topological{
public:
    Topological(Digraph* G);

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

int main(int argc, char** argv){
    while(argc!=3){
        cout << "You must enter two extra parameters!" << endl;
        return 0;
    }

    SymbolDigraph* sg = new SymbolDigraph(argv[1], argv[2]);
    Topological* top = new Topological(sg->graph());

    for(int v: top->order())
        cout << sg->name(v) << endl;

    delete sg;
    sg = nullptr;
    delete top;
    top = nullptr;

    return 0;

}


#endif