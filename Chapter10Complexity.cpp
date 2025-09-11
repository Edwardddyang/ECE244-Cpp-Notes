/*
Big O notation - How code slow as data grows, n = amount of data 
1. Describes the performance of an algorithm as the amount of data grows 
2. Ignore smaller operations O(n + 1) -> O(n) 

Examples: 
O(1) Constant time - Random access of an element in array, inserting at beginning of linked list 
O(log n) Logarithmic time - binary search 
O(n) Linear time - Looping through elements in array, searching through linked list 
O(n log n) Quasilinear time - quicksort, mergesort, heapsort 
O(n^2) Quadratic time - insertion sort, selection sort, bubblesort, 
O(n!) Factorial time - Traversing salesman problem 

O(n) linear time: //if n = 1000000, 1000000 steps 
int sum = 0; 
for(int i = 0, i <= nl i++){
sum += 1; 
}

O(1) constant time //Always completed in 3 steps 
int sum = n * (n+1) / 2; 

To calculate time complexity: 

single loops: 
for(int i = 0; i < n; i+=2) //Linear O(n) 
for(itn i = 0; i < n; i *= 2) //Doubling O(log n)

Nested loops: Multiply the complexities 

Sequential operations: Add the complexities and take the largest one 
*/
