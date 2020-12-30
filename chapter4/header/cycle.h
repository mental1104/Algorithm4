#ifndef FINDING_A_DIRECTED_CYCLE
#define FINDING_A_DIRECTED_CYCLE

#include<list>
#include"digraph.h"

using namespace::std;

class DirectedCycle{
public:
    DirectedCycle(Digraph* G);
    ~DirectedCycle(){}

    bool hasCycle() {   return !_cycle.empty(); }
    deque<int> cycle()   {  return _cycle;  }


private:

    void dfs(Digraph* G, int v);

    deque<bool> _marked;
    deque<int> _edgeTo;
    deque<int> _cycle;//Since STL stack does not support iteration operation, try use list to mimic stack instead.  
    deque<bool> _onStack;
};


DirectedCycle::DirectedCycle(Digraph* G)
{
    _marked.resize(G->V());
    _edgeTo.resize(G->V());
    _onStack.resize(G->V());

    for(int i = 0; i<G->V(); i++){
        _onStack[i] = false;
        _marked[i] = false;
    }

    for(int v = 0; v<G->V(); v++)
        if(!_marked[v]) dfs(G, v);
}



void 
DirectedCycle::dfs(Digraph* G, int v){
    _onStack[v] = true;
    _marked[v] = true;
    for(int w: G->adj(v))
        if(hasCycle()) return;
        else if(!_marked[w]){
            _edgeTo[w] = v;
            dfs(G, w);
        }

        else if(_onStack[w]){
            for(int x = v; x != w; x = _edgeTo[x])
                _cycle.push_front(x);
            _cycle.push_front(w);
            _cycle.push_front(v);
        }
    _onStack[v] = false;
}
#endif