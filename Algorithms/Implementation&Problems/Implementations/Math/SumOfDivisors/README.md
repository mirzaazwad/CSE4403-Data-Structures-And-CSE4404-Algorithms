# Sum of Divisors SOD


My implementation of SOD is given below
```cpp
ll SOD(ll n){
    ll c,ret=1;
    for(int j=0;primeList[j]<=n;j++){
        ll tmp=n;
        for(c=0;tmp%primeList[j]==0;c++){
            tmp/=primeList[j];
        }
        ll val=(ll)pow(primeList[j],c+1);
        val--;
        val/=(primeList[j]-1);
        if(c>0)ret*=val;
    }
    return ret;
}
```
