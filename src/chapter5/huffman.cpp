/*
 * @Author: mental1104 mental1104@gmail.com
 * @Date: 2023-05-14 22:45:19
 * @LastEditors: mental1104 mental1104@gmail.com
 * @LastEditTime: 2023-05-14 23:17:12
 * @FilePath: /espeon/code/Algorithm4/src/chapter5/huffman.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include "huffman.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace::std;

int main(){
    /*if(argc!=2){
        cout << "You should enter one extra parameter!" << endl;
        return 0;
    }*/
    ostringstream trie;
    ostringstream rest;
    ifstream is("testfile/ge.txt");


    Huffman* hf = new Huffman(&is,&rest,&trie);

    cout << "Compression begins... " << endl;
    
    hf->compress();
    string trie_val = trie.str();
    cout << "Trie:  " << trie.str() << endl;
    
    cout<<"after compressing:" << hf->_s<<endl;
    cout<< hf->to_string() <<endl;
    cout<<endl;

    cout<<"Trie Tree:"<<endl;
    for(int i=0;i< 128;i++)
        if(hf->st(i)!="")
            cout<<(char)i<<" "<<hf->st(i)<<endl;

    delete hf;
    hf = nullptr;
/*
    cout << "Now we're tring to recover..." << endl;

    istringstream trie_input(trie_val);
    istringstream rest_val(rest.str());
    ofstream os("./copy.txt");
    Huffman* ex = new Huffman(&rest_val, &trie_input, &os);
    ex->expand();

    delete ex;
    ex = nullptr;
*/
    return 0;
}