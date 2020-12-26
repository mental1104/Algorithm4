# Searching

`g++ frequency.cpp`    
`./a.out`  

This section is to compare different data structure to construct a tool to measure how frequently a word in a texts appears.  

e.g: 'better' appears 88 times in tale.txt  

## Implementation

### [Linked-List](./linked_list.h)  

### [BinarySearch](./binarysearch.h)

### [BinarySearch Tree](./BST.h)  

### [Balanced-BinarySearch Tree/Red-Black Tree](./RB_tree.h)  

### HashTable  

#### [SeparateChain](./SeparateChain.h)  

#### [LinearProbing](./LinearProbing.h)  



## Run-Time Effiency(Theoretically)  

Warning: for simplicity, there are STL such as vector and string in some of the data structure, whose effects for efficency should be ignored.   

Construction(N≈10K):  

Linked-list construction time: 8.72703s. 
> The slowest one, to put an element needs a traverse(O(N)) and then put that elements at the top of the list(O(1)), so for N its complexity would be reaching O(N^2). 

BinarySearch construction time: 0.815428s.   
> Cause BinarySearch needs element sorted, so put every elements in the vector needs binarysearch(O(logN)) and the complexity for inserting in sorted array would be O(N).  

BST construction time: 0.112996s.  
> Due to the excellent performace of tree, search would cause O(logN) and put an element consume O(logN) as well, the only thing which whould be considered is whether it's balanced.  

RB_tree construction time: 0.136813s.  
> Since our source file just contained 10K elements, Red-Black tree may not be much superior than its property appears. Plus, due to its coloring operation, the total time is even longer than imbalanced BST.  

HashTable(SeparateChain) construction time: 0.065271s.  
> I do prefer SeparateChain than LinearProbing. it's nothing but an array with every Node* elements in it. Although put operation is a little slower than linear probing, it does not need to worry about conflict and resize. But the greatest shortcoming is, it's not sorted.  

HashTable(LinearProbing) construction time: 0.045653s.  
> Resize would cause a great deal of waste in space. But at run-time it presents a greater performance than separate chain. However, delete an element is LinearProbing would be an intricate problem...  


| |Dynamic |    Static (ms)| 
| --- |---| ---|
|linked-list  |  0.17ms  |   0.092ms |
|BinarySearch     |   0.266ms  |   0.001ms |
|BST             |    0.003ms   |  0.001ms |
|RB_tree        |     0.006ms   |  0.001ms |
|HashTable(SC) |     0.005ms    | 0.002ms |
|HashTable(LP)|      0.002ms    | 0.001ms |