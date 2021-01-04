## KMP 

Since char can be negative(between -128 - 127), to support the ASCII code beyond 127 might need more code to implement. Negative num cannot be the index to an array or a container. So to convenience our test and solely reinforce our understanding in KMP, I just implement a simple version that can only support lower and upper case of letters (it cannot even support spacehold!).  

If you want to construct a more robust version of KMP, you can modify the small fraction of codes to implement it.

It foresee the future and create a customed table to predict where the substring's going.  

`g++ KMP.cpp`  
`./a.out AACAA AABRAACADABRAACAADABRA`  

```
text:    AABRAACADABRAACAADABRA
pattern:             AACAA
```

`./a.out thing Withoutstrengthyoucannotprotectanything`  

```
text:    Withoutstrengthyoucannotprotectanything
pattern:                                   thing
```

## 5.7 BoyerMoore  

It creates a small table for step to jump at. 

`g++ BM.cpp`  
`./a.out rol controls`  
```
text:    controls
pattern:     rol
```  

## 5.8 Rabin-Karp
`g++ RK.cpp`  
`./a.out red thatlastshredofhumanitythatyoustillhad`
```
text:    thatlastshredofhumanitythatyoustillhad
pattern:           red                         
```

## 5.9 Regular-Expression  
Finite State Machine.  
It needs digraph and DFS for digraph in chapter4.  
`g++ grep.cpp`  
`./a.out "(A*B|AC)D"`  
```
ABD
ABCCBD
```

## 5.10 Huffman-Encoding Compression
Not implementing the binaryInput and expand(), writeTrie(), readTrie().  
`g++ huffman.cpp`  
`./a.out ABRACADABRA!` 

```
Compression begins... 
after compressing:
0101111011010100010111101100

Trie Tree:
! 1100
A 0
B 101
C 1101
D 100
R 111
```

`./a.out Acanopenercanopencans`  
```
Compression begins... 
after compressing:
001011011101101100010001100001111011101101100010001110111011010

Trie Tree:
A 0010
a 111
c 110
e 100
n 01
o 1011
p 000
r 0011
s 1010
```
