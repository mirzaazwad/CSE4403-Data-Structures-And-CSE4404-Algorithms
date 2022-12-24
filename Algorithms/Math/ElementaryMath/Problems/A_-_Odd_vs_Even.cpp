/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"

vector<int>primeList;

void sieve(){
    int n=1000009;
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



ll oddNOD(ll n)
{
    ll i, c, ret = 1;

    for(i = 1; primeList[i]*primeList[i] <= n; i++)
    {
        for(c = 0; n % primeList[i] == 0; c++)
            n /= primeList[i];
        ret *= (c+1);
    }

    if(n > 1)
        ret = ret << 1;

    return ret;
} 
/*
Explanation: 
When N=2^d×a (a: even), the set of the divisors of N is:

{2^i×j∣​0≤i≤d,j is a divisor of a}

Thus, if
N has m odd divisors, it has dm even divisors.

Therefore, the answer is:

Even, if N is divisible by 4;
Same, if N is divisible by 2 but not by 4;
Odd, if N is not divisible by 2.
*/
void solve(){
    long long N;
    cin>>N;
    if(N%2!=0){
        cout<<"Odd"<<endl;
    }
    else{
        int count=0;
        int i;
        while(!(N%2)){
            N/=2;
            count++;
        }
        if(count==1){
            cout<<"Same"<<endl;
        }
        else{
            cout<<"Even"<<endl;
        }

    }

}
int main()
{
    fastio;
    sieve();
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}