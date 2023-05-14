/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 23:13:47
 * @FilePath: /espeon/code/Algorithm4/src/chapter4/reachability.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "digraph.h"
#include "reachability.h"
#include <deque>
#include <fstream>

using namespace::std;


int main(){
    ifstream is("./testfile/tinyDG.txt");
    Digraph *G = new Digraph(is);

    int temp;
    deque<int> vec;
    cout << "> Input the number. " << endl;
    while(cin >> temp){
        vec.push_back(temp);
        cout << "> OK, next one.(Ctrl+D to break) " << endl;
    }

    DirectedDFS* reachable = new DirectedDFS(G, vec); 

    for(int v = 0; v < G->V(); v++)
        if(reachable->marked(v)) cout << v << " ";
    cout << endl;

    delete reachable;
    reachable = nullptr;

    delete G;
    G = nullptr;

    return 0;
}