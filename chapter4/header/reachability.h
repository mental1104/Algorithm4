#ifndef REACHABILITY_IN_DIGRAPHS_4_4
#define REACHABILITY_IN_DIGRAPHS_4_4

#include "./digraph.h"
#include "./dfs.h"
#include<vector>
#include<fstream>

using namespace::std;

class DirectedDFS : public DepthFirstPaths {
public:
    DirectedDFS(Digraph* G, int s);
    DirectedDFS(Digraph* G, vector<int> sources);
    virtual ~DirectedDFS(){}

private:
    virtual void dfs(Digraph* G, int v);

};

DirectedDFS::DirectedDFS(Digraph* G, int s){
    dfs(G, s);
}

DirectedDFS::DirectedDFS(Digraph* G, vector<int> sources){
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