#ifndef RED_BLACK_TREE_3_4
#define RED_BLACK_TREE_3_4

#include"BST.h"

#define BLACK false
#define RED true

class RB_tree: public BST{
protected:

    bool isRed(Node* h);

    Node* rotateLeft(Node* h);

    Node* rotateRight(Node* h);

    void flipColors(Node* h);

    Node* put(Node* h, string key);

    void traverse_delete(Node* node);

public:

    RB_tree():BST(){}  

    void put(string key){
        root = put(root, key);
        root->color = BLACK;
    }
};


bool
RB_tree::isRed(Node* h){
    if(h == nullptr) return false;
    return h->color == RED;
}

Node*
RB_tree::rotateLeft(Node* h){
    Node* x = h->right;
    h->right = x->left;
    x->left = h;
    x->color = h->color;
    h->color = RED;
    x->N = h->N;
    h->N = 1 + size(h->left) + size(h->right);
    return x;
}

Node*
RB_tree::rotateRight(Node* h){
    Node* x = h->left;
    h->left = x->right;
    x->right = h;
    x->color = h->color;
    h->color = RED;
    x->N = h->N;
    h->N = 1 + size(h->left) + size(h->right);
    return x;
}

void
RB_tree::flipColors(Node* h){
    h->color = RED;
    h->left->color = BLACK;
    h->right->color = BLACK;
}

Node*
RB_tree::put(Node* h, string key){
    if(h == nullptr)
        return new Node(key, 1, 1, RED);
    
    int cmp = key.compare(h->key);
    if      (cmp < 0) h->left = put(h->left, key);
    else if (cmp > 0) h->right = put(h->right, key);
    else h->val++;

    if(isRed(h->right) && !isRed(h->left))  h = rotateLeft(h);
    if(isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if(isRed(h->left) && isRed(h->right))  flipColors(h);

    h->N = size(h->left) + size(h->right) + 1;
    return h;
}

#endif