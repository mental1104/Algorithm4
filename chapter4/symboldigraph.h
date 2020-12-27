#ifndef SYMBOL_GRAPH_IN_ALGORITHM_FOURTH
#define SYMBOL_GRAPH_IN_ALGORITHM_FOURTH

#include<string>
#include<vector>
#include<fstream>
#include<unordered_map>

using namespace::std;

#include "digraph.h"

void splitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{//why does STL stirng not support split string operation???
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
      v.push_back(s.substr(pos1, pos2-pos1));
 
      pos1 = pos2 + c.size();
      pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
      v.push_back(s.substr(pos1));
}

class SymbolDigraph{
public:
    SymbolDigraph(string stream, string sp);
    ~SymbolDigraph()  {     delete G;   }

    Digraph* graph() { return G; }
    int index(string s) { return st[s]; }
    string name(int v) { return keys[v]; }
    vector<string> names() { return keys; }
    
private:
    unordered_map<string, int> st;
    vector<string> keys;
    Digraph* G;
};

SymbolDigraph::
SymbolDigraph(string stream, string sp){
    ifstream is(stream);

    string temp;
    while(getline(is,temp)){
        vector<string> vec;
        splitString(temp, vec, sp);
        for(int i = 0; i<vec.size(); i++)
            if(st.find(vec[i])==st.end())
                st[vec[i]] = st.size(); 
    }
    keys.resize(st.size());
    for(auto name : st)
        keys[name.second] = name.first;

    G = new Digraph(st.size());
    is.close();

    ifstream is_1;
    is_1.open(stream);
    while(getline(is_1,temp)){
        vector<string> vec;
        splitString(temp, vec, sp);
        int v = st[vec[0]];
        for(int i = 1; i <vec.size(); i++)
            G->addEdge(v, st[vec[i]]);
    }


}

#endif