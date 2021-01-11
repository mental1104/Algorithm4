//ALGORITHM 1.1 Pushdown (LIFO) stack (resizing array implementation) testfile
#include<iostream>
#include "./header/stack.h"

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