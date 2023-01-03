#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;

int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

#define N 100000 //Number to which the function needs to hold

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

ll maxPrime(ll val){
    ll m=1;
    for(int i=0;i<15;i++){
        if(m*primes[i]>val)break;
        m*=primes[i];
    }
    return m;
}

int main()
{
    fastio;
    ll n;
    cin>>n;
    ll lim=maxPrime(n);
    ll num=lim-phi(lim);
    cout<<num/__gcd(num,lim)<<"/"<<lim/__gcd(num,lim)<<endl;

    return 0;
}