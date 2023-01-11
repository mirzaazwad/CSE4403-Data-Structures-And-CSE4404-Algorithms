#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

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

void solve(){
    long long W;
    cin>>W;
    long long M,N;
    for(long long i=1;1LL<<i<=W;i++){
        long long val=1LL<<i;
        if(((W/val)&1)){
            N=W/val;
            M=val;
            break;
        }
    }
    if(N*M==W)cout<<N<<" "<<M<<endl;
    else cout<<"Impossible"<<endl;
}

int main()
{
    fastio;
    sieve();
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
