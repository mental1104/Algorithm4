#include<iostream>
#include<fstream>
#include"./header/lazyPrim.h"

using namespace::std;

int main(int argc, char** argv){
    if(argc!=2){
        cout << "You must enter one extra parameter!" << endl;
        return 0;
    }
    ifstream is(argv[1]);
    EdgeWeightedGraph* graph = new EdgeWeightedGraph(is);
    LazyPrimMST* prim = new LazyPrimMST(graph);
    for(Edge* edge:prim->edges())
        cout << edge->toString() << endl;
    cout << "Total weight: " << prim->weight() << endl;
    
    delete prim;
    delete graph;

    return 0;
}