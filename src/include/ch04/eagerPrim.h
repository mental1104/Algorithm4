#ifndef EAGER_PRIM_4_7
#define EAGER_PRIM_4_7

#include "mapping.h"
#include "EWG.h"
#include <queue>
#include <vector>
#include <deque>

using std::priority_queue;
using std::vector;
using std::deque;

class PrimMST{
public:
    PrimMST(EdgeWeightedGraph* G);
    ~PrimMST();
    double weight();
    vector<Edge*> edges();
private:
    void visit(EdgeWeightedGraph* G, int v);

    vector<Edge*> _edgeTo;
    vector<double> _distTo;
    deque<bool> _marked;
    priority_queue<mapping*, vector<mapping*>, cmp_prim> _pq;
    vector<mapping*> _vec; 
    vector<Edge*> _edges;
    unsigned long _infinity = 0x7ff0000000000000;//inf double
};

PrimMST::PrimMST(EdgeWeightedGraph* G){
    
    _edgeTo.resize(G->V());
    _distTo.resize(G->V());
    _marked.resize(G->V());
    _vec.resize(G->V());

    double inf = *reinterpret_cast<double*>(&_infinity);
    for(int v = 0; v < G->V(); v++){
        _distTo[v] = inf;//represent the largest double num -> infinity
        _marked[v] = false;
    }
    _distTo[0] = 0.0;
    mapping* mp = new mapping(0, 0.0);

    _pq.push(mp);
    _vec.at(mp->_w) = mp;

    //contained[mp->_w] = true;

    while(!_pq.empty()){
        mapping* temp = _pq.top();

        _pq.pop();
        //contained[temp] = false;
        for(auto iter = _vec.begin(); iter!=_vec.end(); iter++){
            if(*iter == temp) _vec.erase(iter);
            _vec.resize(G->V());//since the erase operation the vec's capacity has been modified. 
            //If this operation is ignored, following accessing vec might be out of range.
        }
            
        visit(G, temp->_w);
        delete temp;
    }
}

PrimMST::~PrimMST(){
    for(auto i:_vec)
        delete i;
}

void
PrimMST::visit(EdgeWeightedGraph* G, int v){
    _marked[v] = true;
    
    for(Edge* e :G->adj(v)){
        int w = e->other(v);
        if(_marked[w]) continue;
        if(e->weight() < _distTo[w])
        {
           
            _edgeTo[w] = e;
            _distTo[w] = e->weight();
            if(_vec.at(w)!=nullptr) _vec.at(w)->_weight = _distTo[w];
            else{
                mapping* temp = new mapping(w,_distTo[w]);
                _pq.push(temp);
                _vec.at(w) = temp;
            }
        }
    }

}

vector<Edge*> 
PrimMST::edges(){
    vector<Edge*> mst;
    for(int v = 1;v<_edgeTo.size();v++)
        mst.push_back(_edgeTo[v]);
    return mst;
}

double
PrimMST::weight(){
    double sum = 0.0;
    for(double i:_distTo)
        sum+=i;
    return sum;
}

#endif