# Recursion

### Recursion and its types

A **Recursive Function** is one that calls itself and it should have a base condition that helps terminate the recursive calls. 

A Recursive function can generally be of two types:
- tail recursion
- head recursion

We will discuss the types of recursion later

First let's discuss the tracing of a recursion tree. The tracing of a recursion tree allows one to view the different pathways the recursion tree takes. 
To give some intuition we will soon see the two different types of recursions mentioned being traced. 

### Understanding the difference of head and tail recursion using an analogy



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

The tracing tree here shows every step of recursion. As you can see the input statement is arranged in order in every level of the tree. You can imagine the outputs similar to a queue. And the output is given before every recursive call. And the idea given here is that the recursive call takes place near the end which gives it its characteristic name, **tail recursion** as the call is placed near the tail or the end of the code. If you don't understand it's okay it would become clearer when we view the memory stack interpretation of recursion. But remember this after the recursive call meets the base condition, it backtracks, or control goes back to previous call. So when func(0) is met, it goes back to func(1). This idea would be useful when understanding **head recursion**. 

### Head Recursion

```cpp
void func(int n)
{
  if(n>0)
  {
    func(n-1);
    printf("%d",n);
   }
   
}
```

Observe the different with tail recursion, the difference lies in the fact that the positions of the call statement and the print statements have been swapped. Let's look at the tracing tree for the head recursion.

![Head Recursion Image](https://github.com/mirzaazwad/Data-Structures-And-Algorithms/blob/main/Algorithms/RecursiveFunctions/Tutorial/HeadRecursion.png)

Now let's look at the tree from a different angle, essentially the tree works such that every time the recursive function is called it goes deeper into the leftmost branch of the tree, after the calls for that branch finally meets the base condition, it backtracks and moves onto the next branch. Observe in the aforementioned head recursion tracing tree. The first call takes func(3) and then it moves onto func(2) -> func(1) -> func(0) when it meets func(0) it meets the base condition being that n is no longer grreater than 0, so it returns call to func(1) which continues to check if it has any other children besides func(0), the only other child is a print function being printf("%d",1) so it prints the number and then func(1)'s task is complete, it then goes to its parent func(2), func(2) checks its remaining children, upon all children's task being completed, func(2) goes to its parent func(3) , so on and so forth.

### Understanding the different types with analogies

First imagine 3 connected rooms, essentially to go to the third room you have to enter the first room and then through the first room, you enter the second room, and then through the second room, you enter the third room. 

We are going to perform two tasks:
- Switch on the Bulb
- Move between rooms.
Our goal is to turn on all 3 lights.

Now if we first turn on a light and then go to the next room, its basically tail recursion.
If we first go to the third room and on our way back we turn on the lights one by one then it is head recursion.

You can also imagine the head recursion as a stack which pops one by one when the stack is full and the tail recursion as a stack which first pushes then pops and so on.

### Generalising Recursion

```cpp
void func(int n)
{
  if(n>0)
  {
    //This area before the recursive call is called the ascending phase of recursion, calling time
    func(n-1)*2;
    //This area after the recursive call is called the descending phase of recursion, returning time
  }
}
```
### Recursion vs Loop



