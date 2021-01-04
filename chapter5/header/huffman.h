#ifndef HUFFMAN_COMPRESSION_5_10
#define HUFFMAN_COMPRESSION_5_10

#include <vector>
using std::vector;
#include <queue>
using std::priority_queue;
#include <string>
using std::string;

struct Node{
public:
    Node(char ch){ _ch = ch; }
    Node(char ch, int freq, Node* left, Node* right)
    :_ch(ch),_freq(freq),_left(left),_right(right){}  
   

    bool isLeaf(){  return _left == nullptr && _right == nullptr; }
    int compareTo(Node* that) { return _freq - that->_freq; }

    char _ch;
    int _freq = 0;
    Node* _left = nullptr, *_right = nullptr;
};


struct cmp
{
    bool operator()(Node* a, Node* b)
    {
        return a->_freq > b->_freq;
    }
};

class Huffman{
public:
    Huffman() 
    {  _st.resize(R); }

    ~Huffman(){ 
        destruct(_root); 
    }

    void compress(string _s);
    Node* buildTrie(vector<int> freq);
    string to_string();

    string st(int i) {  return _st[i]; }
    string _s;
private:
    void buildCode(vector<string>& st, Node* x, string s);
    void destruct(Node* node);


    int R = 128;
    Node* _root;
    vector<string> _st;
    string _res;
};

void 
Huffman::destruct(Node* node){
    if(node == nullptr)
        return;
    destruct(node->_left);
    destruct(node->_right);
    delete node;
}

Node* 
Huffman::buildTrie(vector<int> freq){
    priority_queue<Node*, vector<Node*>, cmp> pq;
    for(int c = 0; c < R; c++){
        if(freq[c] > 0)
            pq.push(new Node(c, freq[c], nullptr, nullptr));
    }

    while(pq.size() > 1){
        Node* x = pq.top();
        pq.pop();
        Node* y = pq.top();
        pq.pop();
        Node* parent = new Node('\0', x->_freq+y->_freq, x, y);
        pq.push(parent);
    }

    Node* root = pq.top();
    pq.pop();
    return root;
}


void 
Huffman::buildCode(vector<string>& st, Node* x, string s){
    if(!x->isLeaf()) {  
        buildCode(st, x->_left, s+'0');
        buildCode(st, x->_right, s+'1');
    }else
        st[x->_ch] = s;
}

void
Huffman::compress(string _s){
    vector<int> freq(R,0);
    for(char c:_s)
        freq[c]++;  
    //to measure the non-null element

    _root = buildTrie(freq);

    buildCode(_st, _root, "");

    _res = _s;
}


string
Huffman::to_string(){
    string ans = "";
    
    for(int i = 0; i < _res.size(); i++){
        
        string code = _st[_res[i]];
        for(int j = 0; j < code.length(); j++)
        if(code[j] == '1')
            ans+='1';
        else
            ans+='0';
    }

    return ans;
}


#endif

