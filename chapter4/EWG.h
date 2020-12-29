#ifndef EDGE_WEIGHTED_GRAPH
#define EDGE_WEIGHTED_GRAPH

#include "weightededge.h"
#include <vector>

using std::istream;
using std::vector;

//generating Min Heap for the use of priority_queue<Edge*, vector<Edge*>, cmp>.   
struct cmp
{
    bool operator()(Edge* a,Edge* b)
    {
        if(a->weight() == b->weight())  return a->weight() >= b->weight();
        else return a->weight() > b->weight();
    }
};

class EdgeWeightedGraph{
public:
    EdgeWeightedGraph(int V):_V(V){ _adj.resize(V); }
    EdgeWeightedGraph(istream& in);
    ~EdgeWeightedGraph();
    int V() {   return _V;  }
    int E() {   return _E;  }
    void addEdge(Edge*);
    vector<Edge*> adj(int v) { return _adj[v]; } 
    vector<Edge*> edges();

private:
    int readInt(istream& in);
    double readDouble(istream &in);

    int _V;
    int _E = 0;
    vector<vector<Edge*>> _adj;
    Edge** edge;
};

EdgeWeightedGraph::
~EdgeWeightedGraph(){
    delete[] edge;
}
int
EdgeWeightedGraph::readInt(istream& in){
    int temp;
    in >> temp;
    return temp;
}

double
EdgeWeightedGraph::readDouble(istream& in){
    double temp;
    in >> temp;
    return temp;
}

vector<Edge*>
EdgeWeightedGraph::edges(){
    vector<Edge*> b;
    for(int v = 0; v < _V; v++)
        for(Edge* e: _adj[v])
            if(e->other(v) > v) b.push_back(e);
    return b;
}

void 
EdgeWeightedGraph::addEdge(Edge* e){
    int v = e->either(), w = e->other(v);
    _adj[v].push_back(e);
    _adj[w].push_back(e);
    _E++;
}

EdgeWeightedGraph::EdgeWeightedGraph(istream& in){
    _V = readInt(in);
    _adj.resize(_V);
    int E = readInt(in);
    edge = new Edge*[E];
    for(int i =0; i < E; i++){
        int v = readInt(in);
        int w = readInt(in);
        double x = readDouble(in);
        Edge* ptr = new Edge(v,w,x);
        edge[i] = ptr;
        addEdge(ptr);
    }
}



#endif