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

set<int>s;
 
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

void solve(){
    ll l,r;
    cin>>l>>r;
    segmentedSieve(l,r);
    for(auto u:s)cout<<u<<endl;
    s.clear();
    cout<<endl;
}
int main()
{
    fastio;
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
