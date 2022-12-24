# Segmented Sieve

Resources:

[CP Algorithms](https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/tutorial/)

[Segmented Sieve Codeforces](https://codeforces.com/blog/entry/61430)

[A Github Blog on Segmented Sieve](https://github.com/kimwalisch/primesieve/wiki/Segmented-sieve-of-Eratosthenes)

Segmented Sieve essentially helps solve problems for slightly larger values of prime numbers as long as the range is within 10^6.

```cpp
unordered_set<int>s;
 
 void segmentedSieve(int l,int r){
    bool isPrime[r - l + 1];
    for(int i=0;i<r-l+1;i++)isPrime[i] = true;
    for (long long i = 2; i * i <= r; ++i) {
        for (long long j = max(i * i, (l + (i - 1)) / i  * i); j <= r; j += i) {
            isPrime[j - l] = false;
        }
    }
    for (long long i = max(l, 2); i <= r; ++i) {
        if (isPrime[i - l]) {
            s.insert(i);
        }
    }
 }
```

My implementation of segmented sieve, the unordered set helps store the primes in a way such that it can be retrieved at O(1).
