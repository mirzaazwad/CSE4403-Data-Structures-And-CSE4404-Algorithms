# Recursion

### Recursion and its types

A **Recursive Function** is one that calls itself and it should have a base condition that helps terminate the recursive calls. 

A Recursive function can generally be of the following types:
- tail recursion
- head recursion
- tree recursion
- indirect recursion
- nested recursion

We will discuss the other types of recursion later, first let's start with tail and head recursion.

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
### Introduction to Divide and Conquer

For recursive problems first focus on the input and the output. This is the first step or you may call it the basis step upon which we build up the solution to come.
Suppose we know that this function takes an input and spits out an output. But to find this output we need a series of subproblems being solved. The subproblems may be solved by calling the same function again with a different input. So the function basically says, I cannot solve the problem now but if you give me this result I can solve it, so you are basically like, okay then can you find the result you need if you call yourself using a different input, if yes, perform the calling until you can come up with a solution. So this becomes the essence of what we call **Divide and Conquer** in the computer science realm.

### Understanding the Factorial Function

Let's observe the simplest of all recursive statements, **FACTORIAL**

```cpp
int factorial(int n)
{
  //the first if statement gives the base condition which is the basis step, I know this so I don't need the function to go any further
  if(n<=1)return 1;
  else return n*factorial(n-1);
  //the else statement provides the path the function has to go by so that it reaches the base condition, if any other input is given to factorial, don't bother
  //just keep reusing the factorial function.
}
```

So say that you wanted factorial(3), the pathway would go as follows factorial(3)->3\*factorial(2)->2\*factorial(1)->1 what happens then is that it backtracks, factorial(1) is like okay fine, I have the solution factorial(2) asked for and so factorial(2) is replaced with 2\*1 and then factorial(2) is like okay I have the solution that factorial(3) asked for and so factorial 3 is replaced by 3\*(2\*1) thus giving us the answer 3\*2\*1=6

First distinction we need to consider is that a loop only has an ascending phase and not a descending phase unlike recursion although loops and recursions are both iterative or repetitive statements. Its ok to not understand right now, let's see some details to clarify the concepts.


### Recursion vs Loop

The key distinguishing factor between recursion and loops is that loops only have ascending phase while recursions have ascending and descending phases although both can be used as repeating/iterative structures.

But whatever you can do with loop, you can do with recursion. In this section I shall give a brief overview of the simple technique to convert the loop statements into recursion. See the following example for **forward loop**.

```cpp
for(int i = 0; i < n; i++) {
    // do whatever needed
}
```

To convert this to recursion the basic approach is:
```cpp
void FOR(int i, int n) {
    if(i==n) return; // terminates
    // do whatever needed
    FOR(i+1, n); // go to next step
}
```
<font face="courier new" size="3"><br><span style="color:#101000">01|call function<sub>1</sub> with i=1<br><span style="color:#FF00FF">02|    call function<sub>2</sub> with i=2<br><span style="color:#3399FF">03|        call function<sub>3</sub> with i=3<br><span style="color:#0000FF">04|            call function<sub>4</sub> with i=4<br><span style="color:#336600">05|                call function<sub>5</sub> with i=5<br><span style="color:#FF0000">06|                    call function<sub>6</sub> with i=6<br>07|                        i breaks condition, no more calls<br>08|                    return to function<sub>5</sub></span><br>09|                    print 5<br>10|                return to function<sub>4</sub></span><br>11|                print 4<br>12|            return to function<sub>3</sub></span><br>13|            print 3<br>14|        return to function<sub>2</sub></span><br>15|        print 2<br>16|    return to function<sub>1</sub></span><br>17|    print 1<br>18|return to main, done!</span></font>

