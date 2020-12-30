#include<iostream>
#include<fstream>

#include "./header/graph.h"
#include "./header/dfs.h"
#include "./header/bfs.h"
using namespace::std;

int main(int argc, char** argv){
    if(argc!=3){
        cout << "You must enter two extra parameters!" << endl;
        return 0;
    }
    ifstream is(argv[1]);
    int s = atoi(argv[2]);

    Graph* graph = new Graph(is);
    
    cout << "\nResults for DFS: \n" << endl;
    DepthFirstPaths* dfs = new DepthFirstPaths(graph, s);
    for(int v = 0; v < graph->V(); v++){
        cout << s << " to " << v << ": ";
        if(dfs->marked(v))
            for(int x: dfs->pathTo(v))
                if(x == s) cout << x;
                else cout << "-" << x;
        cout << endl;
    }

    cout << "\nResults for BFS: \n" <<endl;
    BreadthFirstPaths* bfs = new BreadthFirstPaths(graph, s);
    for(int v = 0; v < graph->V(); v++){
        cout << s << " to " << v << ": ";
        if(bfs->marked(v))
            for(int x: bfs->pathTo(v))
                if(x == s) cout << x;
                else cout << "-" << x;
        cout << endl;
    }

    delete graph;
    graph = nullptr;
    delete dfs;
    dfs = nullptr;
    delete bfs;
    bfs = nullptr;

    return 0;
}