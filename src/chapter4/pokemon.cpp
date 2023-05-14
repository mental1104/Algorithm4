//This is a simple program to check the strong connectivity among 18 different elements.
#include "kosarajuSCC.h"
#include <unordered_map>
#include <fstream>

int main(){
    vector<string> pokemon
    {
        "normal",
        "fire",
        "water",
        "Electric",
        "grass",
        "ice",
        "fighting",
        "poison",
        "ground",
        "flying",
        "psychic",
        "bug",
        "rock",
        "ghost",
        "dragon",
        "dark",
        "steel",
        "fairy"
    };
    ifstream is("./testfile/pokemon.txt");
    Digraph* graph = new Digraph(is);
    KosarajuSCC* components = new KosarajuSCC(graph);
    cout << components->count() << " Components" << endl;
    for(vector<int> vec1: components->strongComponents()){
        for(int i: vec1)
            cout << pokemon[i] << " ";
        cout << endl;
    }
    delete graph;
    graph = nullptr;
    delete components;
    components = nullptr;
}