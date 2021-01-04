#include <iostream>
#include"./header/huffman.h"
#include <fstream>
#include <string>

using namespace::std;

int main(int argc, char** argv){
    if(argc!=2){
        cout << "You should enter one extra parameter!" << endl;
        return 0;
    }
    Huffman* hf = new Huffman();

    cout << "Compression begins... " << endl;

    
    hf->compress(argv[1]);
    
    cout<<"after compressing:" << hf->_s<<endl;
    cout<< hf->to_string() <<endl;
    cout<<endl;

    cout<<"Trie Tree:"<<endl;
    for(int i=0;i< 128;i++)
        if(hf->st(i)!="")
        cout<<(char)i<<" "<<hf->st(i)<<endl;
    
    delete hf;
    hf = nullptr;

    return 0;
}