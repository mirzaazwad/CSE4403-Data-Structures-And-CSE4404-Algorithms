# Prime Number Determination

Mathematically, one can define a prime number as one that is not divisible by any number other than 1 and itself. So one can imagine a brute force approach to this problem
quite easily but then again that isn't the most efficient approach to solving this problem. Below we discuss the brute force approach and how it becomes something that
may be the cause of the TLE's you may be getting in those prime number problems.  

```CPP

#include<iostream>
using namespace std;

bool isPrime(int n){
	for(int i=2;i<n;i++){
		if(n%i==0)return false;
	}
	return true;
}
int main(){
         cout<<isPrime(5)<<endl;
	 return 0;
         }
```

This approach is basically O(N) and if you wanted to make a list of prime numbers with this approach usinng a nested loop, it basically goes upto O(N<sup>2</sup>) which is not very efficient. Time is the issue here.

So basically this approach is a bit like if there is a number i that can divide n within the range 1<i<n then this is not prime, but this approach is very redundant and unnecessary and can lead one to a TLE or CPU Limit Exceeded. For this we have the sieve of Eratosthenes. The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million and such. [Again a wikipedia link](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
For a detailed overview, please visit geeks for geeks, basically just [Click HERE!!!](https://www.geeksforgeeks.org/sieve-of-eratosthenes/).
Furthermore, I would discuss Sieve in greater details in the section below.


```CPP

#include<iostream>
using namespace std;

bool isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}
int main(){
         cout<<isPrime(5)<<endl;
	 return 0;
         }
```
A brief implementation of an idea. Make sure i starts from 2, it is a common mistake.
It is not sieve but more efficient that the brute force approach.
It is more like a relatively efficient approach with your complexity reduced to O(&radic;(N)) and for a list it is still efficient and becomes O(N).


```Python3
def isPrime(a):
	i=2
	while(i*i<=a):
		if(a%i==0):
			return False;
		i+=1
	return True
```

Also this is the python code for the same algorithm.

###### But why do we check till the squres only?

Let's take a number n, if n is not a prime  number, n can be factored into:

> n = a x b

Now a and b can't be both greater than the square root of n, since then the product a * b would be greater than &radic;(n) * &radic;(n) = n. So in any factorization of n, at least one of the factors must be smaller than the square root of n, and if we can't find any factors less than or equal to the square root, n must be a prime.


## Sieve of Eratosthenes

Let's assume a number sequence, say 1, 2, 3, 4, 5, 6.......n. 

In order to find the prime numbers in this sequence we do the following steps:

1) First cancel out all even numbers
2) Then cancel out all squares of odd numbers

A very brief way to approach the sieve algortihm. 

```CPP
// C++ program to print all primes
// smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
	// Create a boolean array
	// "prime[0..n]" and initialize
	// all entries it as true.
	// A value in prime[i] will
	// finally be false if i is
	// Not a prime, else true.
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	prime[0]=false;
	prime[1]=false;
	for (int p = 2; p * p <= n; p++)
	{
		// If prime[p] is not changed,
		// then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples
			// of p greater than or
			// equal to the square of it
			// numbers which are multiple
			// of p and are less than p^2
			// are already been marked.
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Print all prime numbers
	for (int p = 2; p <= n; p++)
		if (prime[p])
			cout << p << " ";
}

// Driver Code
int main()
{
	int n = 30;
	cout << "Following are the prime numbers smaller "<< " than or equal to " << n << endl;
	SieveOfEratosthenes(n);
	return 0;
}

```
So time for some explanation, in the above methods to determine prime numbers, or making a prime number list we uncovered that checking till
> i\*i<=n

Now in this method we first set all the numbers to be true using a memset, and then we check from 2 onwards, but why 2? since 2 is the first prime number it is pointless to start from 1. After we start checking from 2, we check whether the number is a prime or is marked prime as initially we marked all the numbers to be prime using the flag and applying memset on it, and then we clarified that 0 and 1 are not prime. Then if the number is a prime, we mark all its multiples using a nested loop from i\*i to N and incrememting the number by itself as in if p is the prime number, then we increment by p or in other words **i+=p**. This marks all the multiples of the prime numbers as not prime as a prime number can have no factor other than itself and 1. In this method we can mark all numbers as  either prime or not prime. This is pretty efficient. Another approach is:

```CPP
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

vector<int>primeList;

void sieve(int n){
    bool isPrime[n+1];
    memset(isPrime, false, sizeof(isPrime));
    isPrime[2]=true;//mark 2 as prime

    for(int i=3;i<=n;i+=2)isPrime[i]=true;//mark 3 and all odd numbers from 3 onwards as prime excluding the even numbers in the process
    for(int i=3;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=2*i)isPrime[j]=false;//this marks all odd multiples as not prime, since the even multiples are already marked as not prime, its not needed
	    //to repeat the process, thus making the algorithm more efficient.
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            primeList.push_back(i);//pushing all the prime numbers into a list on the basis of the colouring of the list. True means prime and false means not prime
        }
    }
}

int main()
{
    fastio;
    int n;
    cin>>n;
    sieve(n);
    for(int i=0;i<primeList.size();i++){
        cout<<primeList[i]<<" ";
    }
    cout<<endl;
    return 0;
}
```
This is another approach to create and print a list of prime numbers.

The time complexity for the sieve algorithm is O(Nlog(log(N))).

More on Sieve [A Codeforces Blog On It](https://codeforces.com/blog/entry/54090)

[Another Codeforces Blog, basically explains how sieve can take O(N) as well?](https://codeforces.com/blog/entry/22229)

[Some TidBits to know, check out the comments section](https://codeforces.com/blog/entry/61700)

[An Overview of Sieve and Practice Problems](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html)
