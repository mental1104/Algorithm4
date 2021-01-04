#include <iostream>
#include "./header/regular_expression.h"
#include <string>
#include <fstream>

using namespace::std;

int main(int argc, char** argv){
    if(argc!=2){
        cout << "You must enter one extra parameter!" <<endl;
        return 0;
    }
    string regexp = "";
    regexp+= "(.*";
    regexp+= argv[1];
    regexp+= ".*";
    NFA* nfa = new NFA(regexp);

    ifstream is("./testfile/tinyL.txt");
    string temp;
    while(getline(is, temp))
        if(nfa->recognize(temp))  
            cout << temp << endl;

    delete nfa;
    nfa = nullptr;
    return 0;
}