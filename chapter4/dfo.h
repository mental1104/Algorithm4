#ifndef DEPTH_FIRST_ORDER
#define DEPTH_FIRST_ORDER

#include<vector>
#include<list>

#include "./digraph.h"

using namespace::std;

class DepthFirstOrder{
public:
    DepthFirstOrder(Digraph* G);
    ~DepthFirstOrder(){ delete[] M;}

    vector<int> pre() { return pre_; }
    vector<int> post() { return post_; }
    list<int> reversePost() { return reversePost_; }

private:
    void dfs(Digraph* G, int v);

    bool* M;
    vector<int> pre_;
    vector<int> post_;//vector to mimic queue
    list<int> reversePost_;//list(push_front()) to mimic stack
};

DepthFirstOrder::DepthFirstOrder(Digraph* G){
    M = new bool[G->vertex()];
    for(int i = 0; i<G->vertex(); i++)
        M[i] = false;
    
    for(int v = 0; v<G->vertex(); v++)
        if(!M[v]) dfs(G, v);
}

void 
DepthFirstOrder::dfs(Digraph* G, int v){
    pre_.push_back(v);

    M[v] = true;
    auto temp = G->adjacent(v)->iter();
    while(temp!=nullptr){
        int w = temp->item;
        if(!M[w]) 
            dfs(G, w);
        temp = temp->next;
    }
    
    post_.push_back(v);
    reversePost_.push_front(v);
}

#endif