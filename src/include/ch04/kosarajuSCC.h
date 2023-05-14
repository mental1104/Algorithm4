#ifndef KOSARAJUSCC_4_6
#define KOSARAJUSCC_4_6

#include "digraph.h"
#include "dfo.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace::std;

class KosarajuSCC{
public:
    KosarajuSCC(Digraph* G);
    ~KosarajuSCC(){}

    bool stronglyConnected(int v, int w) {  return _id[v]==_id[w]; }

    int id(int v) {   return _id[v];  } 
    int count() {   return _count;  }
    vector<vector<int>> strongComponents() {  return _components; }
private:
    void dfs(Digraph* G, int v);
    deque<bool> _marked;
    deque<int>  _id;
    int _count = 0;
    vector<vector<int>> _components;
    vector<int> _tempVec;
};



KosarajuSCC::KosarajuSCC(Digraph* G)
{
    _marked.resize(G->V());
    _id.resize(G->V());
    DepthFirstOrder* order = new DepthFirstOrder(G->reverse());
    
    for(int s: order->reversePost()){
        if(!_marked[s]){
            dfs(G, s); 
            _components.push_back(_tempVec);
            _tempVec.clear();//For iterator.
            _count++;
        }
    }
    delete order;
    order = nullptr;
}

void
KosarajuSCC::dfs(Digraph* G, int v){
    _marked[v] = true;
    _id[v] = _count;
    _tempVec.push_back(v);
    for(int w :G->adj(v))
        if(!_marked[w])
            dfs(G, w);
}


#endif