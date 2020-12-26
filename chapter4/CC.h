#ifndef DFS_CONNCETIED_COMPONENTS_4_3
#define DFS_CONNCETIED_COMPONENTS_4_3

#include "graph.h"

class CC{
public:
    CC(Graph* G);
    ~CC();

    bool connected(int v, int w);
    
    int id(int v){  return i[v]; }

    int count(){ return c;}

private:
    void dfs(Graph* G, int v);

    bool* marked;
    int* i;
    int c;
};

CC::CC(Graph* G){
    marked = new bool[G->vertex()];
    for(int i = 0; i<G->vertex(); i++)
        marked[i] = false;
    i = new int[G->vertex()];
    for(int s = 0; s<G->vertex(); s++)
        if(!marked[s]){
            dfs(G,s);
            c++;
        }
}

CC::~CC(){
    delete[] marked;
    delete[] i;
}

void
CC::dfs(Graph* G, int v){
    marked[v] = true;
    i[v] = c;
    auto temp = G->adjacent(v)->iter();
    while(temp!=nullptr){
        int w = temp->item;
        if(!marked[w])
            dfs(G, w);
        temp = temp->next;
    }
}
#endif