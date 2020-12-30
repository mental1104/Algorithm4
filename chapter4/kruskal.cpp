#include <iostream>
#include <fstream>
#include "./header/kruskal.h"

using namespace::std;

int main(int argc, char** argv){
    if(argc!=2){
        cout << "You must enter one extra parameter!" << endl;
        return 0;
    }
    ifstream is(argv[1]);
    EdgeWeightedGraph* graph = new EdgeWeightedGraph(is);
    KruskalMST* kruskal = new KruskalMST(graph);
    for(Edge* edge: kruskal->edges())
        cout << edge->toString() << endl;
    cout << "Total weight: " << kruskal->weight() << endl;
    
    delete graph;
    delete kruskal;

    return 0;
}