#ifndef DFS_TO_FIND_PATHS_4_1
#define DFS_TO_FIND_PATHS_4_1

#include "graph.h"
#include <deque>
using std::deque;

class DepthFirstPaths{

public:
    DepthFirstPaths(){}
    DepthFirstPaths(Graph* G, int s);

    virtual ~DepthFirstPaths(){}

    bool marked(int v) {     return _marked[v];   }

    deque<int> pathTo(int v);

protected:
    virtual void dfs(Graph* G, int v);

    deque<bool> _marked;
    deque<int> _edgeTo;
    int _s;
};

DepthFirstPaths::
DepthFirstPaths(Graph* G, int s):_s(s)
{   
    _marked.resize(G->V());
    _edgeTo.resize(G->V());
    dfs(G,s); 
}
void 
DepthFirstPaths::dfs(Graph* G, int v){
    _marked[v] = true;
    for(int i : G->adj(v))
        if(!_marked[i]){
            _edgeTo[i] = v;
            dfs(G, i);
        }
}

deque<int> 
DepthFirstPaths::pathTo(int v){
    deque<int> path;
    if(!marked(v)) return path;
    for (int x = v; x != _s; x = _edgeTo[x])
        path.push_front(x);
    path.push_front(_s);
    return path;
}

#endif