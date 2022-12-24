# C++ Tricks and why it is important

The most popular language for competitive programming is C++. it is easiest to chose this language for competitive programming.
I personally prefer using vscode as an IDE. Below I would give a borderline idea of how you could setup vscode for optimised coding experience in your online contests.
In onsite constests you wouldn't get many of these features so beware.

[VSCODE setup for competitive programming](https://www.geeksforgeeks.org/how-to-setup-competitive-programming-in-visual-studio-code-for-c/)

Now when it comes to header I prefer ``` bits/stdc++.h ```

This includes all the necessary files and file headers for Competitive Programmming(at least most of them). Then we move on to the next step. We learn about snippets and their importance.

## Fast Input C/C++

```cpp
template <class T> void fastInput(T &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {
        
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}
```


###### Using Lambda Functions in C++

[First Article to Read](https://www.geeksforgeeks.org/lambda-expression-in-c/)

[Second Article to Read](https://www.geeksforgeeks.org/generalized-lambda-expressions-c14/?ref=rp)

[Lambda Expressions vs Function Pointers](https://www.geeksforgeeks.org/lambda-expressions-vs-function-pointers/?ref=rp)
