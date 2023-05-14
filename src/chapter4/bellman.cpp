/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 23:10:21
 * @FilePath: /espeon/code/Algorithm4/src/chapter4/bellman.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <fstream>
#include "EWDG.h"
#include "bellman.h"

using namespace::std;

int main(int argc, char** argv){
    while(argc!=3){
        cout << "You must print out 2 extra parameters!" << endl;
        return 0;
    }
    ifstream is(argv[1]);
    EdgeWeightedDigraph* G = new EdgeWeightedDigraph(is);
    int s = atoi(argv[2]);

    BellmanFordSP* sp = new BellmanFordSP(G,s);
    
    for (int t = 0; t < G->V(); t++){
        cout << s << " to " << t;
        printf(" (%4.2f): ", sp->distTo(t));
        if(sp->hasPathTo(t))
            for(DirectedEdge* e:sp->pathTo(t))
                cout << e->toString() << "    ";
        cout << endl;
    }

    delete G;
    G = nullptr;
    delete sp;
    sp = nullptr;
}