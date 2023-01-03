# Artithmetic Progression

[Read This Article](https://byjus.com/maths/arithmetic-progression/)

# Geometric Progression

[Read This Article](https://byjus.com/maths/geometric-progression/)

# Finding the Sum of n, n<sup>2</sup>, n<sup>3</sup> and n<sup>x</sup> ?

[A Brilliant Article](https://brilliant.org/wiki/sum-of-n-n2-or-n3/)

[Cue Math](https://www.cuemath.com/summation-formulas/)

Read these articles to understand the concepts more clearly.



# How do you find the nth term formula for a sequence with non-constant difference?

Take the sequence;

9,    12,    19,    30,    ...

###### (1) The first step is always to look at difference between the terms;
```

9,    12,    19,    30,    ...

   +3,    +7,    +11,   ...         
   
        +4,    +4,    ...                      
```
We can see the difference is not constant, 

###### (2)  so we looked at the change in the difference each term.

This gives a constant change in the difference of an extra +4 each term. The fact that we needed to take 2 turns to find the constant difference means we are dealing with a quadratic sequence.

###### (3) Furthermore, because the difference is +4, we are dealing with a 2n<sup>2</sup> sequence.

If the change in the difference is (a) then the nth term follows a (1/2a)n<sup>2</sup> pattern.

###### (4) Now we can rewrite the sequence as follows;

```

         n       n2      2n2
9       1       1         2

12     2       4         8             

19     3       9        18

30     4      16       32

```

###### (5) We need to find the difference between the sequence and 2n<sup>2</sup>.

```

           2n2        d

9          2          -7                

12        8          -4                   

19       18         -1

30       32        +2

```

###### (6) The difference here will either be a constant number, in which case the nth term is (1/2a)n<sup>2</sup> +d. Or like this case, will itself follow a linear sequence with constant difference, which we should know how to solve.

```

 1      2      3       4
 
-7,    -4,    -1,    +2

    +3     +3    +3
```

This gives 3n - 10. Therefore the whole formula for the nth term is;

###### (7) 2n<sup>2</sup> + 3n - 10
