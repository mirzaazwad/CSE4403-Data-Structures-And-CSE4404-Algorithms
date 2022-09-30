# Data Structures

**Data Structures** are ways to store and organize data in a computer so that it can be used efficiently.

There are two main ideas behind a data structures course:

1) Abstract Data Types - Logical Understanding
2) Implementation of different data types

Note: First and foremost learn how to think on pen and paper

There are 3 main types of memory allocation:

1) Contagious - data is stored in sequential memory blocks -> usually stored in stack memory
2) Linked - data is stored scattered throughout the memory, linked by the use of pointers -> usually stored in heap memory
3) Indexed- which is of further 2 types:
  1) Row-major
  2) Column-major

Most contagious memory-based data structures are **static data structues** in other words they can hold a fixed number of elements and thus cannot be resized.

so say we have the array given below:

![Array Image](https://cdn.programiz.com/sites/tutorial2program/files/c-arrays.jpg](https://media.geeksforgeeks.org/wp-content/uploads/C-Arrays.jpg)

We cannot insert 35 after 46 which is the last element, which is a drawback of contiguous memory-based data structures that is they have static allocation of memory.

Advantage of Contiguous Memory lies in the fact that we can store a lot of elements sequentially making it easier to search and index. The searching can be done on the basis of 
data type by shifting positions in an indexed manner via pointer, telling it to move exactly the same number of blocks as the size of that data type in each next transition.


