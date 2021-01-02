#include <iostream>
#include <fstream>
#include <string>
#include "./header/MSD.h"
using std::string;


using namespace::std;

int main(){
    ifstream is("./testfile/msd.txt");
    string temp;
    vector<string> vec;
    while(getline(is, temp))
        vec.push_back(temp);

    clock_t begin, end;
    cout << "Before MSD Sorting...." << endl;
    for(string i:vec)
        cout << i << endl;
    cout << "After MSD Sorting...." << endl;
    MSD* msd = new MSD();
    begin = clock();
    msd->sort(vec);
    end = clock();

    double time_val = double(end - begin)/CLOCKS_PER_SEC;
    cout << "Sort time: " << time_val << "s. " << endl;

    delete msd;
    msd = nullptr;

    for(string i:vec)
        cout << i << endl;
    return 0;
}