#include<iostream>
#include<fstream>
#include<memory>

#include "graph.h"
#include "dfs.h"

int main(){
    ifstream is("tinyCG.txt");

    Graph* graph = new Graph(is);
    
    cout << "> Input the source: " << endl;
    int s;
    cin >> s;

    DepthFirstPaths* dfs = new DepthFirstPaths(graph, s);
    for(int v = 0; v < graph->vertex(); v++){
        cout << s << " to " << v << ": ";
        if(dfs->hasPathTo(v))
            for(int x: dfs->pathTo(v))
                if(x == s) cout << x;
                else cout << "-" << x;
        cout << endl;
    }

    delete graph;
    graph = nullptr;
    delete dfs;
    dfs = nullptr;

    return 0;

   
}