/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 23:14:05
 * @FilePath: /espeon/code/Algorithm4/src/include/ch04/kruskal.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef KRUSKAL_MST_4_8
#define KRUSKAL_MST_4_8

#include <vector>
#include <queue>
#include "EWG.h"
#include "unionfind.h"
using namespace::std;


class KruskalMST{
public:
    KruskalMST(EdgeWeightedGraph* G);
    vector<Edge*> edges() { return mst;}
    double weight();
private:
    vector<Edge*> mst;
    priority_queue<Edge*, vector<Edge*>, cmp> pq;
};


KruskalMST::KruskalMST(EdgeWeightedGraph* G){
    for(Edge* e: G->edges())
        pq.push(e);
    UnionFind* uf = new UnionFind(G->V());
    while(!pq.empty() && mst.size() < G->V()-1){
        Edge* e = pq.top();
        pq.pop();
        int v =e->either(), w = e->other(v);
        if(uf->connected(v,w)) 
            continue;
        uf->w_union(v ,w);
        mst.push_back(e);
    }
    delete uf;
    
}

double 
KruskalMST::weight(){
    double sum = 0.0;
    for(Edge* e: mst)
        sum += e->weight();
    return sum;
}

#endif