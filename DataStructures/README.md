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

![Array Image](https://media.geeksforgeeks.org/wp-content/uploads/C-Arrays.jpg)

We cannot insert 35 after 46 which is the last element, which is a **drawback** of contiguous memory-based data structures that is they have static allocation of memory.

**Advantage of Contiguous Memory** lies in the fact that we can store a lot of elements sequentially making it easier to search and index. The searching can be done on the basis of 
data type by shifting positions in an indexed manner via pointer, telling it to move exactly the same number of blocks as the size of that data type in each next transition. Can give constant access time by the use of indexing.

**Disadvantage of Contiguous Memory** is that we usually can't add new elements or search for a group of elements that aren't having the same data type.

To overcome the Disadvantage of Contiguous Memory we implement something called a **Linked List**.

A Linked List has one major **drawback**, although we can add more elements which is a **plus** but we cannot index a linked list, what ends up happening
is that the linked list has to be traversed from head to tail and any particular node cannot be accessed directly.

There are 3 types of linked list commonly used:

1) Singly
2) Doubly
3) Circular

Circular is by far the least used [Uses Of Circular Linked List](https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-circular-linked-list/#:~:text=Circular%20Linked%20Lists%20can%20be,such%20as%20a%20Fibonacci%20Heap.)


**Storing Matrices**

Matrices and 2D structures can be stored in row major and column major forms which is essentially a form of indexed storage. But to better understand it,
its easy to relate it to a linked list storing the pointers to the base address of different array elements. If it stores the base address of the rows of a matrix its row-majored.
If it stores the base address of the columns of the matrix is column majored

[For a detailed read](https://en.wikipedia.org/wiki/Row-_and_column-major_order)

Such row majors or column majors can be used for graph representation using adjacency matrices.

**Arrays**

Traversing through the array with constant access time. 

```
For 1D arrays
arr[i] = arr[0] + elem_size*(i-0)
arr[0] here indicates the base address of the array or the array address, i-firstIndex where firstIndex is the starting index of the array

For 2D arrays

Row-Major: arr[i,j] = array_address + elem_size*((i-firstIndex)*row_size+(j-firstIndex))

Column-Major: arr[i,j] = array_address + elem_size*((i-firstIndex)+(j-firstIndex)*column_size)
```


