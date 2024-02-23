# I2P hw





## Array/ Loop/ Others

use 2D array to solve questions like map operations.
*Careful for iteration exceeds the boundary will cause seg fault error
13648(mid1-3)_textmaze
14007(hw4-1)_convolution

for/ whil loop.
14049(mid1-2)_domoTreasure
13991(lab3-2)_palindrome
14018(mid1-6)_domoHack2 (challenging with lots of edge case testing)
Others
to find pattern or other solutions

---
## Recursion
1.	Base case/ or termination condition of the recursive function itself. 
Basic step: it is the base case it holds. Like in MMI, define the result of n = 1;
Termination condition: 
some of recursion starts from the result and backward to find the root, or from the start and move forward to verify if result == ideal output(terminate condition). 
Take the backward example, it is like the function start with n= 10 for initial input argument and it has n – 1 as input to keep decrease. Then, in this case, the ending condition can be if n = 0 , return;
It is usually written on the top inside the function. 
2.	Recursive (inductive part): as the above example, keep calling itself of the function until it meets the condition of termination.
Notes: it will keep finished the smallest part and go to next iteration. See DFS concept. 
in MMI:
(1) define n = 1 holds
(2) assume n -1 holds, then prove n still hold. for example, that n = 2 as n-1 = 1 holds 2 holds. N = 3 as n – 1 =2 holds, n holds…



* tips: 
(1)we can use step+1 in parameter to track how many times we call the function 
(2)usually declare the map globally and avoid duplicate declaration(common error!). but for swapMap it need it as parameter when calling the funciton
(3)use simple hanoi case to fully understand how recursion iterate break down
* inside recursion it call one recursion
13420(mid2-3)_domoTravel
12604(mid2-1)_NqueenMrook
  
* inside recurison it call multiple recursions with different aurguments
usually call four directions to return the value or true false. 
Unlike above call one recursion itselt, which we can terminate it to return the value once it call the recurison function one more time as the final and hit the base case(terminate case) to terminate. 
If calling multiple recursions function with different directions, we need to one step ahead to determine each branches true/ false.
See SwapMap. 

13014(mid2-2)_swapMap
14072(hw7-2)_count24
14042(hw6-3)_CapybaraHunts
14074(hw7-3)_quadtreeMatrix
14071(hw7-1)_quadtreePosition


## Dynamic Programming

Dynamic Programming is mainly an optimization over plain recursion. Wherever we see a recursive solution that has repeated calls for the same inputs, we can optimize it using Dynamic Programming. The idea is to simply store the results of subproblems so that we do not have to re-compute them when needed later. This simple optimization reduces time complexities from exponential to polynomial.

reading source: 
[DP Tutorial](<https://www.geeksforgeeks.org/introduction-to-dynamic-programming-data-structures-and-algorithm-tutorials/>) / [Recursion and DP](<https://www.geeksforgeeks.org/difference-between-recursion-and-dynamic-programming/>) / [DP others](<https://www.geeksforgeeks.org/dynamic-programming/>)

See: Climb1- recur/ BP/ TD.c
recurison will duplicate to run the function with same result. Time complexity is 2^(n-1)
if we declare space to store the ans to avoid duplicately calling
time complexity is n times (see BP bottom up, TD top down)

others:
14101(mid2-4)_domo3D

## Pointer
We usually declare the variable globally, so that we can call different functions to modify the global variable values.
What if we declare variable in main(), and trying to modify the value use function ?

We can declare a pointer varaible like int *a; it means the pointer pointer to a int value. The pointer itself stores the memory address. We can use the pointer to change the variable that is outside of its scope. 

The concept will be used in following Dynamic Memory Allocation, linked list, string...

## Dynamic Memory Allocation

We often allocate the memory at the complile time. For example, in map questions, we declare possible maximum map size char map[500][500]; and when at run time scanf("%d %d", &h, &w), then use h, w to create the map. What if we want to decide how many memory we need to allocate at the run time?
if we use char map[h][w]; scanf("%d %d", &h, &w), although VLA supports this, but it may cause untrackable error!

use malloc and free to allocate and free the memory we declare.
*malloc and free is a pair, once you malloc a space, must free it before the end

2D question: 13361(hw9-1)_cardtable
3D question: 11711(hw8-1)_malloc3Darr

## Struct and Linked List

Struct is like object that we can package some different types of variables into one element we can use.
details to use : [link](<https://hackmd.io/kzL_SafUQgekPLZQ8YHGsg>)

Using malloc, we allocate Node space during the run time and append it to link with Dummy(head)node to crate a linked list. 

13391(fin-4)_domoConductor
14180(fin-5)_domoCircularInsert

operations: Add front, back, insert after certain node, swap
(1) If we need to opearte the certain node, we should start from the head and get to the node we need to operate.
(2) In the function, we declare the Node locally, how we can still print it in main function ? 

The memory allocated using malloc within a function persists beyond the function's scope if the pointer pointing to that memory is passed outside the function.
If you create a newNode within a function and do not link it to any existing data structures outside that function, it will indeed persist in memory after the function ends. However, without a reference to that memory space, you won't be able to access or use it further in your program, resulting in a memory leak.

## String operation
Use function in <string.h>, the concept is using pointer to points to which memory cell of the char array.
use function to parsing the text

quesitons
12544(final-1)_web crawl
14136(hw9-3)_ZoroSlash

## Sort and Select

bubble sort
insert sort
quick sort
merge sort 
14156(hw10-2)_MergeSort

quick select: to find the k-th smallest string
14101(hw8-4)_QuickSelect

## Stack and Queue

queue: u15-queue
stack: u15-stack
use stack to solve problem
14182(fin-6)_removeKdigits

## Binary Opeartion
& ^ << >>
use mask to get power set:
14134(hw9-2)_PowerSet
14109(mid2-5)_HUTI
