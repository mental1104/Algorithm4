#ifndef REACHABILITY_IN_DIGRAPHS
#define REACHABILITY_IN_DIGRAPHS

#include "digraph.h"
#include<vector>
#include<fstream>

using namespace::std;

class DirectedDFS{
public:
    DirectedDFS(Digraph* G, int s);
    DirectedDFS(Digraph* G, vector<int> sources);
    ~DirectedDFS(){delete[] M;}

    bool marked(int v) {    return M[v]; }

private:
    void dfs(Digraph* G, int v);

    bool* M;
};

DirectedDFS::DirectedDFS(Digraph* G, int s){
    M = new bool[G->vertex()];
    dfs(G, s);
}

DirectedDFS::DirectedDFS(Digraph* G, vector<int> sources){
    M = new bool[G->vertex()];
    for(int s: sources)
        if(!M[s]) dfs(G, s);
}

void
DirectedDFS::dfs(Digraph* G, int v){
    M[v] = true;
    auto temp = G->adjacent(v)->iter();
    while(temp!=nullptr){
        int w = temp->item;
        if(!M[w]) dfs(G, w);
        temp = temp->next;
    }
}

int main(){
    ifstream is("tinyDG.txt");
    Digraph* G = new Digraph(is);

    int temp;
    vector<int> vec;
    cout << "> Input the number. " << endl;
    while(cin >> temp){
        vec.push_back(temp);
        cout << "> OK, next one.(Ctrl+D to break) " << endl;
    }

    DirectedDFS* reachable = new DirectedDFS(G, vec); 

    for(int v = 0; v < G->vertex(); v++)
        if(reachable->marked(v)) cout << v << " ";
    cout << endl;

    delete reachable;
    reachable = nullptr;

    delete G;
    G = nullptr;

    return 0;
}

#endif