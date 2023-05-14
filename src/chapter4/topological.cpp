/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 23:11:19
 * @FilePath: /espeon/code/Algorithm4/src/chapter4/topological.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include "topological.h"

using namespace::std;

int main(int argc, char** argv){
    while(argc!=3){
        cout << "You must enter two extra parameters!" << endl;
        return 0;
    }

    SymbolDigraph* sg = new SymbolDigraph(argv[1], argv[2]);
    Topological* top = new Topological(sg->graph());

    for(int v: top->order())
        cout << sg->name(v) << endl;

    delete sg;
    sg = nullptr;
    delete top;
    top = nullptr;

    return 0;

}

