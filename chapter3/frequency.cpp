#include<iostream>
#include<string>
#include<fstream>
#include<memory>

#include "linked_list.h"
#include "binarysearch.h"

using namespace::std;

int main(){
    shared_ptr<Sequential> ll = make_shared<Sequential>();
    shared_ptr<BinarySearchST> bs = make_shared<BinarySearchST>(11000);

    ifstream rd("./tale.txt");

    ofstream ll_o, bs_o;
    ll_o.open("unordered_linked_list.txt");
    bs_o.open("binarysearch.txt");

    string temp;

    time_t start, end;
    //linked-list construction
    start = clock();
    while(rd >> temp)
        ll->put(temp);
    end = clock();

    double ll_c = double(end-start)/CLOCKS_PER_SEC;
    cout << "Linked-list construction time: " << ll_c << "s. " << endl;

    //binarySearch construction
    rd.close();
    rd.open("./tale.txt");
    start = clock();
    while(rd >> temp)
        bs->put(temp);
    end = clock();
    double bs_c = double(end-start)/CLOCKS_PER_SEC;
    cout << "BinarySearch construction time: " << bs_c << "s. " << endl;

    ll->traverse(ll_o);
    bs->traverse(bs_o);



    return 0;
}