#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>

#include "selectionsort.h"
#include "insertionsort.h"
#include "shellsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"

using namespace::std;

int main(){
    ifstream int32K;
    //int8K.open("8Kints.txt"); 
    //int16K.open("16Kints.txt"); 
    int32K.open("32Kints.txt"); 

    ofstream res;
    res.open("res.txt");

    int temp;
    vector<int> vec32K;

    /*while(int8K>>temp)
        vec8K.push_back(temp);
    while(int16K>>temp)
        vec16K.push_back(temp);*/

    while(int32K>>temp)
        vec32K.push_back(temp);

    //int8K.close();
    //int16K.close();
    int32K.close();

    vector<int> selection, insertion, shell, merge_bu, merge_td, quick, quick3way, heap;

    selection = vec32K;
    insertion = vec32K;
    shell = vec32K;
    merge_bu = vec32K;
    merge_td = vec32K;
    quick = vec32K;
    quick3way = vec32K;
    heap = vec32K;

    clock_t start,end;

    //selection sort 
    start = clock();
    Selection::sort(selection);
    end = clock();
    
    double selection_32K = double(end-start)/CLOCKS_PER_SEC;

    //insertion sort
    start = clock();
    Insertion::sort(insertion);
    end = clock();

    double insertion_32K = double(end-start)/CLOCKS_PER_SEC;

    //shell sort 
    start = clock();
    Shell::sort(shell);
    end = clock();

    double shell_32K = double(end-start)/CLOCKS_PER_SEC;

    //merge sort bottom_up 
    BottomUpMerge* bottom_up_merge = new BottomUpMerge();

    start = clock();
    bottom_up_merge->sort(merge_bu);
    end = clock();

    delete bottom_up_merge;
    bottom_up_merge = nullptr;

    double merge_bu_32K = double(end-start)/CLOCKS_PER_SEC;

    //merge sort top_down 
    TopDownMerge* top_down_merge = new TopDownMerge();

    start = clock();
    top_down_merge->sort(merge_td);
    end = clock();

    delete top_down_merge;
    top_down_merge = nullptr;

    double merge_td_32K = double(end-start)/CLOCKS_PER_SEC;

    // quick sort
    start = clock();
    Quick::sort(quick);
    end = clock();

    double quick_32K = double(end-start)/CLOCKS_PER_SEC;

    // quick-3way 
    start = clock();
    Quick::quick3way(quick3way);
    end = clock();

    double quick3way_32K = double(end-start)/CLOCKS_PER_SEC;

    // heap sort
    start = clock();
    Heap::sort(heap);
    end = clock();

    double heap_32K = double(end-start)/CLOCKS_PER_SEC;

    res << "For 32K random int: " << endl;
    res << "SelectionSort:  " << selection_32K << "s\n" << endl;
    res << "InsertionSort:  " << insertion_32K << "s  " << selection_32K/insertion_32K
        << " times faster than SelectionSort.\n" << endl;
    res << "ShellSort:  " << shell_32K << "s  " << selection_32K/shell_32K
        << " times faster than SelectionSort.\n" << endl;
    res << "MergeSort(BottomUp):  " << merge_bu_32K << "s  " << selection_32K/merge_bu_32K
        << " times faster than SelectionSort.\n" << endl;
    res << "MergeSort(TopDown):  " << merge_td_32K << "s  " << selection_32K/merge_td_32K 
        << " times faster than SelectionSort.\n" << endl;
    res << "Quicksort:  " << quick_32K << "s  " << selection_32K/quick_32K 
        << " times faster than SelectionSort.\n" << endl;
    res << "Quicksort(3way):  " << quick3way_32K << "s  " << selection_32K/quick3way_32K 
        << " times faster than SelectionSort.\n" << endl;   
    res << "heapsort:  " << heap_32K << "s  " << selection_32K/heap_32K 
        << " times faster than SelectionSort.\n" << endl;   

    res << "\n\nBefore Sort:" << endl;
    res << "---------------------------------------------------------------------\n\n" << endl;
    for(int i: vec32K)
        res << i << " ";
    res << endl;

    res << "\n\nAfter Sort(take quicksort as example):" << endl;
    res << "---------------------------------------------------------------------\n\n" << endl;
    for(int i: quick)
        res << i << " ";
    res << endl;
    
    res.close();

    return 0;
}