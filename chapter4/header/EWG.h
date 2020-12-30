#ifndef EDGE_WEIGHTED_GRAPH
#define EDGE_WEIGHTED_GRAPH

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <deque>

using std::istream;
using std::vector;
using std::string;
using std::ostringstream;
using std::deque;

class Edge{
public:
    Edge(int v, int w, double weight):_v(v),_w(w),_weight(weight){}
    double weight() {   return _weight;  }
    int either() {  return _v;  }
    int other(int vertex);
    int compareTo(Edge* that);
    string toString();
private:
    int _v;
    int _w;
    double _weight;
};


int 
Edge::other(int vertex){
    if      (vertex == _v) return _w;
    else if (vertex == _w) return _v;
    else throw std::runtime_error("No such data!");
}

int 
Edge::compareTo(Edge* that){
    if      (this->weight()<that->weight()) return -1;
    else if (this->weight()>that->weight()) return +1;
    else                                    return 0;
}

string
Edge::toString(){
    ostringstream ss;
    ss << _v << "-" << _w << " " << std::fixed << std::setprecision(2) << _weight;
    return ss.str();
}

struct cmp
{
    bool operator()(Edge* a,Edge* b)
    {
        if(a->weight() == b->weight())  return a->weight() >= b->weight();
        else return a->weight() > b->weight();
    }
};//generating Min Heap for the use of priority_queue<Edge*, vector<Edge*>, cmp>. 

class EdgeWeightedGraph{
public:
    EdgeWeightedGraph(int V):_V(V){ _adj.resize(V); }
    EdgeWeightedGraph(istream& in);
    ~EdgeWeightedGraph();
    int V() {   return _V;  }
    int E() {   return _E;  }
    void addEdge(Edge*);
    deque<Edge*> adj(int v) { return _adj[v]; } 
    deque<Edge*> edges();

private:
    int readInt(istream& in);
    double readDouble(istream &in);

    int _V;
    int _E = 0;
    vector<deque<Edge*>> _adj;
    Edge** edge;//make it easy to destruct.
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

deque<Edge*>
EdgeWeightedGraph::edges(){
    deque<Edge*> b;
    for(int v = 0; v < _V; v++)
        for(Edge* e: _adj[v])
            if(e->other(v) > v) b.push_back(e);
    return b;
}

void 
EdgeWeightedGraph::addEdge(Edge* e){
    int v = e->either(), w = e->other(v);
    _adj[v].push_front(e);
    _adj[w].push_front(e);
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