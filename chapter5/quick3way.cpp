#include <iostream>
#include "./header/quick3way.h"
#include <fstream>

using namespace::std;

int main(){
    ifstream is("./testfile/msd.txt");
    string temp;
    vector<string> vec;
    while(getline(is, temp))
        vec.push_back(temp);

    clock_t begin, end;
    cout << "Before quick-3-string Sorting...." << endl;
    for(string i:vec)
        cout << i << endl;
    cout << "After quick-3-string Sorting...." << endl;
    begin = clock();
    Quick3string::sort(vec);
    end = clock();

    double time_val = double(end - begin)/CLOCKS_PER_SEC;
    cout << "Sort time: " << time_val << "s. " << endl;

    for(string i:vec)
        cout << i << endl;
    return 0;
}