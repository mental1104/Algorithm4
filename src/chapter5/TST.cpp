/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 23:19:00
 * @FilePath: /espeon/code/Algorithm4/src/chapter5/TST.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include "TST.h"
#include <fstream>

using namespace::std;

int main(){
    ifstream is("testfile/msd.txt");
    TST* tree = new TST(is);
    delete tree;
    tree = nullptr;
}