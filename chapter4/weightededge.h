#ifndef WEIGHTED_EDGE_DATA_TYPE
#define WEIGHTED_EDGE_DATA_TYPE

#include<string>
#include<sstream>
#include<iomanip>
#include<stdexcept>

using std::string;
using std::ostringstream;

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

#endif