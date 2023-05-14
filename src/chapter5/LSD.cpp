/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 23:17:21
 * @FilePath: /espeon/code/Algorithm4/src/chapter5/LSD.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

#include "LSD.h"

using namespace::std;

int main(){
    ifstream is("./testfile/license.txt");
    string temp;
    vector<string> vec;
    while(getline(is, temp))
        vec.push_back(temp);

    clock_t begin, end;
    cout << "Before LSD Sorting...." << endl;
    for(string i:vec)
        cout << i << endl;
    cout << "After LSD Sorting...." << endl;

    begin = clock();
    LSD::sort(vec, 7);
    end = clock();

    double time_val = double(end - begin)/CLOCKS_PER_SEC;
    cout << "Sort time: " << time_val << "s. " << endl;

    for(string i:vec)
        cout << i << endl;
    return 0;

}