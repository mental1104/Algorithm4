#include "./header/kosarajuSCC.h"

int main(int argc, char** argv){
    if(argc!=2){
        cout << "You must enter exactly one parameter!" << endl;
        return 0;
    }
    ifstream is(argv[1]);
    Digraph* graph = new Digraph(is);
    KosarajuSCC* strong = new KosarajuSCC(graph);
    cout << strong->count() << " Components" << endl;
    for(vector<int> vec1: strong->strongComponents()){
        for(int i: vec1)
            cout << i << " ";
        cout << endl;
    }
    delete graph;
    graph = nullptr;
    delete strong;
    strong = nullptr;

    return 0;
}