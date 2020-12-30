#include<iostream>
#include<fstream>
#include<vector>

#include "./header/CC.h"

using namespace::std;

int main(int argc, char** argv){
    if(argc!=2){
        cout << "You must enter ont extra parameter!" << endl;
        return 0;
    }
    ifstream is(argv[1]);

    Graph* G = new Graph(is);
    CC* cc = new CC(G);

    int M = cc->count();
    cout << M << " Components" << endl;

    vector<vector<int>> vec;
    vec.resize(M);
    for(int v = 0; v < G->V(); v++)
        vec[cc->id(v)].push_back(v);
    for(int i = 0; i<M; i++)
    {
        for(int v: vec[i])
            cout << v << " ";
        cout << endl;
    }

    delete G;
    G = nullptr;
    delete cc;
    cc = nullptr;
}