#include <iostream>
#include "./header/TST.h"
#include <fstream>

using namespace::std;

int main(){
    ifstream is("./testfile/msd.txt");
    TST* tree = new TST(is);
    delete tree;
    tree = nullptr;
}