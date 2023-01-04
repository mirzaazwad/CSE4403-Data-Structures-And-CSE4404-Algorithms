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

![Tail Recursion Image](https://github.com/mirzaazwad/Data-Structures-And-Algorithms/blob/main/Algorithms/ImplementationsAndPracticeProblems/RecursiveFunctions/Tutorial/TailRecursion.png)

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

![Head Recursion Image](https://github.com/mirzaazwad/Data-Structures-And-Algorithms/blob/main/Algorithms/ImplementationsAndPracticeProblems/RecursiveFunctions/Tutorial/HeadRecursion.png)

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
We can do the same for a backward loop.
For a backward loop, the key difference lies in the fact that the loop travels backwards or has a decrement for i and the i starts at n-1 and proceeds towards 0. The code is given below:
```cpp
for(int i = n-1; i >= 0; i -= 1) {
    // do whatever needed
}
```

The equivalent recursion can be
```cpp
void ROF(int i, int n) {
    if(i==n) return; // terminates
    ROF(i+1, n); // keep going to the last
    // do whatever needed when returning from prev steps
}
```
Now you may wonder that how does this make sense, but the idea is making use of the descending phase of recursion similar to how we use the descending phase of recursion in a head recursion. The statements being after the call statement means that the execution of these statements takes place at the time of backtracking or at returning time. Just think of its execution cycle, just after entering the function, it is calling itself again incrementing the value of i, and the execution routine that you have written under the function call, was paused there. From the new function it enters, it works the same way, call itself again before executing anything...Thus when you have reached the limiting condition, or the base condition, then the function stops recursion and starts returning, and the whole process can be shown as below...let n=5, and we want to print 5 4 3 2 1...code for this might be:

```cpp
void function(int i, int n) {
    if(i<=n) {
        function(i+1, n);
        printf("%d ", i);
    }
}
```
Explanation might look something like this
![image](https://user-images.githubusercontent.com/50703605/210554644-3ea61445-34d5-4c47-b4d8-ff286f15af0a.png)
Left side number shows the execution steps, so from the above program, we get, 5 4 3 2 1. So indeed it ran on reverse direction.

### How Recursion uses stack

The first idea is that each time a function is called an activation record is created for the function which occupies the stack memory. As the activation records are created they pile up or form a stack especially for recursive calls. Let's consider the input for the head recursion example.
![IMG_20230104_184042](https://user-images.githubusercontent.com/50703605/210557393-90b835e7-6831-400f-b62e-c86a9af24743.jpg)
The activation records are popped when the base condition is met and it starts backtracking one by one. The size of the stack is the number of activation records created during the progress of the recursion. In this case the size of the stack is considered to be 4 as we exclude the activation record for main when calculating the size of the stack for a specific recursive function. The size of the memory consumed is this m x (n+1) where m is the memory for each call and n+1 is the number of calls of the function, func(n). If the toal calls is n+1 then the memory complexity is O(n) as m is a constant. Thus recursive functions appear to be more memory consuming than iterative loops which essentially has a memory complexity of O(1). 

### General Precaution for using recursion in competitive programming

Be careful while using recursions. From a programming contest aspects, recursions are always best to avoid. As you've seen above, most recursions can be done using loops somehow. Recursions have a great deal of drawbacks and it most of the time extends the execution time of your program. Though recursions are very very easy to understand and they are like the first idea in many problems that pops out in mind first... they still bear the risks of exceeding memory and time limits.

Generally, in loops, all the variables are loaded at the same time which causes it a very low memory consumption and faster access to the instructions. But whenever we use recursions, each function is allotted a space at the moment it is called which requires much more time and all the internal piece of codes stored again which keeps the memory consumption rising up. As your compiler allows you a specific amount of memory (generally 32 MB) to use, you may overrun the stack limit by excessive recursive calls which causes a Stack Overflow error (a Runtime Error).

### Introduction to Dynamic Programming

If the recursion tree has some overlapping branches, most of the times, what we do, is to store already computed values, so, when we meet any function which was called before, we may stop branching again and use previously computed values, which is a common technique knows as Dynamic Programming (DP), we will talk about that later as that is pretty advanced. A better example regarding fibonacci would be shown later.

### Time Complexity in Recursion

For the basic idea of time complexity we assume every statement takes 1 unit of time for execution. So if we observe the following recursive statement.
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
which gives this tracing tree for input 3:
![Head Recursion Image](https://github.com/mirzaazwad/Data-Structures-And-Algorithms/blob/main/Algorithms/ImplementationsAndPracticeProblems/RecursiveFunctions/Tutorial/HeadRecursion.png)

essentially every level of the tree takes 1 unit of time for execution so the overall Time complexity, T<sub>3</sub>=3 for n=3 and for n, T<sub>n</sub>=m
which means that the complexity can be seen as O(n).

The typical way to determine time complexity is not necessarily on a level basis. We come across other means such as **Master's Theorem** and determining mathematically using recurrence relation. Let's first discuss **determining time complexity with recurrence relation**.

Observe the following function:

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
T(n)=T(n-1)+2 when n>0
T(n)=1 when n=0
 can be the recurrence relation
 
 The steps to determine the time complexity can be as follows:
- rewrite the constant values as 1
- Go to next n, T(n-1)=T(n-2)+1
- Substitute the previous step in the first step
- 
T(n)=T(n-2)+1+1=T(n-2)+2

T(n)=T(n-3)+1+2=T(n-3)+3

Hence, T(n)=T(n-k)+k
 
So when you don't know the answer for the bigger expression but you know the answer for the smaller expression so you keep breaking the problem into smaller ones and sole it. Here you try to reach 0 so n-k=0 => n=k

T(n)=T(n-n)+n

T(n)=T(0)+n

T(n)=1+n

which can be written as O(n).
### References
- [Abdul Bari Udemy Data Structures Recursion](https://www.udemy.com/course/datastructurescncpp/)
- [Abdul Bari Youtube Algorithms](https://youtube.com/playlist?list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O)
- [Attacking Recursions](https://zobayer.blogspot.com/2009/12/cse-102-attacking-recursion.html)
