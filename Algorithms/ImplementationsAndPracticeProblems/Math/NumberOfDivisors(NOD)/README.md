# Number of Divisors

[Click here for detailed description](https://cp-algorithms.com/algebra/divisors.html#sum-of-divisors)

The basic implementation is given below

```cpp

ll NOD(ll n)
{
    ll i, c, ret = 1;

    for(i = 0; primes[i]*primes[i] <= n; i++)
    {
        for(c = 0; n % primes[i] == 0; c++)
            n /= primes[i];
        ret *= (c+1);
    }

    if(n > 1)
        ret = ret << 1;

    return ret;
}
```
