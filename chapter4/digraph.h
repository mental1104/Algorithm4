#ifndef DIGRAPH_IN_ALGORITHM_FOURTH
#define DIGRAPH_IN_ALGORITHM_FOURTH  

#include "../chapter1/bag.h"
#include <iostream>

using namespace::std;

class Digraph{
private:
    int V;
    int E = 0;
    Bag<int>** adj;

    int readInt(istream& in);
public:
    Digraph(int V);
    Digraph(istream& in);
    ~Digraph();

    int vertex() {   return V; }
    int edge()  {   return E; }

    void addEdge(int v, int w);

    Bag<int>* adjacent(int v) { return adj[v]; }

    Digraph* reverse();

};

Digraph::Digraph(int vertex):V(vertex){
    adj = new Bag<int>*[vertex]();
    for(int v = 0; v < V; v++)
        adj[v] = new Bag<int>();
}

int
Digraph::readInt(istream& in){
    int temp;
    in >> temp;
    return temp;
}

Digraph::Digraph(istream& in){
    new (this)Digraph(readInt(in));
    int E = readInt(in);
    for(int i =0; i < E; i++){
        int v = readInt(in);
        int w = readInt(in);
        addEdge(v, w);
    }
}

Digraph::~Digraph(){
    for(int i = 0; i < V; i++)
        adj[i]->~Bag();
}
void
Digraph::addEdge(int v, int w){
    adj[v]->add(w);
    E++;
}

Digraph*
Digraph::reverse(){
    Digraph* R = new Digraph(V);
    for(int v = 0; v < V; v++){
        auto temp = this->adjacent(v)->iter();
        while(temp!=nullptr){
            int w = temp->item;
            R->addEdge(w, v);
        }
        temp = temp->next;
    }
    return R;    
}

#endif