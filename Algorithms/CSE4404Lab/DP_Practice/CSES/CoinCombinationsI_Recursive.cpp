#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll n,m;
vector<ll>coins,dp;

ll coin_combinationsI(ll m){
  if(m==0){
    return 1;
  }
  if(m<0){
    return 0;
  }
  if(dp[m]!=-1){
    return dp[m];
  }
  dp[m]=0;
  for(int i=0;i<n;i++){
    dp[m]+=(coin_combinationsI(m-coins[i])%mod);
  }
  dp[m]=dp[m]%mod;
  return dp[m];
}

int main()
{
    fastio;
    cin>>n>>m;
    coins.resize(n);
    for(ll &i:coins)cin>>i;
    dp.assign(m+5,-1);
    cout<<coin_combinationsI(m)<<endl;
    return 0;
}