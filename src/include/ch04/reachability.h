#ifndef REACHABILITY_IN_DIGRAPHS_4_4
#define REACHABILITY_IN_DIGRAPHS_4_4

#include "./digraph.h"
#include "./dfs.h"
#include<deque>
#include<fstream>

using namespace::std;

class DirectedDFS : public DepthFirstPaths {
public:
    DirectedDFS(Digraph* G, int s);
    DirectedDFS(Digraph* G, deque<int> sources);
    virtual ~DirectedDFS(){}

private:
    virtual void dfs(Digraph* G, int v);

};

DirectedDFS::DirectedDFS(Digraph* G, int s){
    _marked.resize(G->V());
    dfs(G, s);
}

DirectedDFS::DirectedDFS(Digraph* G, deque<int> sources){
    for(int s: sources)
        if(!_marked[s]) dfs(G, s);
}

void
DirectedDFS::dfs(Digraph* G, int v){
    _marked[v] = true;
    for(int w : G->adj(v))
        if(!_marked[w]) dfs(G, w);

}

#endif