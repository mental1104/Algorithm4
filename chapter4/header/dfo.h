#ifndef DEPTH_FIRST_ORDER
#define DEPTH_FIRST_ORDER

#include<deque>

#include "./digraph.h"

using std::deque;

class DepthFirstOrder{
public:
    DepthFirstOrder(Digraph* G);
    ~DepthFirstOrder(){}

    deque<int> pre() { return _pre; }
    deque<int> post() { return _post; }
    deque<int> reversePost() { return _reversePost; }

private:
    void dfs(Digraph* G, int v);

    deque<bool> _marked;
    deque<int> _pre;
    deque<int> _post;//vector to mimic queue
    deque<int> _reversePost;//list(push_front()) to mimic stack
};

DepthFirstOrder::DepthFirstOrder(Digraph* G){
    _marked.resize(G->V());
    for(int i = 0; i<G->V(); i++)
        _marked[i] = false;
    
    for(int v = 0; v<G->V(); v++)
        if(!_marked[v]) dfs(G, v);
}

void 
DepthFirstOrder::dfs(Digraph* G, int v){
    _pre.push_back(v);

    _marked[v] = true;
    for(int w: G->adj(v))
        if(!_marked[w]) 
            dfs(G, w);
    
    
    _post.push_back(v);
    _reversePost.push_front(v);
}

#endif