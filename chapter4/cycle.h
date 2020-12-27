#ifndef FINDING_A_DIRECTED_CYCLE
#define FINDING_A_DIRECTED_CYCLE

#include<list>
#include"digraph.h"

using namespace::std;

class DirectedCycle{
public:
    DirectedCycle(Digraph* G);
    ~DirectedCycle();

    bool hasCycle() {   return !cycle.empty(); }
    list<int> cycle_list()   {  return cycle;  }


private:

    void dfs(Digraph* G, int v);
    bool* M;
    int* edgeTo;
    list<int> cycle;//Since STL stack does not support iteration operation, try use list to mimic stack instead.  
    bool* onStack;
};

DirectedCycle::
DirectedCycle(Digraph* G):onStack(new bool[G->vertex()]),edgeTo(new int[G->vertex()]),
                          M(new bool[G->vertex()])
{
    for(int i = 0; i<G->vertex(); i++){
        onStack[i] = false;
        M[i] = false;
    }

    for(int v = 0; v<G->vertex(); v++)
        if(!M[v]) dfs(G, v);
}

DirectedCycle::
~DirectedCycle(){
    delete[] edgeTo;
    delete[] M;
    delete[] onStack;
}

void
DirectedCycle::dfs(Digraph* G, int v){
    onStack[v] = true;
    M[v] = true;
    auto temp = G->adjacent(v)->iter();
    while(temp!=nullptr){
        int w = temp->item;
        if(hasCycle()) return;

        else if(!M[w]){
            edgeTo[w] = v;
            dfs(G, w);
        }

        else if(onStack[w]){
            for(int x = v; x != w; x = edgeTo[x])
                cycle.push_front(x);
            cycle.push_front(w);
            cycle.push_front(v);
        }

        temp = temp->next;
    }
    onStack[v] = false;
}
#endif