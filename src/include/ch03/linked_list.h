#ifndef SEQUENTIAL_SERACH_IN_AN_UNORDERED_LINKED_LIST_3_1
#define SEQUENTIAL_SERACH_IN_AN_UNORDERED_LINKED_LIST_3_1

#include<string>
#include<fstream>


using std::ostream;
using std::string;
using std::endl;

class Sequential{
private:
    struct Node
    {
        string key;
        int val;
        Node *next;
        Node(string k,int v, Node* n):key(k),val(v),next(n){}
    };

    Node* first;
public:   
    Sequential(){   first = nullptr;    }
    ~Sequential();

    int get(string key);

    void put(string key);

    void traverse(ostream& os);

};

Sequential::~Sequential(){
    while(first!=nullptr){
		Node *oldfirst = first;
        first = first->next;
		delete oldfirst;
    }
}

int
Sequential::get(string key){
    for(Node* x = first;x!=nullptr;x=x->next)
        if(key==x->key)
            return x->val;
    return -1;
}

void
Sequential::put(string key){
    for(Node* x = first;x!=nullptr;x=x->next)
        if(key==x->key){
            x->val++;//for counting frequency, small modification here.
            return;
        }
    first = new Node(key, 1, first);
}

void
Sequential::traverse(ostream& os){
    for(Node* x = first;x!=nullptr;x=x->next)
        os << x->key << "\t\t\t\t" << x->val << endl;
}


#endif