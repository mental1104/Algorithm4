#ifndef DFS_CONNCETIED_COMPONENTS_4_3
#define DFS_CONNCETIED_COMPONENTS_4_3

#include "./graph.h"
#include "./dfs.h"
#include <deque>

class CC : public DepthFirstPaths {
public:
    CC(Graph* G);
    virtual ~CC(){}

    bool connected(int v, int w);
    
    int id(int v){  return _id[v]; }

    int count(){ return _count;}

protected:
    virtual void dfs(Graph* G, int v);

    deque<int> _id;
    int _count = 0;
};

CC::CC(Graph* G){
    _marked.resize(G->V());
    _id.resize(G->V());
    for(bool& i:_marked)
        i = false;
    for(int s = 0; s<G->V(); s++)
        if(!_marked[s]){
            dfs(G,s);
            _count++;
        }
}


void
CC::dfs(Graph* G, int v){
    _marked[v] = true;
    _id[v] = _count;
    for(int w: G->adj(v))
        if(!_marked[w])
            dfs(G, w);
}

#endif