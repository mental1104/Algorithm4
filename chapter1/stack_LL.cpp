//ALGORITHM 1.2 Pushdown stack (linked-list testfile)
#include<iostream>
#include "./header/stack_LL.h"

using namespace::std;

int main(){
    Stack<int> s;
    int temp;
    cout << "Input the sequence:" << endl;
    cout << "> ";
    while(cin >> temp && temp != -1){
        s.push(temp);
        s.traverse(cout);
        cout << "> ";       
    }
    cout << "\n\nNow they will be gradually popped.\n";
    while(!s.isEmpty()){
        s.traverse(cout);
        s.pop();
    }

    return 0;
}