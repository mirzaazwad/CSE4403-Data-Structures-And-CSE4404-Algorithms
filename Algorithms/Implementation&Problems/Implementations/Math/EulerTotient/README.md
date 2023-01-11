# Euler Totient Function

###### My implementation of the EulerTotient Function(φ)

```CPP
#include <bits/stdc++.h>
using namespace std;
#define N 100000 //Number to which the function needs to hold
int phi[N+1];

void eulerTotient(){
    for(int i=0;i<=N;i++)phi[i]=i;
    for(int i=2;i<=N;i++){//you can optimise sieve of eratosthenes with i*i<=N but don't do that for euler totient as it might lead to inaccurate precalculation
        if(phi[i]==i){
            for(int j=i+i;j<=N;j=j+i)phi[j]=(phi[j]*(i-1))/i;
            phi[i]=i-1;
        }
    }
}



int main()
{
    eulerTotient();
    int t;
    cin >> t;
    
    while(t--)//to check with various tests
    {
        int n;
        cin>>n;
        cout<<phi[n]<<endl;//output the phi value
    }
    return 0;
}
```

For larger numbers often it is not efficient to generate the eulerTotient value and store it in an array.
In that event, the best decision would be to
```cpp
ll phi(ll n)
{
    // Initialize result as n
    ll result = n;
  
    // Consider all prime factors of n
    // and subtract their multiples
    // from result
    for(ll p = 2; p * p <= n; ++p)
    {
         
        // Check if p is a prime factor.
        if (n % p == 0)
        {
             
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
                 
            result -= result / p;
        }
    }
  
    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
         
    return result;
}
```

###### Some Resources:

[GeeksForGeeks](https://www.geeksforgeeks.org/eulers-totient-function/)

The Time Complexity of Euler Totient Function is the same as sieve which is Nlog(log(N))
