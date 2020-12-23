#ifndef BINARY_SEARCH_TREEE_3_3
#define BINARY_SEARCH_TREEE_3_3

#include<string>
#include<vector>
#include<fstream>

using namespace::std;

class Node{
public:
    string key;
    int val;
    Node* left = nullptr, *right = nullptr;
    int N;
    Node(string k, int v, int n):key(k),val(v),N(n){}
};

class BST{
private:

    Node* root;

    int size(Node* x);

    int get(Node* x, string key);

    Node* put(Node* x, string key);

    Node* min(Node* x);

    Node* max(Node* x);

    Node* floor(Node* x, string key);

    Node* ceiling(Node* x, string key);

    Node* select(Node* x, int k);

    int rank(string key, Node* x);

    Node* deleteMin(Node* x);

    Node* deleteMax(Node* x);

    Node* dele(Node* x, string key);

    void keys(Node* x, vector<string>& vec, string lo, string hi);

    void traverse_delete(Node* node);

    void traverse(ostream& os, Node* node);

public:

    BST() { root = nullptr; }
    ~BST()  {   traverse_delete(root);  }

    int size() {  return size(root); }

    int get(string key){ return get(root,key); }

    void put(string key){ root = put(root, key); }

    string min(){ return min(root)->key; }

    string max(){ return max(root)->key; }

    string floor(string key){
        Node* x = floor(root, key);
        if(x == nullptr)  return "NULL";
        return x->key;
    }

    string ceiling(string key){
        Node* x = ceiling(root, key);
        if(x == nullptr) return "NULL";
        return x->key;
    }

    string select(int k){ return select(root, k)->key; }

    int rank(string key){ return rank(key, root); }

    void deleteMin(){ root = deleteMin(root); }

    void deleteMax(){ root = deleteMax(root); }

    void dele(string key){ root = dele(root, key); }

    vector<string> keys(){  return keys(min(),max()); }

    vector<string> keys(string lo, string hi){  
        vector<string> vec;
        keys(root, vec, lo, hi);
        return vec;

    }

    void traverse(ostream& os){ traverse(os, root); }
};

void 
BST::traverse_delete(Node* node){
    if(node!=nullptr){
        Node* l = node->left;
        Node* r = node->right;
        delete(node);
        traverse_delete(node->left);
        traverse_delete(node->right);
    }
}

int 
BST::size(Node* x){
    if(x == nullptr) return 0;
    else             return x->N;
}

int
BST::get(Node* x, string key){
    if(x==nullptr) return -1;
    int cmp = key.compare(x->key);
    if      (cmp < 0) return get(x->left, key);
    else if (cmp > 0) return get(x->right, key);
    else return x->val;
}

Node*
BST::put(Node* x, string key){
    if(x == nullptr) return new Node(key, 1, 1);
    int cmp = key.compare(x->key);
    if      (cmp < 0) x->left  = put(x->left, key);
    else if (cmp > 0) x->right = put(x->right, key);
    else x->val++;

    x->N = size(x->left) + size(x->right) + 1;
    return x;
}

Node*
BST::min(Node* x){
    if(x->left == nullptr) return x;
    return min(x->left);
}

Node*
BST::max(Node* x){
    if(x->right == nullptr) return x;
    return max(x->right);
}

Node* 
BST::floor(Node* x, string key){
    if(x == nullptr) return nullptr;
    int cmp = key.compare(x->key);
    if(cmp == 0) return x;
    if(cmp < 0) return floor(x->left, key);
    Node* t = floor(x->right, key);
    if(t!=nullptr) return t;
    else           return x;
}

Node* 
BST::ceiling(Node* x, string key){
    if(x == nullptr) return nullptr;
    int cmp = key.compare(x->key);
    if(cmp == 0) return x;
    if(cmp > 0) return ceiling(x->right, key);
    Node* t = ceiling(x->left, key);
    if(t!=nullptr) return t;
    else           return x;
}

Node* 
BST::select(Node* x, int k){
    if(x==nullptr) return nullptr;
    int t = size(x->left);
    if      (t > k) return select(x->left, k);
    else if (t < k) return select(x->right, k-t-1);
    else            return x;
}

int
BST::rank(string key, Node* x){
    if(x==nullptr) return 0;
    int cmp = key.compare(x->key);
    if      (cmp < 0) return rank(key, x->left);
    else if (cmp > 0) return 1 + size(x->left) + rank(key, x->right);
    else              return size(x->left);
}

Node*
BST::deleteMin(Node* x){
    if(x->left == nullptr) return x->right;
    x->left = deleteMin(x->left);
    x->N = size(x->left) + size(x->right) + 1;
    return x;
}

Node* 
BST::deleteMax(Node* x){
    if(x->right == nullptr) return x->left;
    x->right = deleteMax(x->right);
    x->N = size(x->left) + size(x->right)+1;
    return x;
}

Node*
BST::dele(Node* x, string key){
    if(x == nullptr) return nullptr;
    int cmp = key.compare(x->key);
    if      (cmp < 0) x->left  = dele(x->left, key);
    else if (cmp > 0) x->right = dele(x->right, key);
    else{
        if(x->right == nullptr) return x->left;
        if(x->left == nullptr)  return x->right;
        Node* t = x;
        x = min(t->right);
        x->right = deleteMin(t->right);
        x->left = t->left;
        delete(t);
    }
    x->N = size(x->left) + size(x->right) + 1;
    return x;
}

void
BST::keys(Node* x, vector<string>& vec, string lo, string hi){
    if(x == nullptr) return;
    int cmplo = lo.compare(x->key);
    int cmphi = hi.compare(x->key);
    if(cmplo < 0) keys(x->left, vec, lo, hi);
    if(cmplo <= 0 && cmphi >= 0) vec.push_back(x->key);
    if(cmphi > 0) keys(x->right, vec, lo, hi);
}

void
BST::traverse(ostream& os, Node* node){
    if(node == nullptr)
        return;
    traverse(os, node->left);
    os << node->key << "\t\t\t\t" << node->val << endl;
    traverse(os, node->right);
}
#endif