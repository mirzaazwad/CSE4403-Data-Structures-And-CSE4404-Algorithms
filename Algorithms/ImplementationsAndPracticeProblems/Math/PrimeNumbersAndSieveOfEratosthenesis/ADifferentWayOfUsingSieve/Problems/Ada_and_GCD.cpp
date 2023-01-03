/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
*/
#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
#define ll long long
#define endl "\n"
const int N =1e7+4569;
const int mod= 1e9+7;

unordered_map<ll,ll>ans;

/* Calculate ( a^b ) %c */
ll bigmod(ll a, ll p, ll MOD)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return a;

    ll res = bigmod(a, p/2, MOD);
    res = (res*res)%MOD;
    if(p&1)
        return (a*res)%MOD;
    return res;
}

vector<ll>primeList(N+1);

void sieve(){
    for(int i=0;i<=N;i++)primeList[i]=i;
    for(int i=2;i<=N;i+=2)primeList[i]=2;
    for(int i=3;i*i<=N;i+=2){
        if(primeList[i]!=i)continue;
        for(int j=i;j<=N;j+=i){
            if(primeList[j]==j){
                primeList[j]=i;
            }
        }
    }
}

void primeFactorisation(ll val, unordered_map<ll,ll>& mp){
    while(val>1){
        mp[primeList[val]]++;
        val/=primeList[val];
    }
}

int main(){
    fastio
    sieve();
    int n;
    cin>>n;
    unordered_map<ll,ll>fact;
    for(int i=0;i<n;i++){
        unordered_map<ll,ll>tmp;
        int m;
        cin>>m;
       for(int k=0;k<m;k++){
            ll val;
            cin>>val;
            primeFactorisation(val,tmp);
        }
        if(i==0)fact=tmp;
        else{
            for(pair<ll,ll> u:fact){
                fact[u.first]=min(tmp[u.first],u.second);
            }
        }
    }
    for(auto u:fact){
        if(u.second>0){
            ans[u.first]=u.second;
        }
    }
    ll val=1;
    for(pair<ll,ll> u:ans){
        val=(val*bigmod(u.first,u.second,mod))%mod;
    }
    cout<<val<<endl;
}
