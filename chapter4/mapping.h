#ifndef INT_DOUBLE_MAPPING_STRUCT
#define INT_DOUBLE_MAPPING_STRUCT

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


#endif