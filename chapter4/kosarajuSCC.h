#ifndef KOSARAJUSCC_4_6
#define KOSARAJUSCC_4_6

#include "digraph.h"
#include "dfo.h"
#include<fstream>
#include<iostream>
#include<vector>

using namespace::std;

class KosarajuSCC{
public:
    KosarajuSCC(Digraph* G);
    ~KosarajuSCC();

    bool stronglyConnected(int v, int w) {  return _id[v]==_id[w]; }

    int id(int v) {   return _id[v];  } 
    int count() {   return _count;  }
    vector<vector<int>> strongComponents() {  return components; }
private:
    void dfs(Digraph* G, int v);
    bool* M;
    int* _id;
    int _count;
    vector<vector<int>> components;
    vector<int> tempVec;
};

KosarajuSCC::~KosarajuSCC(){
    delete[] M;
    delete[] _id;
}

KosarajuSCC::KosarajuSCC(Digraph* G):M(new bool[G->vertex()]), _id(new int[G->vertex()])
{
    DepthFirstOrder* order = new DepthFirstOrder(G->reverse());
    
    for(int s: order->reversePost()){
        if(!M[s]){
            dfs(G, s); 
            components.push_back(tempVec);
            tempVec.clear();//For iterator.
            _count++;
        }
    }
    delete order;
    order = nullptr;
}

void
KosarajuSCC::dfs(Digraph* G, int v){
    M[v] = true;
    _id[v] = _count;
    tempVec.push_back(v);
    auto temp = G->adjacent(v)->iter();
    while(temp!=nullptr){
        int w = temp->item;
        if(!M[w])
            dfs(G, w);
        temp = temp->next;
    }
}


#endif