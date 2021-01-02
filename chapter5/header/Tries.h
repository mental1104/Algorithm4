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

    void del(string key){   root = del(root, key, 0); }

    vector<string> keys();
    vector<string> keysWithPrefix(string pre);
    vector<string> keysThatMatch(string pat);
    string longestPrefixOf(string s);


private:
    void dele(Node** ptr);
    Node* get(Node* x, string key, int d);
    Node* put(Node* x, string key, int val, int d);
    void collect(Node* x, string pre, vector<string>& q);
    void collect(Node* x, string pre, string pat, vector<string>& q);
    int search(Node* x, string s, int d, int length);
    Node* del(Node* x, string key, int d);

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

vector<string>
TrieST::keysThatMatch(string pat){
    vector<string> q;
    collect(root, "", pat, q);
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

void 
TrieST::collect(Node* x, string pre, string pat, vector<string>& q){
    int d = pre.length();
    if (x == nullptr) return;
    if (d == pat.length() && x->val!=-1) q.push_back(pre);
    if (d == pat.length()) return; 

    char next = pat[d];
    for(short c = 0; c<R; c++){
        char temp = *(char*)&c;
        if(next = '.'||next == temp)
            collect(x->next[c],pre+temp, pat, q);
    }
}

string
TrieST::longestPrefixOf(string s){
    int length = search(root, s, 0, 0);
    return s.substr(0, length);
}

int 
TrieST::search(Node* x, string s, int d, int length){
    if(x == nullptr) return length;
    if(x->val != -1) length = d;
    if(d == s.length()) return length;
    char c = s[d];
    return search(x->next[c], s, d+1, length);
}

Node* 
TrieST::del(Node* x, string key, int d){
    if(x == nullptr) return nullptr;
    if(d == key.length())
        x->val = -1;
    else{
        char c = key[d];
        x->next[c] = del(x->next[c],key,d+1);
    }
    if(x->val != -1) return x;
    for(short c = 0; c<R; c++)
        if(x->next[c]!= nullptr) return x;
    return nullptr;
}
#endif