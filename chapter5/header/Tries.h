#ifndef TRIES_SYMBOL_TABLE_5_4
#define TRIES_SYMBOL_TABLE_5_4

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;

struct Node{
    int val;
    Node** next = nullptr; 
    Node():val(-1){
        next = new Node*[256];
    }  
};

class TrieST{
public:
    TrieST(ifstream& is);
    ~TrieST(){ 
        if(root != nullptr)
            dele(root->next);
    }

    int get(string key){
        Node* x = get(root, key, 0);
        if(x == nullptr) return -1;
        return x->val;
    }

    void put(string key, int val){
        root = put(root, key, val, 0);
    }

    vector<string> keys();
    vector<string> keysWithPrefix(string pre);


private:
    void dele(Node** ptr);
    Node* get(Node* x, string key, int d);
    Node* put(Node* x, string key, int val, int d);
    void collect(Node* x, string pre, vector<string>& q);

    int R = 256;
    Node* root = nullptr;
};

TrieST::TrieST(ifstream& is){
    string temp;
    int i = 0;
    while(is >> temp){
        put(temp, i);
        i++;
    }
}

void 
TrieST::dele(Node** ptr){
    for(int i = 0; i<256; i++)
        if(ptr[i] == nullptr)
            delete ptr[i];
        else
            dele(ptr[i]->next);
}

Node*
TrieST::get(Node* x, string key, int d){
    if(x == nullptr) return nullptr;
    if(d == key.size()) return x;
    char c = key[d];
    return get(x->next[c],key, d+1);
}

Node*
TrieST::put(Node* x, string key, int val, int d){
    if (x == nullptr) x = new Node();
    if (d == key.length()) { x->val = val; return x;}
    char c = key[d];
    x->next[c] = put(x->next[c], key, val, d+1);
    return x;
}

vector<string> 
TrieST::keys(){
    return keysWithPrefix("");
}

vector<string>
TrieST::keysWithPrefix(string pre){
    vector<string> q;
    collect(get(root, pre, 0), pre, q);
    return q;
}

void
TrieST::collect(Node* x, string pre, vector<string>& q){
    if (x == nullptr) return;
    if (x->val != -1) q.push_back(pre);
    for(short c = 0; c<R; c++){
        char temp = *(char*)&c;
        collect(x->next[c], pre+temp, q);
    }
}


#endif