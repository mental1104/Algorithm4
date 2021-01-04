#ifndef REGULAR_EXPRESSION_PATTERN_MATCHING_5_9
#define REGULAR_EXPRESSION_PATTERN_MATCHING_5_9

#include "../../chapter4/header/digraph.h"
#include "../../chapter4/header/reachability.h"
#include <string>
#include <stack>
#include <deque>
using std::deque;
using std::stack;
using std::string;

class NFA{
public:
    NFA(string regexp);
    ~NFA() { delete G; }
    bool recognize(string txt);
private:
    string _re;
    Digraph* G;
    int M;
};

NFA::NFA(string regexp):_re(regexp){
    stack<int> ops;
    M = _re.length();
    G = new Digraph(M+1);

    for(int i = 0; i<M; i++){
        int lp = i;
        if(_re[i] == '(' || _re[i] == '|')
            ops.push(i);
        else if(_re[i] == ')')
        {
            int _or = ops.top();
            ops.pop();
            if(_re[_or] == '|')
            {
                lp = ops.top();
                ops.pop();
                G->addEdge(lp, _or+1);
                G->addEdge(_or, i);
            }
            else lp = _or;
        }
        if(i < M-1 && _re[i+1] == '*')
        {
            G->addEdge(lp, i+1);
            G->addEdge(i+1, lp);
        }
        if(_re[i] == '(' || _re[i] == '*' || _re[i] == ')')
            G->addEdge(i, i+1);
    }
}

bool
NFA::recognize(string txt){
    deque<int> pc;
    DirectedDFS* dfs = new DirectedDFS(G, 0);
    for(int v = 0; v<G->V(); v++)
        if(dfs->marked(v)) pc.push_front(v);
    
    for(int i = 0; i < txt.length(); i++)
    {
        deque<int> match;
        for(int v: pc)
            if(v < M)
                if(_re[v] == txt[i] || _re[v] =='.')
                    match.push_front(v+1);
        pc.clear();
        dfs = new DirectedDFS(G, match);
        for(int v = 0; v<G->V(); v++)
            if(dfs->marked(v)) pc.push_front(v);
    }
    for(int v: pc) if(v == M) return true;
    return false;
}
#endif