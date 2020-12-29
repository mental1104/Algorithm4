#ifndef DIRECTED_WEIGHT_EDGE_DATA_TYPE
#define DIRECTED_WEIGHT_EDGE_DATA_TYPE

#include<string>
using std::string;

#include<sstream>
#include<iomanip>

using std::ostringstream;

class DirectedEdge{
public:
    DirectedEdge(int v, int w, double weight):_v(v),_w(w),_weight(weight){}
    int from()  {   return _v;  }
    int to()    {   return _w;  }
    double weight() {  return _weight; }
    string toString();
    
private:
    int _v;
    int _w;
    double _weight;
};

string
DirectedEdge::toString(){
    ostringstream ss;
    ss << _v << "-" << _w << " " << std::fixed << std::setprecision(2) << _weight;
    return ss.str();
}

#endif