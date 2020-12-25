#include<iostream>
#include<string>
#include<fstream>
#include<memory>

#include "linked_list.h"
#include "binarysearch.h"
#include "BST.h"
#include "RB_tree.h"
#include "SeparateChain.h"
#include "LinearProbing.h"


using namespace::std;

int main(){
    ifstream rd("./tale.txt");

    ofstream ll_o, bs_o, bst_o, rbt_o, hts_o, htl_o;
    ll_o.open("linked_list.txt");
    bs_o.open("binarysearch.txt");
    bst_o.open("BST.txt");
    rbt_o.open("RB_tree.txt");
    hts_o.open("SeparateChain.txt");
    htl_o.open("LinearProbing.txt");

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

    res << "BST construction time: " << bst_c << "s." << endl;

    //RB_tree construction
    rd.close();
    rd.open("./tale.txt");
    start = clock();
    shared_ptr<RB_tree> rbt = make_shared<RB_tree>();
    while(rd >> temp)
        rbt->put(temp);
    end = clock();
    double rbt_c = double(end-start)/CLOCKS_PER_SEC;

    res << "RB_tree construction time: " << rbt_c << "s." << endl;

    rd.close();
    rd.open("./tale.txt");
    start = clock();
    shared_ptr<SeparateChain> hts = make_shared<SeparateChain>();
    while(rd >> temp)
        hts->put(temp);
    end = clock();
    double hts_c = double(end-start)/CLOCKS_PER_SEC;

    res << "HashTable(SeparateChain) construction time: " << hts_c << "s." << endl;

    rd.close();
    rd.open("./tale.txt");
    start = clock();
    shared_ptr<LinearProbing> htl = make_shared<LinearProbing>();
    while(rd >> temp)
        htl->put(temp);
    end = clock();

    double htl_c = double(end-start)/CLOCKS_PER_SEC;
    res << "HashTable(LinearProbing) construction time: " << htl_c << "s.\n\n" << endl;


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
    res << "BST traverse time: " << bst_t << "s. " << endl; 

    start = clock();
    rbt->traverse(rbt_o);
    end = clock();

    double rbt_t = double(end-start)/CLOCKS_PER_SEC;
    res << "RB_tree traverse time(should be the same as BST): " << rbt_t << "s. " << endl; 

    start = clock();
    hts->traverse(hts_o);
    end = clock();

    double hts_t = double(end-start)/CLOCKS_PER_SEC;
    res << "HashTable(SeparateChain) traverse time: " << hts_t << "s. " << endl; 

    start = clock();
    htl->traverse(htl_o);
    end = clock();

    double htl_t = double(end-start)/CLOCKS_PER_SEC;
    res << "HashTable(LinearProbing) traverse time: " << htl_t << "s. \n\n" << endl; 

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

    res << "BST                 " << 1000*bst_d << "ms     " << 1000*bst_s << "ms " << endl;

    
    start = clock();
    rbt->put("BLUE_ESPEON");
    end = clock();

    double rbt_d = double(end-start)/CLOCKS_PER_SEC;

    start = clock();
    rbt->get("BLUE_ESPEON");
    end = clock();

    double rbt_s = double(end-start)/CLOCKS_PER_SEC;

    res << "RB_tree             " << 1000*rbt_d << "ms     " << 1000*rbt_s << "ms " << endl;

    start = clock();
    hts->put("BLUE_ESPEON");
    end = clock();

    double hts_d = double(end-start)/CLOCKS_PER_SEC;

    start = clock();
    hts->get("BLUE_ESPEON");
    end = clock();

    double hts_s = double(end-start)/CLOCKS_PER_SEC;

    res << "HashTable(SC)      " << 1000*hts_d << "ms     " << 1000*hts_s << "ms " << endl;

    start = clock();
    htl->put("BLUE_ESPEON");
    end = clock();

    double htl_d = double(end-start)/CLOCKS_PER_SEC;

    start = clock();
    htl->get("BLUE_ESPEON");
    end = clock();

    double htl_s = double(end-start)/CLOCKS_PER_SEC;

    res << "HashTable(LP)      " << 1000*htl_d << "ms     " << 1000*htl_s << "ms " << endl;


    ll_o.close();
    bs_o.close();
    bst_o.close();

    res.close();

    return 0;
}