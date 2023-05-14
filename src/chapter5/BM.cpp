#include <iostream>
#include "BM.h"
using namespace::std;

int main(int argc, char** argv){
    if(argc!=3){
        cout << "You need to enter two extra parameters!" << endl;
        return 0;
    }
    string pat = argv[1];
    string txt = argv[2];
    BoyerMoore* bm = new BoyerMoore(pat);
    cout << "text:    " << txt << endl;
    int offset = bm->search(txt);
    cout << "pattern: ";
    for (int i = 0; i < offset; i++)
        cout << " ";
    cout << pat << endl;

    delete bm;
    bm = nullptr;
    return 0;
}