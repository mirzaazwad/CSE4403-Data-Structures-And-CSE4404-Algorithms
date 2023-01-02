# Recursion

### Recursion and its types

A **Recursive Function** is one that calls itself and it should have a base condition that helps terminate the recursive calls. 

A Recursive function can generally be of two types:
- tail recursion
- head recursion

We will discuss the types of recursion later

First let's discuss the tracing of a recursion tree. The tracing of a recursion tree allows one to view the different pathways the recursion tree takes. 
To give some intuition let's see the two different types of recursions mentioned being traced. 

### Tail Recursion

```cpp
void func(int n)
{
  if(n>0)
  {
    printf("%d",n);
    func(n-1);
   }
   
}
```

The tracing tree for the recursion given above:

![Tail Recursion Image](https://github.com/mirzaazwad/Data-Structures-And-Algorithms/blob/main/Algorithms/RecursiveFunctions/Tutorial/TailRecursion.png)

The tracing tree here shows every step of recursion.
