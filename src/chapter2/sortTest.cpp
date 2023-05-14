#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

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
    int32K.open("./testfile/32Kints.txt"); 

    ofstream res;
    res.open("res.txt");

    int temp;
    vector<int> vec32K;

    while(int32K>>temp)
        vec32K.push_back(temp);

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

    double merge_bu_32K = double(end-start)/CLOCKS_PER_SEC;

    //merge sort top_down 
    TopDownMerge* top_down_merge = new TopDownMerge();

    start = clock();
    top_down_merge->sort(merge_td);
    end = clock();

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

    //1kint
    ifstream int1K;
    int1K.open("./testfile/1Kints.txt");
    
    vector<int> small_file;
    while(int1K >> temp)
        small_file.push_back(temp);
    int1K.close();

    vector<int> insert_vec = small_file, 
                select_vec = small_file,
                shell_vec = small_file,
                merge_bu_vec = small_file,
                merge_td_vec = small_file,
                quick_vec = small_file,
                quick3way_vec = small_file,
                heap_vec = small_file;
    //small file for selection sort

    start = clock();
    Selection::sort(select_vec);
    end = clock();

    double selection_for_small_files = double(end-start)/CLOCKS_PER_SEC;

    //small file for insertion sort

    start = clock();
    Insertion::sort(select_vec);
    end = clock();

    double insertion_for_small_files = double(end-start)/CLOCKS_PER_SEC;


    //small file for shell sort
    start = clock();
    Shell::sort(shell_vec);
    end = clock();

    double shell_for_small_files = double(end-start)/CLOCKS_PER_SEC;

    //small file for merge sort bottom-up
    start = clock();
    bottom_up_merge->sort(merge_bu_vec);
    end = clock();


    double merge_bu_for_small_files = double(end-start)/CLOCKS_PER_SEC;

    //small file for merge sort top-down
    start = clock();
    top_down_merge->sort(merge_td_vec);
    end = clock();

    double merge_td_for_small_files = double(end-start)/CLOCKS_PER_SEC;

    //small file for quick sort
    start = clock();
    Quick::sort(quick_vec);
    end = clock();

    double quick_for_small_files = double(end-start)/CLOCKS_PER_SEC;

    //small file for quick-3way 
    start = clock();
    Quick::quick3way(quick3way_vec);
    end = clock();

    double quick3way_for_small_files = double(end-start)/CLOCKS_PER_SEC;

    // heap sort
    start = clock();
    Heap::sort(heap_vec);
    end = clock();

    double heap_for_small_files = double(end-start)/CLOCKS_PER_SEC;

    //1kint
    ifstream int8K;
    int8K.open("./testfile/8Kints.txt");
    
    vector<int> vec8K;
    while(int8K >> temp)
        vec8K.push_back(temp);
    int8K.close();

    vector<int> insert_8K = vec8K, 
                select_8K = vec8K,
                shell_8K = vec8K,
                merge_bu_8K = vec8K,
                merge_td_8K = vec8K,
                quick_8K = vec8K,
                quick3way_8K = vec8K,
                heap_8K = vec8K;
    //small file for selection sort

    start = clock();
    Selection::sort(select_8K);
    end = clock();

    double s8 = double(end-start)/CLOCKS_PER_SEC;

    //small file for insertion sort

    start = clock();
    Insertion::sort(insert_8K);
    end = clock();

    double i8 = double(end-start)/CLOCKS_PER_SEC;


    //small file for shell sort
    start = clock();
    Shell::sort(shell_8K);
    end = clock();

    double sh8 = double(end-start)/CLOCKS_PER_SEC;

    //small file for merge sort bottom-up
    start = clock();
    bottom_up_merge->sort(merge_bu_8K);
    end = clock();

    delete bottom_up_merge;
    bottom_up_merge = nullptr;

    double mb8 = double(end-start)/CLOCKS_PER_SEC;

    //small file for merge sort top-down
    start = clock();
    top_down_merge->sort(merge_td_8K);
    end = clock();

    delete top_down_merge;
    top_down_merge = nullptr;

    double mt8 = double(end-start)/CLOCKS_PER_SEC;

    //small file for quick sort
    start = clock();
    Quick::sort(quick_8K);
    end = clock();

    double q8 = double(end-start)/CLOCKS_PER_SEC;

    //small file for quick-3way 
    start = clock();
    Quick::quick3way(quick3way_8K);
    end = clock();

    double q38 = double(end-start)/CLOCKS_PER_SEC;

    // heap sort
    start = clock();
    Heap::sort(heap_8K);
    end = clock();

    double h8 = double(end-start)/CLOCKS_PER_SEC;
    

    res << "For 32K random int: " << endl;
    res << "SelectionSort:  " << selection_32K << "s\n" << endl;
    res << "InsertionSort:  " << insertion_32K << "s  " << selection_32K/insertion_32K
        << " times faster than SelectionSort." << endl;
    res << "ShellSort:  " << shell_32K << "s  " << selection_32K/shell_32K
        << " times faster than SelectionSort." << endl;
    res << "MergeSort(BottomUp):  " << merge_bu_32K << "s  " << selection_32K/merge_bu_32K
        << " times faster than SelectionSort." << endl;
    res << "MergeSort(TopDown):  " << merge_td_32K << "s  " << selection_32K/merge_td_32K 
        << " times faster than SelectionSort." << endl;
    res << "Quicksort:  " << quick_32K << "s  " << selection_32K/quick_32K 
        << " times faster than SelectionSort." << endl;
    res << "Quicksort(3way):  " << quick3way_32K << "s  " << selection_32K/quick3way_32K 
        << " times faster than SelectionSort." << endl;   
    res << "heapsort:  " << heap_32K << "s  " << selection_32K/heap_32K 
        << " times faster than SelectionSort.\n" << endl;   

    res << "\n\nFor 8Kint:" << endl;
    res << "Selection Sort for 8K int: " << s8 << "s" << endl;
    res << "Insertion Sort for 8K int: " << i8 << "s.  " << s8/i8
        << " times faster than selection sort." << endl;
    res << "Shell Sort for 8K int: " << sh8 << "s.  " << s8/sh8
        << " times faster than selection sort." << endl;
    res << "Merge Sort Bottom-Up for 8K int: " << mb8 << "s.  " << s8/mb8
        << " times faster than selection sort." << endl;
    res << "Merge Sort Top-Down for 8K int: " << mt8 << "s.  " << s8/mt8
        << " times faster than selection sort." << endl;
    res << "Quick Sort for 8K int: " << q8 << "s.  " << s8/q8
        << " times faster than selection sort." << endl;
    res << "Quick 3way for 8K int: " << q38 <<"s.  " << s8/q38
        << " times faster than selection sort." << endl;
    res << "Heap Sort for 8K int: " << h8 << "s.  " << s8/h8
        << " times faster than selection sort.\n" << endl; 

    res << "\n\nFor small files(1Kint):" << endl;
    res << "Selection Sort for 1K int: " << selection_for_small_files << "s" << endl;
    res << "Insertion Sort for 1K int: " << insertion_for_small_files << "s.  " << selection_for_small_files/insertion_for_small_files
        << " times faster than selection sort." << endl;
    res << "Shell Sort for 1K int: " << shell_for_small_files << "s.  " << selection_for_small_files/shell_for_small_files 
        << " times faster than selection sort." << endl;
    res << "Merge Sort Bottom-Up for 1K int: " << merge_bu_for_small_files << "s.  " << selection_for_small_files/merge_bu_for_small_files
        << " times faster than selection sort." << endl;
    res << "Merge Sort Top-Down for 1K int: " << merge_td_for_small_files << "s.  " << selection_for_small_files/merge_td_for_small_files
        << " times faster than selection sort." << endl;
    res << "Quick Sort for 1K int: " << quick_for_small_files << "s.  " << selection_for_small_files/quick_for_small_files
        << " times faster than selection sort." << endl;
    res << "Quick 3way for 1K int: " << quick3way_for_small_files <<"s.  " << selection_for_small_files/quick3way_for_small_files
        << " times faster than selection sort." << endl;
    res << "Heap Sort for 1K int: " << heap_for_small_files << "s.  " << selection_for_small_files/heap_for_small_files 
        << " times faster than selection sort.\n" << endl;  

    
    

/*
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
*/
    return 0;
}