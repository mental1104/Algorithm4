/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 23:20:16
 * @FilePath: /espeon/code/Algorithm4/src/chapter5/RK.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include "RabinKarp.h"

using namespace::std;

int main(int argc, char** argv){
    if(argc!=3){
        cout << "You need to enter two extra parameters!" << endl;
        return 0;
    }
    string pat = argv[1];
    string txt = argv[2];
    RabinKarp* rk = new RabinKarp(pat);
    cout << "text:    " << txt << endl;
    int offset = rk->search(txt);
    cout << "pattern: ";
    for (int i = 0; i < offset; i++)
        cout << " ";
    cout << pat << endl;

    delete rk;
    rk = nullptr;
    return 0;
}