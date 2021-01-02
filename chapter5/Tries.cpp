#include <iostream>
#include "./header/Tries.h"
#include <fstream>

using namespace::std;

int main(){
    ifstream is("./testfile/msd.txt");
    TrieST* tree = new TrieST(is);
    for(string s: tree->keys())
        cout << s << endl;
    delete tree;
    tree = nullptr;
}