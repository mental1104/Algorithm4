#ifndef TST_SYMBOL_TABLE_5_5
#define TST_SYMBOL_TABLE_5_5

#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;

struct Node{
    char c;
    Node* left, *mid, *right;
    int val = -1;
    Node():left(nullptr),mid(nullptr), right(nullptr){}
};

class TST{
public:
    TST(ifstream& is);
    ~TST(){ destruct(root); }
    int get(string key){
        Node* x = get(root, key, 0);
        if(x == nullptr) return -1;
        return x->val;
    }

    void put(string key, int val) { root = put(root,key,val,0); }

private:
    Node* get(Node* x, string key, int d);
    Node* put(Node* x, string key, int val, int d);
    void destruct(Node* x);
    void collect(Node* x, string pre, vector<string>& q);
    Node* root;
};

TST::TST(ifstream& is){
    string temp;
    int i = 0;
    while(is >> temp){
        put(temp, i);
        i++;
    }
}

void
TST::destruct(Node* x){
    if(x == nullptr)
        return;
    destruct(x->left);
    destruct(x->mid);
    destruct(x->right);
    delete x;
    x = nullptr;
}

Node*
TST::get(Node* x, string key, int d){
    if(x == nullptr) return nullptr;
    char c = key[d];
    if      (c < x->c) return get(x->left, key, d);
    else if (c > x->c) return get(x->right, key, d);
    else if (d < key.length() - 1) return get(x->mid, key, d+1);
    else    return x;
}

Node*
TST::put(Node* x, string key, int val, int d){
    char c = key[d];
    if(x == nullptr) {  x = new Node(); x->c = c; }
    if      (c < x->c) x->left = put(x->left, key, val, d);
    else if (c > x->c) x->right = put(x->right, key, val, d);
    else if (d < key.length() - 1) x->mid = put(x->mid, key, val, d+1);
    else    x->val = val;
    return x;
}


#endif