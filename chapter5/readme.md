## KMP 

Since char can be negative(between -128 - 127), to support the ASCII code beyond 127 might need more code to implement. Negative num cannot be the index to an array or a container. So to convenience our test and solely reinforce our understanding in KMP, I just implement a simple version that can only support lower and upper case of letters (it cannot even support spacehold!).  

If you want to construct a more robust version of KMP, you can modify the small fraction of codes to implement it.

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

`g++ BM.cpp`  
`./a.out rol controls`  
```
text:    controls
pattern:     rol
```  

