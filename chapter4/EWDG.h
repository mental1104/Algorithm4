#ifndef EDGE_WEIGHTED_DIGRAPH_DATA_TYPE
#define EDGE_WEIGHTED_DIGRAPH_DATA_TYPE

#include <iostream>
#include <vector>
#include "directededge.h"
using std::istream;
using std::vector;



class EdgeWeightedDigraph{
public:
    EdgeWeightedDigraph(int V):_V(V){ _adj.resize(V); }
    EdgeWeightedDigraph(istream& in);
    ~EdgeWeightedDigraph() {    delete[] edge; }
    int V() {   return _V; }
    int E() {   return _E; }
    void addEdge(DirectedEdge* e);
    vector<DirectedEdge*> adj(int v) { return _adj[v]; }  
    vector<DirectedEdge*> edges();

private:
    int readInt(istream& in);
    double readDouble(istream& in);

    int _V;
    int _E = 0;
    vector<vector<DirectedEdge*>> _adj;
    DirectedEdge** edge;//make it easy to destruct.
};

EdgeWeightedDigraph::
EdgeWeightedDigraph(istream& in){
    _V = readInt(in);
    _adj.resize(_V);
    int E = readInt(in);
    edge = new DirectedEdge*[E];
    for(int i = 0; i < E; i++){
        int v = readInt(in);
        int w = readInt(in);
        double x = readDouble(in);
        DirectedEdge* ptr = new DirectedEdge(v,w,x);
        edge[i] = ptr;
        addEdge(ptr);
    }
    
}

int
EdgeWeightedDigraph::readInt(istream& in){
    int temp;
    in >> temp;
    return temp;
}

double
EdgeWeightedDigraph::readDouble(istream& in){
    double temp;
    in >> temp;
    return temp;
}


void
EdgeWeightedDigraph::addEdge(DirectedEdge* e){
    int index = e->from();
    _adj[index].push_back(e);
    _E++;
}

vector<DirectedEdge*> 
EdgeWeightedDigraph::edges(){
    vector<DirectedEdge*> vec;
    for(int v = 0; v < _V; v++)
        for(DirectedEdge* e: _adj[v])
            vec.push_back(e);
    return vec;
}

#endif