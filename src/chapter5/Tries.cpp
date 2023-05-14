/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 23:18:34
 * @FilePath: /espeon/code/Algorithm4/src/chapter5/Tries.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include "Tries.h"
#include <fstream>

using namespace::std;

int main(){
    ifstream is("../chapter3/testfile/tale.txt");
    TrieST* tree = new TrieST(is);
    for(string s: tree->keys())
        cout << s << endl;

    cout << "> Find keys with prefix:(Ctrl-D to jump out)" << endl;
    string temp;
    while(cin >> temp){
        for(string i: tree->keysWithPrefix(temp))
            cout << i <<endl;
        cout << "> Find keys with prefix:(Ctrl-D to jump out)" << endl;
    }

    delete tree;
    tree = nullptr;
}