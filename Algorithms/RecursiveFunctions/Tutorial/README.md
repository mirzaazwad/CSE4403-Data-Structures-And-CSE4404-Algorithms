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

The tracing tree here shows every step of recursion. As you can see the input statement is arranged in order in every level of the tree. You can imagine the outputs similar to a queue. And the output is given before every recursive call. And the idea given here is that the recursive call takes place near the end which gives it its characteristic name, **tail recursion** as the call is placed near the tail or the end of the code. If you don't understand it's okay it would become clearer when we view the memory stack interpretation of recursion. But remember this after the recursive call meets the base condition, it backtracks, or control goes back to previous call. So when func(0) is met, it goes back to func(1). This idea would be useful when understanding head recursion. 
