# Chicken McNugget Theorem

So the theorem essentially states that for an equation, ax+by=c, the maximum value of c for which this equation is invalid is given by a\*b-a-b
This theorem is especially helpful for certain cases. An example problem is GetACinOneGo of codechef. Here we have 2 numbers given a and b,
and we have to find a least value n such that all currency values *greater than or equal to n* can be made using any number of these coin denominations, that
being a and b. So our approach should be identifying the equations. First we realise that there is a hypothetical number, say m, above which all numbers can be
represented using a and b. In other words, n>=m. We find 2 equations:

ax1+by1=m ------ (i)

ax2+by2=m+1 ---- (ii)

If we subtract equation (ii) from (i)

a(x2-x1)+b(y2-y1)=(m+1)-m=1 => aX+bY=1, where X=x2-x1 and Y=y2-y1

Now as per Linear Diophantine equation, this can only have a solution if gcd(a,b)|1 so basically gcd(a,b)=1 is the only case where a solution exists. We can
set an if statement to check if the gcd(a,b)=1 and if it is, then we can use the chicken McNugget Theorem and hence a\*b-a-b=n-1, the maximum number for
which the solution doesn't exist and a\*b-a-b+1=n is the minimum number for which the solution exists.  
