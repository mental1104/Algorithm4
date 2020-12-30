#ifndef DIGRAPH_IN_ALGORITHM_FOURTH
#define DIGRAPH_IN_ALGORITHM_FOURTH  

#include <iostream>
#include <vector>
#include <deque>

using std::vector;
using std::istream;
using std::deque;
using std::endl;

class Digraph {
public:
    Digraph(int V):_V(V){ _adj.resize(_V); }
    Digraph(istream& in);
    ~Digraph(){}

    int V() { return _V; }
    int E() { return _E; }

    void addEdge(int v, int w);

    deque<int> adj(int v) { return _adj[v]; }

    Digraph* reverse();

    
private:
    int readInt(istream&);
    int _V;
    int _E = 0;
    vector<deque<int>> _adj;
};

Digraph::Digraph(istream& in){
    _V = readInt(in);
    _adj.resize(_V);
    int E = readInt(in);
    for(int i =0; i < E; i++){
        int v = readInt(in);
        int w = readInt(in);
        addEdge(v, w);
    }
}

int
Digraph::readInt(istream& in){
    int temp;
    in >> temp;
    return temp;
}

void
Digraph::addEdge(int v, int w){
    _adj[v].push_front(w);//Normal graph should add `adj[w]->add[v]
    _E++;
}

Digraph*
Digraph::reverse(){
    Digraph* R = new Digraph(_V);
    for(int v = 0; v < _V; v++)
        for(int w: _adj[v])
            R->addEdge(w, v);
    return R;    
}

#endif