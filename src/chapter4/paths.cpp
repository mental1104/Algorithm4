/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 23:10:53
 * @FilePath: /espeon/code/Algorithm4/src/chapter4/paths.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <fstream>

#include "graph.h"
#include "dfs.h"
#include "bfs.h"
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