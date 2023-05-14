/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 23:10:46
 * @FilePath: /espeon/code/Algorithm4/src/chapter4/lazyPrim.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <fstream>
#include "lazyPrim.h"

using namespace::std;

int main(int argc, char** argv){
    if(argc!=2){
        cout << "You must enter one extra parameter!" << endl;
        return 0;
    }
    ifstream is(argv[1]);
    EdgeWeightedGraph* graph = new EdgeWeightedGraph(is);
    LazyPrimMST* prim = new LazyPrimMST(graph);
    for(Edge* edge:prim->edges())
        cout << edge->toString() << endl;
    cout << "Total weight: " << prim->weight() << endl;
    
    delete prim;
    delete graph;

    return 0;
}