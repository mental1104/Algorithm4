/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 23:10:39
 * @FilePath: /espeon/code/Algorithm4/src/chapter4/kosarajuSCC.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "kosarajuSCC.h"

int main(int argc, char** argv){
    if(argc!=2){
        cout << "You must enter exactly one parameter!" << endl;
        return 0;
    }
    ifstream is(argv[1]);
    Digraph* graph = new Digraph(is);
    KosarajuSCC* strong = new KosarajuSCC(graph);
    cout << strong->count() << " Components" << endl;
    for(vector<int> vec1: strong->strongComponents()){
        for(int i: vec1)
            cout << i << " ";
        cout << endl;
    }
    delete graph;
    graph = nullptr;
    delete strong;
    strong = nullptr;

    return 0;
}