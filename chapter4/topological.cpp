#include <iostream>
#include "./header/topological.h"

using namespace::std;

int main(int argc, char** argv){
    while(argc!=3){
        cout << "You must enter two extra parameters!" << endl;
        return 0;
    }

    SymbolDigraph* sg = new SymbolDigraph(argv[1], argv[2]);
    Topological* top = new Topological(sg->graph());

    for(int v: top->order())
        cout << sg->name(v) << endl;

    delete sg;
    sg = nullptr;
    delete top;
    top = nullptr;

    return 0;

}

