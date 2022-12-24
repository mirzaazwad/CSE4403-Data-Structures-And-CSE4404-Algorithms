#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
#define MAXN 1000009
#define ll long long

ll phi[MAXN+5];

vector<unsigned ll>primeList;

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
            primeList.push_back((unsigned ll)i);//pushing all the prime numbers into a list on the basis of the colouring of the list. True means prime and false means not prime
        }
    }
}

void eulerTotient(){
    for(int i=0;i<=MAXN;i++)phi[i]=i;
    for(int i=2;i<=MAXN;i++){
        if(phi[i]==i){
            for(int j=i;j<=MAXN;j+=i)phi[j]*=(i-1)/i;
            phi[i]=i-1;
        }
    }
}

void solve(){
    ll N;
    cin>>N;
    ll i=1;
    for(auto u:primeList){
        if(i*u>=N){
            break;
        }
        else{
            i=i*u;
        }
    }
    cout<<i<<endl;
}

int main()
{
    fastio;
    sieve(MAXN);
    eulerTotient();
    int t;
    cin >> t;
    
    while(t--)
    {
       solve();
    }
    return 0;
}
