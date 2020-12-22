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