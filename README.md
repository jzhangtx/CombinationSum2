Combination Sum 2


Given an array of integers A and a target value val, find all unique combinations of integers from A where their sum is equal to val.

Note: Each integer in the array may be used once in the combination.

Example
A: [10, 1, 2, 7, 6, 1, 5]
val: 8
Combinations: [
  [1, 1, 6],
  [1, 2, 5],
  [1, 7],
  [2, 6]
]
Testing
Input Format
The first line contains an integer ‘T’, denoting the number of test cases.

For each test case the input has three lines:

An integer ‘n’ denoting the length of the array A.
n space-separated unique integers denoting the elements of the array A.
An integer ‘val’ denoting the target value.
Output Format
For each test case, the output has the following lines:

The first line contains an integer ‘m’ denoting the total no of distinct combinations.
The next m line contains space-separated integers denoting elements in that particular combination.
Sample Input
3
7
10 1 2 7 6 1 5
8
4
1 2 3 2
4
5
1 2 3 4 5
5
Expected Output
4
1 1 6
1 2 5
1 7
2 6
2
1 3
2 2
3
1 4
2 3
5