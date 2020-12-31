# Graph  

For handier generic support, this chapter I use a lot of STL.  

## [Undirected Graph](./header/graph.h)

### [4.1 Depth-First Search](./header/dfs.h)  

### [4.2 Breadth-First Search](./header/bfs.h)  

**for both bfs and dfs:**  
`g++ paths.cpp`  
`./a.out ./testfile/tinyCG.txt 0`  

```
Results for DFS: 

0 to 0: 0
0 to 1: 0-2-1
0 to 2: 0-2
0 to 3: 0-2-3
0 to 4: 0-2-3-4
0 to 5: 0-2-3-5

Results for BFS: 

0 to 0: 0
0 to 1: 0-1
0 to 2: 0-2
0 to 3: 0-2-3
0 to 4: 0-2-4
0 to 5: 0-5
``` 

### [4.3 Connected Components](./header/CC.h)   
`g++ CC.cpp`  
`./a.out ./testfile/tinyG.txt`  
```
3 Components
0 1 2 3 4 5 6 
7 8 
9 10 11 12 
```

## [Directed Graph](./header/digraph.h)  

+ [symbol digraph.h](./header/symboldigraph.h)  

### [4.4 Reachability](./header/reachability.h)  
`g++ reachability.cpp`  
`./a.out ./testfile/tinyDG.txt`  
```
> Input the number. 
1
> OK, next one.(Ctrl+D to break) 
2
> OK, next one.(Ctrl+D to break) 
6
> OK, next one.(Ctrl+D to break) 
0 1 2 3 4 5 6 8 9 10 
```  

### [4.5 Topological Sort](./header/topological.h)
+ [Finding a directed cycle](./header/cycle.h)  
+ [Depth-first Search vertex ordering in a digraph](./header/dfo.h)  


`g++ topological.cpp`  
`./a.out ./testfile/jobs.txt /`  
```
Calculus
Linear Algebra
Introduction to CS
Advanced Programming
Algorithms
Theoretical CS
Artificial Intelligence
Robotics
Machine Learning
Neural Networks
Databases
Scientific Computing
Computational Biology
```  
`./a.out ./testfile/booklist.txt /`  
```
Calculus
Statistic Inference
Linear Algebra
Discrete Mathematics
Python Crashbook
C Primer Plus
C++ Primer
Data Structure
Algorithm 4
Fluent Python
Introduction to Computer System
Operating System
MIT 6.828
Computer Network
CS144
Advanced Programing in the UNIX Environment
UNIX Network Programing
Compiler
Linux Kernel Development
Computer Organization
Database System Concept
High Performance MySQL
Introduction to Algorithms
Concrete Mathematics
Operation-research-applications-and-algorithms
Effective C++
Effective Modern C++
Structure and Interpretation of Computer Programs
Desgin Pattern
Clean Code
The Mythical Man-Month
C++ Templates
Effective STL
C++ Concurrency in Action
Designing Data-Intensive applications
Professional JavaScript
```  

### [4.6 Kosaraju's Algorithm for Computing Strong Components](./header/kosarajuSCC.h)  

`g++ kosarajuSCC.cpp`  
`./a.out ./testfile/tinyDG.txt`  
```
5 Components
1 
0 5 4 3 2 
11 12 9 10 
6 8 
7 
```  
## Minimum Spanning Tree 
+ [Undirected Weighted Graph](./header/EWG.h)  

### [Lazy version of Prim's MST algorithm](./header/lazyPrim.h)

`g++ lazyPrim.cpp`  
`./a.out ./testfile/tinyEWG.txt`  
```
0-7 0.16
1-7 0.19
0-2 0.26
2-3 0.17
5-7 0.28
4-5 0.35
6-2 0.40
Total weight: 1.81
```  

### [4.7 Prim's MST Algorithm(eager version)](./header/eagerPrim.h)  
`g++ eagerPrim.cpp`  
`./a.out ./testfile/mediumEWG.txt`  
```
1-107 0.07
2-51 0.05
3-67 0.10
4-78 0.03
5-26 0.03
6-236 0.06
7-157 0.01
8-244 0.03
9-23 0.04
10-175 0.07
11-244 0.07
12-198 0.06
13-100 0.03
14-133 0.07
0-15 0.06
6-16 0.05
17-182 0.09
18-86 0.03
19-174 0.02
20-116 0.02
21-233 0.04
22-56 0.02
23-33 0.06
24-209 0.03
25-111 0.05
26-77 0.04
21-27 0.02
28-198 0.01
29-218 0.03
30-244 0.01
31-241 0.08
32-187 0.05
33-114 0.09
34-73 0.02
12-35 0.06
36-88 0.02
37-153 0.04
38-126 0.01
39-149 0.05
40-164 0.03
41-182 0.04
42-135 0.05
43-207 0.03
44-204 0.02
45-83 0.03
46-169 0.07
47-218 0.03
48-232 0.02
49-225 0.03
50-59 0.04
51-70 0.08
52-187 0.03
53-229 0.09
16-54 0.07
4-55 0.06
53-56 0.06
57-65 0.07
58-114 0.02
59-97 0.06
25-60 0.03
61-87 0.05
62-240 0.07
63-199 0.02
64-137 0.04
65-188 0.04
39-66 0.06
45-67 0.06
68-176 0.04
69-173 0.05
19-70 0.07
21-71 0.04
1-72 0.07
22-73 0.05
74-215 0.05
75-116 0.03
37-76 0.03
77-102 0.03
78-239 0.02
70-79 0.02
80-225 0.06
81-134 0.05
11-82 0.04
83-232 0.07
84-174 0.03
82-85 0.04
86-141 0.06
87-130 0.04
35-88 0.07
75-89 0.03
62-90 0.09
91-137 0.01
92-235 0.06
44-93 0.07
35-94 0.06
37-95 0.09
96-199 0.02
49-97 0.03
36-98 0.09
99-147 0.03
19-100 0.06
101-125 0.11
102-226 0.08
103-243 0.06
104-201 0.03
105-193 0.03
106-193 0.02
107-173 0.09
108-196 0.03
109-137 0.05
110-214 0.03
61-111 0.07
112-159 0.04
113-223 0.05
114-222 0.02
37-115 0.01
116-164 0.04
16-117 0.05
57-118 0.08
119-145 0.05
53-120 0.03
121-170 0.03
122-205 0.01
10-123 0.01
124-213 0.03
57-125 0.06
126-215 0.06
89-127 0.11
128-239 0.02
129-166 0.03
130-194 0.06
131-143 0.06
132-235 0.06
100-133 0.08
119-134 0.05
135-141 0.07
136-234 0.03
137-146 0.04
77-138 0.07
101-139 0.04
54-140 0.03
94-141 0.08
142-213 0.03
143-244 0.08
144-248 0.02
53-145 0.07
146-227 0.05
140-147 0.05
148-157 0.02
15-149 0.04
150-220 0.04
151-208 0.00
8-152 0.01
3-153 0.05
154-238 0.02
155-213 0.02
156-205 0.05
125-157 0.03
158-249 0.06
136-159 0.02
93-160 0.04
161-186 0.06
147-162 0.09
163-211 0.02
1-164 0.11
118-165 0.08
133-166 0.07
167-224 0.08
168-231 0.00
169-186 0.06
170-223 0.04
171-213 0.07
172-213 0.06
90-173 0.07
103-174 0.04
175-246 0.04
176-202 0.04
177-189 0.04
178-236 0.03
70-179 0.07
165-180 0.02
157-181 0.05
182-198 0.08
183-215 0.03
57-184 0.03
50-185 0.06
177-186 0.04
187-231 0.04
27-188 0.04
72-189 0.04
40-190 0.04
176-191 0.02
103-192 0.04
131-193 0.01
89-194 0.05
9-195 0.05
101-196 0.03
57-197 0.03
113-198 0.05
25-199 0.08
200-203 0.06
201-248 0.07
0-202 0.05
72-203 0.03
49-204 0.03
139-205 0.02
66-206 0.05
207-221 0.03
52-208 0.03
209-211 0.01
210-221 0.04
15-211 0.04
207-212 0.06
180-213 0.03
156-214 0.03
109-215 0.06
48-216 0.08
83-217 0.04
146-218 0.06
156-219 0.01
40-220 0.03
219-221 0.07
202-222 0.05
158-223 0.05
47-224 0.05
0-225 0.02
52-226 0.02
134-227 0.04
228-241 0.01
17-229 0.07
184-230 0.05
93-231 0.04
201-232 0.04
62-233 0.03
87-234 0.08
171-235 0.03
98-236 0.04
63-237 0.05
171-238 0.06
239-240 0.11
138-240 0.02
153-241 0.04
28-242 0.03
193-243 0.09
212-244 0.04
238-245 0.06
11-246 0.07
190-247 0.07
185-248 0.03
203-249 0.04
Total weight: 11.3584
```  

### [4.8 Kruskal's MST Algorithm](./header/kruskal.h)  

`g++ kruskal.cpp`  
`./a.out ./testfile/tinyEWG.txt`  
```
0-7 0.16
2-3 0.17
1-7 0.19
0-2 0.26
5-7 0.28
4-5 0.35
6-2 0.40
Total weight: 1.81
```  
## Shortest Paths
+ [directed Weighted Graph](./header/EWDG.h)  
+ [A index(int)-double mapping struct for the handier use of STL priority_queue](./header/mapping.h)  

### [4.9 Dijkstra's Shortest-Paths Algorithm](./headerDjijkstra.h)  
`g++ Dijkstra.cpp`  
`./a.out ./testfile/tinyEWD.txt 0`  
```
0 to 0 (0.00): 
0 to 1 (1.05): 0-4 0.38    4-5 0.35    5-1 0.32    
0 to 2 (0.26): 0-2 0.26    
0 to 3 (0.99): 0-2 0.26    2-7 0.34    7-3 0.39    
0 to 4 (0.38): 0-4 0.38    
0 to 5 (0.73): 0-4 0.38    4-5 0.35    
0 to 6 (1.51): 0-2 0.26    2-7 0.34    7-3 0.39    3-6 0.52    
0 to 7 (0.60): 0-2 0.26    2-7 0.34    
```  

### [4.10 Shortest Paths in Edge-Weighted DAGS](./header/acyclic.h)  

`g++ acyclic.cpp`  
`./a.out ./testfile/tinyEWDAG.txt 5`  
```
5 to 0 (0.73): 5-4 0.35    4-0 0.38    
5 to 1 (0.32): 5-1 0.32    
5 to 2 (0.62): 5-7 0.28    7-2 0.34    
5 to 3 (0.61): 5-1 0.32    1-3 0.29    
5 to 4 (0.35): 5-4 0.35    
5 to 5 (0.00): 
5 to 6 (1.13): 5-1 0.32    1-3 0.29    3-6 0.52    
5 to 7 (0.28): 5-7 0.28      
```  

### [4.11 Bellman-Ford Algorithm(queue-based)](./header/bellman.h)  

`g++ bellman.cpp`  
`./a.out ./testfile/tinyEWDn.txt 0`  
```
0 to 0 (0.00): 
0 to 1 (0.93): 0-2 0.26    2-7 0.34    7-3 0.39    3-6 0.52    6-4 -1.25    4-5 0.35    5-1 0.32    
0 to 2 (0.26): 0-2 0.26    
0 to 3 (0.99): 0-2 0.26    2-7 0.34    7-3 0.39    
0 to 4 (0.26): 0-2 0.26    2-7 0.34    7-3 0.39    3-6 0.52    6-4 -1.25    
0 to 5 (0.61): 0-2 0.26    2-7 0.34    7-3 0.39    3-6 0.52    6-4 -1.25    4-5 0.35    
0 to 6 (1.51): 0-2 0.26    2-7 0.34    7-3 0.39    3-6 0.52    
0 to 7 (0.60): 0-2 0.26    2-7 0.34 
```  





