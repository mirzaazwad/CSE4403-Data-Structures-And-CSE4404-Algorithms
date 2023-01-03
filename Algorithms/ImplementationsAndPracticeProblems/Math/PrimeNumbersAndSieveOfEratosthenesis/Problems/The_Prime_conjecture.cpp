/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
*/
#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"
 
 const int N=1e7;

bool isPrime[N+5];
vector<ll>primes;
 
 void sieve(){
    isPrime[2]=true;
    primes.push_back(2);
    for(int i=3;i<=N;i+=2)isPrime[i]=true;
    for(int i=3;i*i<=N;i+=2){
        if(isPrime[i]){
            for(int j=i+i;j<=N;j+=i)isPrime[j]=false;
        }
    }
    for(int i=3;i<=N;i+=2){
        if(isPrime[i])primes.push_back(i);
    }
 }

 bool primecheck(ll value, ll& pr){
    bool found=false;
    for(auto u:primes){
        if(value%u==0){
            pr=u;
            found=true;
        }
    }
    if(found)return 0;
    return 1;
 }

void solve(){
    int n;
    cin>>n;
    ll m=1;
    for(int i=0;i<n;i++){
        ll val;
        cin>>val;
        m*=val;
    }
    m+=1;
    ll pr;
    if(primecheck(m,pr)){
        cout<<m<<endl;
    }
    else cout<<pr<<endl;
}


int main()
{
    fastio;
    sieve();
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}