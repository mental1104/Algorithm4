#include<iostream>
#include<fstream>
#include<vector>

#include "CC.h"

int main(){
    ifstream is("mediumG.txt");
    ofstream os("CC.txt");

    Graph* G = new Graph(is);
    CC* cc = new CC(G);

    int M = cc->count();
    os << M << " Components" << endl;

    vector<vector<int>> vec;
    vec.resize(M);
    for(int v = 0; v < G->vertex(); v++)
        vec[cc->id(v)].push_back(v);
    for(int i = 0; i<M; i++)
    {
        for(int v: vec[i])
            os << v << " ";
        os << endl;
    }

    delete G;
    G = nullptr;
    delete cc;
    cc = nullptr;
}