#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"./header/UF.h"

using namespace::std;



int main(){
    
    ifstream myfile("./testfile/largeUF.txt");
    /*largeUF costs a quarter of an hour! And it involves 6 components.
    You can switch it to "tinyUF.txt" or "mediumUF.txt" manually.*/
    int N;
    myfile >> N;
    UnionFind *uf = new UnionFind(N);
    int p, q;
    while (myfile)
    {
        myfile >> p;
        myfile >> q;
        if(uf->connected(p,q))
            continue;
        uf->w_union(p, q);
        cout << p << " " << q << endl;
    }
    cout << uf->countNum() << " components";

    delete uf;
    uf = nullptr;
    
    return 0;
}