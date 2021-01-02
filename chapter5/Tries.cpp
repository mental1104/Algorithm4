#include <iostream>
#include "./header/Tries.h"
#include <fstream>

using namespace::std;

int main(){
    ifstream is("../chapter3/tale.txt");
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