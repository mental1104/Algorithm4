#ifndef DFS_TO_FIND_PATHS_4_1
#define DFS_TO_FIND_PATHS_4_1

#include<memory>
#include "graph.h"
#include<list>

class DepthFirstPaths{

public:
    DepthFirstPaths(Graph* G, int source):marked(new bool[G->vertex()]),edgeTo(new int[G->vertex()]),s(source)
    {   
        for(int i = 0; i<G->vertex(); i++)
            marked[i] = false;
        dfs(G,source); 
    }

    ~DepthFirstPaths(){
        delete[] marked;
        delete[] edgeTo;
    }

    bool hasPathTo(int v) {     return marked[v];   }

    list<int> pathTo(int v){
        list<int> path;
        if(!hasPathTo(v)) return path;
        for (int x = v; x != s; x = edgeTo[x])
            path.push_front(x);
        path.push_front(s);
        return path;
    }

private:

    void dfs(Graph* G, int v){
        marked[v] = true;
        auto temp = G->adjacent(v)->iter();
        while(temp!=nullptr){
            int i = temp->item;
            if(!marked[i])
            {
                edgeTo[i] = v;
                dfs(G, i);
            }
            temp = temp->next;
        }
    }

    bool* marked;
    int *edgeTo;
    int s;
};

#endif