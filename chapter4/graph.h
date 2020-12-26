#ifndef GRAPH_IN_ALGORITHM_FOURTH
#define GRAPH_IN_ALGORITHM_FOURTH

#include"../chapter1/bag.h"
#include"iostream"

using namespace::std;

class Graph{
public:
    Graph(int V);
    Graph(istream& in);
    ~Graph();

    int vertex() { return V; }
    int edge() { return E; }

    void addEdge(int v, int w);

    Bag<int>* adjacent(int v) { return adj[v]; }



private:
    int readInt(istream&);
    int V;
    int E;
    Bag<int>** adj;
};

Graph::Graph(int V){
    this->V = V;
    this->E = 0;
    adj = new Bag<int>*[V]();
    for(int v = 0; v < V;v++)
        adj[v] = new Bag<int>();
}

Graph::~Graph(){
    for(int i = 0; i < V; i++)
        adj[i]->~Bag();
}

int
Graph::readInt(istream& in){
    int temp;
    in >> temp;
    return temp;
}
Graph::Graph(istream& in){

    new (this)Graph(readInt(in));
    int E = readInt(in);
    for(int i =0; i < E; i++){
        int v = readInt(in);
        int w = readInt(in);
        addEdge(v, w);
    }

}

void
Graph::addEdge(int v, int w){
    adj[v]->add(w);
    adj[w]->add(v);//the critical difference compared with digraph
    E++;
}

#endif