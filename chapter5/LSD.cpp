#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

#include "./header/LSD.h"

using namespace::std;

int main(){
    ifstream is("./testfile/license.txt");
    string temp;
    vector<string> vec;
    while(getline(is, temp))
        vec.push_back(temp);

    clock_t begin, end;
    cout << "Before LSD Sorting...." << endl;
    for(string i:vec)
        cout << i << endl;
    cout << "After LSD Sorting...." << endl;

    begin = clock();
    LSD::sort(vec, 7);
    end = clock();

    double time_val = double(end - begin)/CLOCKS_PER_SEC;
    cout << "Sort time: " << time_val << "s. " << endl;

    for(string i:vec)
        cout << i << endl;
    return 0;

}