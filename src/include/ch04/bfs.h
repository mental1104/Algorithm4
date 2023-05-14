#ifndef BREADTH_FIRST_SEARCH_4_2
#define BREADTH_FIRST_SEARCH_4_2

#include <list>
#include <queue>
#include "graph.h"

using std::list;
using std::queue;

class BreadthFirstPaths{
public:
    BreadthFirstPaths(Graph* G, int source);

    ~BreadthFirstPaths(){
        delete[] _marked;
        delete[] _edgeTo;
    }

    bool marked(int v) {     return _marked[v];   }

    list<int> pathTo(int v);

private:

    void bfs(Graph* G, int s);

    bool* _marked;
    int * _edgeTo;
    int s;
};

BreadthFirstPaths::
BreadthFirstPaths(Graph* G, int source):_marked(new bool[G->V()]),_edgeTo(new int[G->V()]),s(source){
    for(int i = 0; i<G->V(); i++)
        _marked[i] = false;
    bfs(G,source); 
}

void 
BreadthFirstPaths::bfs(Graph* G, int s){
    queue<int> q;
    _marked[s] = true;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i : G->adj(v)){
            if(!_marked[i]){
                _edgeTo[i] = v;
                _marked[i] = true;
                q.push(i);
            }
        }
    }
}

list<int> 
BreadthFirstPaths::pathTo(int v){
    list<int> path;
    if(!marked(v)) return path;
    for (int x = v; x != s; x = _edgeTo[x])
        path.push_front(x);
    path.push_front(s);
    return path;

}


#endif