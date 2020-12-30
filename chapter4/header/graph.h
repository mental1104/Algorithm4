#ifndef GRAPH_IN_ALGORITHM_FOURTH
#define GRAPH_IN_ALGORITHM_FOURTH


#include <iostream>
#include <vector>
#include <deque>

using namespace::std;

class Graph{
public:
    Graph(int V);
    Graph(istream& in);
    ~Graph(){}

    int V() { return _V; }
    int E() { return _E; }

    void addEdge(int v, int w);

    deque<int> adj(int v) { return _adj[v]; }

private:
    int readInt(istream&);
    int _V;
    int _E = 0;
    vector<deque<int>> _adj;
};

Graph::Graph(int V):_V(V){
    _E = 0;
    _adj.resize(V);
}

int
Graph::readInt(istream& in){
    int temp;
    in >> temp;
    return temp;
}
Graph::Graph(istream& in){

    _V = readInt(in);
    _adj.resize(_V);
    int E = readInt(in);
    for(int i =0; i < E; i++){
        int v = readInt(in);
        int w = readInt(in);
        addEdge(v, w);
    }

}

void
Graph::addEdge(int v, int w){
    _adj[v].push_front(w);
    _adj[w].push_front(v);//the critical difference compared with digraph
    _E++;
}

#endif