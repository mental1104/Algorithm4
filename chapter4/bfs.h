#ifndef BREADTH_FIRST_SEARCH_4_2
#define BREADTH_FIRST_SEARCH_4_2

#include <list>
#include <queue>
#include "graph.h"

class BreadthFirstPaths{
public:
    BreadthFirstPaths(Graph* G, int source):marked(new bool[G->vertex()]),edgeTo(new int[G->vertex()]),s(source){
        for(int i = 0; i<G->vertex(); i++)
            marked[i] = false;
        bfs(G,source); 
    }

    ~BreadthFirstPaths(){
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

    void bfs(Graph* G, int s){
        queue<int> q;
        marked[s] = true;
        q.push(s);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            auto temp = G->adjacent(v)->iter();
            while(temp!=nullptr){
                int i = temp->item;
                if(!marked[i]){
                    edgeTo[i] = v;
                    marked[i] = true;
                    q.push(i);
                }
                temp = temp->next;
            }

        }
    }

    bool* marked;
    int *edgeTo;
    int s;
};

#endif