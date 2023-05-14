#include <iostream>
#include "acyclic.h"

int main(int argc, char** argv){
    while(argc!=3){
        cout << "You must print out 2 extra parameters!" << endl;
        return 0;
    }
    ifstream is(argv[1]);
    EdgeWeightedDigraph* G = new EdgeWeightedDigraph(is);
    int s = atoi(argv[2]);

    AcyclicSP* sp = new AcyclicSP(G,s);
    
    for (int t = 0; t < G->V(); t++){
        cout << s << " to " << t;
        printf(" (%4.2f): ", sp->distTo(t));
        if(sp->hasPathTo(t))
            for(DirectedEdge* e:sp->pathTo(t))
                cout << e->toString() << "    ";
        cout << endl;
    }
}