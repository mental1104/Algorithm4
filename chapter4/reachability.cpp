#include "./header/digraph.h"
#include "./header/reachability.h"
#include<deque>
#include<fstream>

using namespace::std;


int main(){
    ifstream is("./testfile/tinyDG.txt");
    Digraph *G = new Digraph(is);

    int temp;
    deque<int> vec;
    cout << "> Input the number. " << endl;
    while(cin >> temp){
        vec.push_back(temp);
        cout << "> OK, next one.(Ctrl+D to break) " << endl;
    }

    DirectedDFS* reachable = new DirectedDFS(G, vec); 

    for(int v = 0; v < G->V(); v++)
        if(reachable->marked(v)) cout << v << " ";
    cout << endl;

    delete reachable;
    reachable = nullptr;

    delete G;
    G = nullptr;

    return 0;
}