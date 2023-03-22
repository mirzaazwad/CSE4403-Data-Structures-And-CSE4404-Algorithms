#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
int n,m;
vector<ll>coins;
vector<ll>dp;

ll min_coins(ll m){
  if(m==0){
    return 0;
  }
  if(m<0){
    return INT_MAX;
  }
  if(dp[m]!=-1){
    return dp[m];
  }
  dp[m]=INT_MAX;
  for(int i=0;i<n;i++){
    dp[m]=min(dp[m],1+min_coins(m-coins[i]));
  }
  return dp[m];
}


int main(void)
{
    fastio;
    cin>>n>>m;
    coins.resize(n);
    for(ll &i:coins){
      cin>>i;
    }
    dp.assign(m+5,-1);
    ll ans=min_coins(m);
    cout<<(ans>=INT_MAX?-1:ans)<<endl;
    return 0;
}