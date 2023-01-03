# GCD(Greatest Common Divisor)
This is a fairly new, addition to the tutorials
So regarding number theory, we first start of with the idea of gcd(greatest common divisor), also known as hcf(highest common factor)
This is a brief yet complete introduction to the properties of gcd. [Click Here](https://people.math.sc.edu/howard/Classes/580f/hw4.pdf)
For more details about gcd, and a quite okayish overview, we know the common place to look into [Click Here, PS It's Wikipedia](https://en.wikipedia.org/wiki/Greatest_common_divisor)
After going through the first link, I suppost one can perceive how the euclidean gcd is determined. To represent this algorithmically:
```CPP
#include<iostream>
using namespace std;

int gcd(int a,int b){
            if(b==0)return a;
            else return gcd(b,a%b);
            }
int main(){
         cout<<gcd(3,6)<<endl;
	 return 0;
         }
```
This is the C++ code to determine gcd for 3,6. The output would be 3. 
Below is the example python code implementation for a gcd function:
```Python3
def gcd(a,b):
	if(b==0):
		return a
	else:
		return gcd(b,a%b)
```

GCD iterative implementation in python:

```Python3
def gcd(a,b):
    x=a
    y=b
    while(y!=0):
        r=x%y
        x=y
        y=r
    return x
```


A good introductory problem to gcd with medium difficulty is discussed below, 

[Codeforces 1617B](https://codeforces.com/contest/1617/problem/B)

This is by far the most efficient approach to finding the gcd of 2 numbers and is known as the Euclidean Algorithm. And it works as the base for the extended euclidean algorithm.


## Most Efficient Way To Find Factors

```CPP
#include <iostream>
#include <vector>
// Switch DEBUG to false if you don't want to print the factors
#define DEBUG true

using namespace std;

vector <int> factors(int x) {
    // We will store all factors in `result`
    vector <int> result;
    int i = 1;
    // This will loop from 1 to int(sqrt(x))
    while(i*i <= x) {
        // Check if i divides x without leaving a remainder
        if(x % i == 0) {
            result.push_back(i);
            // Handle the case explained in the 4th
            if(x/i != i) {
                result.push_back(x/i);
            }
        }
        i++;
    }
    // Print in case of debug mode
    if(DEBUG) {
        for(int i=0; i<result.size(); i++) {
            cout << result[i] << ' ';
        }
        cout << endl;
    }
    // Return the list of factors of x
    return result;
}

int main() {
    factors(1);
    // Output: 1
    factors(4);
    // Output: 1 4 2 
    factors(10);
    // Output: 1 10 2 5 
    factors(12); 
    // Output: 1 12 2 6 3 4 
    factors(16);
    // Output: 1 16 2 8 4 
    return 0;
}

```
