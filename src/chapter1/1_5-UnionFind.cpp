/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 23:02:24
 * @FilePath: /espeon/code/Algorithm4/src/chapter1/UnionFind.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <fstream>
#include "unionfind.h"

using namespace::std;



int main(){
    
    ifstream myfile("testfile/mediumUF.txt");
    /*
     * largeUF costs a quarter of an hour! And it involves 6 components.
     * You can switch it to "tinyUF.txt" or "mediumUF.txt" manually.
     */
    int N;
    myfile >> N;
    UnionFind *uf = new UnionFind(N);
    int p, q;
    while (myfile)
    {
        myfile >> p;
        myfile >> q;
        if(uf->connected(p,q))
            continue;
        uf->w_union(p, q);
        cout << p << " " << q << endl;
    }
    cout << uf->countNum() << " components" << endl;

    delete uf;
    uf = nullptr;
    
    return 0;
}