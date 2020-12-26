#include<iostream>
#include<fstream>
#include<memory>

#include "graph.h"
#include "dfs.h"
#include "bfs.h"

int main(){
    ifstream is("mediumG.txt");

    ofstream os("paths.txt");
    Graph* graph = new Graph(is);
    
    cout << "> Input the source: " << endl;
    int s;
    cin >> s;

    os << "\nResults for DFS: \n" <<endl;
    DepthFirstPaths* dfs = new DepthFirstPaths(graph, s);
    for(int v = 0; v < graph->vertex(); v++){
        os << s << " to " << v << ": ";
        if(dfs->hasPathTo(v))
            for(int x: dfs->pathTo(v))
                if(x == s) os << x;
                else os << "-" << x;
        os << endl;
    }

    os << "\nResults for BFS: \n" <<endl;
    BreadthFirstPaths* bfs = new BreadthFirstPaths(graph, s);
    for(int v = 0; v < graph->vertex(); v++){
        os << s << " to " << v << ": ";
        if(bfs->hasPathTo(v))
            for(int x: bfs->pathTo(v))
                if(x == s) os << x;
                else os << "-" << x;
        os << endl;
    }

    delete graph;
    graph = nullptr;
    delete dfs;
    dfs = nullptr;
    delete bfs;
    dfs = nullptr;

    return 0;
}