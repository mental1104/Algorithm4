/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 22:56:02
 * @FilePath: /espeon/code/Algorithm4/src/chapter1/1_3-queue.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//ALGORITHM 1.2 Pushdown stack (linked-list testfile)
#include<iostream>
#include "queue.h"

using namespace::std;

int main(){
    Queue<int> q;
    int temp;
    cout << "Input the sequence:" << endl;
    cout << "> ";
    while(cin >> temp && temp != -1){
        q.enqueue(temp);
        q.traverse(cout);
        cout << "> ";       
    }
    cout << "\n\nNow they will be gradually popped.\n";
    while(!q.isEmpty()){
        q.traverse(cout);
        q.dequeue();
    }

    return 0;
}