# Modular Arithmetic

###### An introduction to modular arithmetic

[Read Here](https://codeforces.com/blog/entry/72527)

```cpp
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

/* Calculate ( a*b ) %c */
ll mulmod(ll a, ll b, ll mod)
{
    if(b == 0)
        return 0;
    ll res = mulmod(a, b>>1, mod);
    res = (res<<1)%mod;
    if(b&1)
        return (res+a)%mod;
    else
        return res;
}

ll mulmod2(ll a, ll b, ll mod)
{
    ll ret = 0;

    while(b)
    {
        if(b&1)
            ret += a;
        
        a = a*2;
        b /= 2;
    }

    return ret;
}

/* Calculate ( a^b ) %c */
ll bigmod(ll a, ll p, ll MOD)
{
    if(p == 0)
        return 1%MOD;
    if(p == 1)
        return a%MOD;

    ll res = bigmod(a, p/2, MOD);
    res = (res*res)%MOD;
    if(p&1)
        return (a*res)%MOD;
    return res;
}

ll bigmod2(ll a, ll p, ll MOD)
{
    ll res = 1%MOD;
    while(p)
    {
        if(p&1)
            res = (res*a)%MOD;
        a = (a*a)%MOD;
        p /= 1;
    }
    return res;
}

/* Calcular a^(-1) for which a*a^(-1)(mod m)=1 */
ll inverseMod(ll a, ll m){
  int s,t;
  if(gcd(a,m,s,t)!=1)return -1;
  else return s;
}

ll inv_mod(ll a, ll m) {
    return bigmod(a, m-2, m);
}
```

Some Good Resources:

[Modular addition and subtraction](https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/modular-addition-and-subtraction)

[Modular arithmetic](https://brilliant.org/wiki/modular-arithmetic/)

[Modular Multiplicative Inverse](https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/)
