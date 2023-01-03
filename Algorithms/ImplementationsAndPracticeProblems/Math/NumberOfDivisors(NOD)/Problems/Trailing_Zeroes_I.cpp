#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;

bool isPrime[1000009];
vector<long long>primes;

void sieve(int n){
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
            primes.push_back(i);//pushing all the prime numbers into a list on the basis of the colouring of the list. True means prime and false means not prime
        }
    }
}


ll NOD(ll n)
{
    ll i;
    ll ret=1;
    for(i = 0; primes[i]*primes[i] <= n; i++)
    {
        ll c=0;
        while(!(n%primes[i])){
            n/=primes[i];
            c++;
        }
        
        ret *= (c+1);
    }

    if(n > 1)
        ret = ret << 1;

    return ret;
}

void solve(){
    ll N;
    cin>>N;
    cout<<NOD(N)-1<<endl;
}

int main()
{
    fastio;
    sieve(1000009);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
       cout<<"Case "<<i<<": ";
       solve();
    }
    return 0;
}