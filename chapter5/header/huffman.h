#ifndef HUFFMAN_COMPRESSION_5_10
#define HUFFMAN_COMPRESSION_5_10

#include <vector>
using std::vector;
#include <queue>
using std::priority_queue;
#include <string>
using std::string;
#include "./binaryIn.h"
#include "./binaryOut.h"

vector<bitset<8>> int_cre(int num){
    vector<bitset<8>> vec;
    for(int i = 24; i>=0;i=i-8){
        int t = (num >> i);
        bitset<8> temp(t);
        vec.push_back(temp);
    }
    return vec;
}

int bit_to_int(vector<bitset<8>> vec){
    int ans = 0;
    unsigned long i1 = vec[0].to_ulong();
    unsigned long i2 = vec[1].to_ulong();
    unsigned long i3 = vec[2].to_ulong();
    unsigned long i4 = vec[3].to_ulong();
    ans |= (i1 << 24);
    ans |= (i2 << 16);
    ans |= (i3 << 8);
    ans |= i4;
    return ans;
}

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
    Huffman(istream* in, ostream* out, ostream* trie):inFile(new BinaryIn(in)),outFile(new BinaryOut(out)),
                                                      Trie_out(new BinaryOut(trie))
    {  _st.resize(R); }
    Huffman(istream* in, istream* trie, ostream* out):inFile(new BinaryIn(in)),Trie_in(new BinaryIn(trie)),
                                                      outFile(new BinaryOut(out))
    {  _st.resize(R); }

    ~Huffman(){ 
        destruct(_root); 
        delete inFile;
        inFile = nullptr;
        delete outFile;
        outFile = nullptr;
    }

    void compress();
    void expand();

    Node* buildTrie(vector<int> freq);
    void writeTrie() { writeTrie(_root); }
    
    string to_string();

    string st(int i) {  return _st[i]; }
    string _s;
private:
    
    Node* readTrie();
    void writeTrie(Node* x);
    void buildCode(vector<string>& st, Node* x, string s);
    void destruct(Node* node);


    int R = 128;
    Node* _root;
    vector<string> _st;
    string _res;
    BinaryIn* inFile;
    BinaryIn* Trie_in;
    BinaryOut* outFile;
    BinaryOut* Trie_out;

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
Huffman::writeTrie(Node* x){
    if(x->isLeaf()){
        Trie_out->write(true);
        Trie_out->write(bitset<8>(x->_ch));
        return;
    }
    Trie_out->write(false);
    writeTrie(x->_left);
    writeTrie(x->_right);
}

Node* 
Huffman::readTrie(){
    if(Trie_in->readBool()){
        bitset<8> temp = Trie_in->readChar();
        return new Node(*reinterpret_cast<char*>(&temp), 0, nullptr, nullptr);
    }
    return new Node('\0', 0, readTrie(), readTrie());
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
Huffman::compress(){
    vector<bitset<8>> s = inFile->readString();
    string _s = "";
    for(bitset<8> i: s)
        _s+=*reinterpret_cast<char*>(&i);
    vector<int> freq(R,0);
    for(char c:_s)
        freq[c]++;  
    //to measure the non-null element

    _root = buildTrie(freq);

    buildCode(_st, _root, "");

    _res = _s;

    writeTrie(_root);

    int num = _s.size();//logical right shift
     
    outFile->write(int_cre(num));

    for(int i = 0; i < num; i++){
        string code = _st[_s[i]];
        for (int j = 0; j <code.size(); j++)
            if (code[j] == '1')
                outFile->write(true);
            else    
                outFile->write(false);
    }
    outFile->clearBuffer();
}

void 
Huffman::expand(){
    Node* root = readTrie();
    int N = bit_to_int(inFile->readInt());
    for(int i = 0;i<N; i++){
        Node* x = root;
        while (!x->isLeaf())
            if(inFile->readBool())
                x = x->_right;
            else x = x->_left;
        outFile->write(bitset<8>(x->_ch));
    }
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

