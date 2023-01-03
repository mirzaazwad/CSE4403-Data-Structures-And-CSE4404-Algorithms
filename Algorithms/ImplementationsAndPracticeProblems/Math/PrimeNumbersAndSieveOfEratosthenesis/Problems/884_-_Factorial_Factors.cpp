#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define N 1000001
#define ll long long
using namespace std;

bool isPrime[N+1];
vector<ll>primeList;
ll arr[N+1];

void sieve(){
    int n=N;
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


ll Factors(ll n)
{
    ll i, c=0;

    for(i = 0; i*i <= n; i++)
    {
        while(n%primeList[i]==0){
            n/=primeList[i];
            c++;
        }
    }
    if(n>1)c++;
    return c;
}

int main()
{
    fastio;
    sieve();
    
    arr[1]=0;
    for(int i=2;i<=N;i++){
        arr[i]=arr[i-1]+Factors(i);
    }
    int n;
    while(cin>>n){
        cout<<arr[n]<<endl;
    }

    return 0;
}