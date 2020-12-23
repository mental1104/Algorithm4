#include<iostream>
#include<string>
#include<fstream>
#include<memory>

#include "linked_list.h"
#include "binarysearch.h"
#include "BST.h"

using namespace::std;

int main(){
    ifstream rd("./tale.txt");

    ofstream ll_o, bs_o, bst_o;
    ll_o.open("linked_list.txt");
    bs_o.open("binarysearch.txt");
    bst_o.open("BST.txt");

    ofstream res;
    res.open("res.txt");

    string temp;

    time_t start, end;
    //linked-list construction

    res << "Construction:  \n" << endl;
    start = clock();
    shared_ptr<Sequential> ll = make_shared<Sequential>();
    while(rd >> temp)
        ll->put(temp);
    end = clock();

    double ll_c = double(end-start)/CLOCKS_PER_SEC;
    res << "Linked-list construction time: " << ll_c << "s. " << endl;

    //binarySearch construction
    rd.close();
    rd.open("./tale.txt");

    start = clock();
    shared_ptr<BinarySearchST> bs = make_shared<BinarySearchST>(11000);
    while(rd >> temp)
        bs->put(temp);
    end = clock();

    double bs_c = double(end-start)/CLOCKS_PER_SEC;

    res << "BinarySearch construction time: " << bs_c << "s. " << endl;

    //BST construction
    rd.close();
    rd.open("./tale.txt");
    start = clock();
    shared_ptr<BST> bst = make_shared<BST>();
    while(rd >> temp)
        bst->put(temp);
    end = clock();
    double bst_c = double(end-start)/CLOCKS_PER_SEC;

    res << "BST construction time: " << bst_c << "s.\n\n" << endl;

    rd.close();


    //traverse;
    res << "Traverse:  \n" << endl;
    start = clock();
    ll->traverse(ll_o);
    end = clock();

    double ll_t = double(end-start)/CLOCKS_PER_SEC;
    res << "Linked-list traverse time: " << ll_t << "s. " << endl;

    start = clock();
    bs->traverse(bs_o);
    end = clock();

    double bs_t = double(end-start)/CLOCKS_PER_SEC;
    res << "BinarySearch traverse time: " << bs_t << "s. " << endl; 

    start = clock();
    bst->traverse(bst_o);
    end = clock();

    double bst_t = double(end-start)/CLOCKS_PER_SEC;
    res << "BST traverse time: " << bst_t << "s. \n\n" << endl; 

    //Operation
    res << "                  Dynamic     Static (ms): " << endl;
    start = clock();
    ll->put("BLUE_ESPEON");
    end = clock();

    double ll_d = double(end-start)/CLOCKS_PER_SEC;

    start = clock();
    ll->get("it");//cause newly-inserted item will be placed at the first of the linked-list, 
    //so here I'm going to search the last one on purpose to manifest its O(n) search complexity.  
    end = clock();

    double ll_s = double(end-start)/CLOCKS_PER_SEC;

    res << "linked-list         " << 1000*ll_d << "ms     " << 1000*ll_s << "ms " << endl;

    start = clock();
    bs->put("BLUE_ESPEON");
    end = clock();

    double bs_d = double(end-start)/CLOCKS_PER_SEC;

    start = clock();
    bs->get("BLUE_ESPEON");
    end = clock();

    double bs_s = double(end-start)/CLOCKS_PER_SEC;

    res << "BinarySearch        " << 1000*bs_d << "ms     " << 1000*bs_s << "ms " << endl;

    start = clock();
    bst->put("BLUE_ESPEON");
    end = clock();

    double bst_d = double(end-start)/CLOCKS_PER_SEC;

    start = clock();
    bst->get("BLUE_ESPEON");
    end = clock();

    double bst_s = double(end-start)/CLOCKS_PER_SEC;

    res << "BST                 " << 1000*bs_d << "ms     " << 1000*bs_s << "ms " << endl;

    ll_o.close();
    bs_o.close();
    bst_o.close();

    res.close();

    return 0;
}