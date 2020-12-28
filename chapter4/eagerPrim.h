#ifndef EAGER_PRIM_4_7
#define EAGER_PRIM_4_7

#include "weightededge.h"
#include "EWG.h"
#include <queue>
#include <vector>

struct mapping{
    int _w;
    double _weight;
    mapping(int w, double weight):_w(w),_weight(weight){}
};

struct cmp_prim{
    bool operator()(mapping* a,mapping* b)
    {
        if(a->_weight == b->_weight ) return a->_weight >= b->_weight;
        else return a->_weight >= b->_weight;
    }
};

using std::priority_queue;
using std::vector;

class PrimMST{
public:
    PrimMST(EdgeWeightedGraph* G);
    ~PrimMST();
    double weight();
    vector<Edge*> edges();
    //edges
private:
    void visit(EdgeWeightedGraph* G, int v);

    vector<Edge*> edgeTo;
    vector<double> distTo;
    bool* marked;
    //bool* contained;
    priority_queue<mapping*, vector<mapping*>, cmp_prim> pq;
    vector<mapping*> vec; 
    vector<Edge*> _edges;
    unsigned long infinity = 0x7ff0000000000000;
    
    //unordered_map<double, int> ht;//To give val->key mapping.

    
};

PrimMST::PrimMST(EdgeWeightedGraph* G){
    
    edgeTo.resize(G->V());
    distTo.resize(G->V());
    marked = new bool[G->V()];
    //contained = new bool[G->V()];
    vec.resize(100);

    for(int v = 0; v < G->V(); v++){
        distTo[v] = *reinterpret_cast<double*>(&infinity);//represent the largest double num -> infinity
        marked[v] = false;
        //contained[v] = false;
    }
    distTo[0] = 0.0;
    mapping* mp = new mapping(0, 0.0);

    pq.push(mp);
    vec.at(mp->_w) = mp;

    //contained[mp->_w] = true;

    while(!pq.empty()){
        mapping* temp = pq.top();

        pq.pop();
        //contained[temp] = false;
        for(auto iter = vec.begin(); iter!=vec.end(); iter++)
            if(*iter == temp) vec.erase(iter); 
            
        visit(G, temp->_w);
        delete temp;
    }
}

PrimMST::~PrimMST(){
    delete[] marked;
    for(auto i:vec)
        delete i;
    for(auto i:_edges)
        delete i;
}

void
PrimMST::visit(EdgeWeightedGraph* G, int v){
    marked[v] = true;
    
    for(Edge* e :G->adj(v)){
        int w = e->other(v);
        if(marked[w]) continue;
        if(e->weight() < distTo[w])
        {
           
            edgeTo[w] = e;
            distTo[w] = e->weight();
            if(vec.at(w)!=nullptr) vec.at(w)->_weight = distTo[w];
            else{
                mapping* temp = new mapping(w,distTo[w]);
                pq.push(temp);
                vec.at(w) = temp;
            }
        }
    }

}

vector<Edge*> 
PrimMST::edges(){
    vector<Edge*> mst;
    for(int v = 1;v<edgeTo.size();v++)
        mst.push_back(edgeTo[v]);
    return mst;
}

double
PrimMST::weight(){
    double sum = 0.0;
    for(double i:distTo)
        sum+=i;
    return sum;
}

#endif