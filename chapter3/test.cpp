#include<iostream>
#include<memory>
#include"LinearProbing.h"

using namespace::std;


int main(){
    shared_ptr<LinearProbing> ptr = make_shared<LinearProbing>();
    int i = 0;
    while(i<5){
        cout << ptr->entry[i].key << endl;
        i++;
    }
    return 0;
}