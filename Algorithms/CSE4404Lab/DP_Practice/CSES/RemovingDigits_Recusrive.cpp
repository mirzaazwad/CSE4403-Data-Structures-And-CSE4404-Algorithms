#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
vector<ll>dp;
ll remove_digits(ll n){
  if(n==0){
    return 0;
  }
  if(n<0){
    return INT_MAX;
  }
  if(dp[n]!=-1){
    return dp[n];
  }
  dp[n]=INT_MAX;
  for(auto u:to_string(n)){
    if(u!='0')dp[n]=min(dp[n],1+remove_digits(n-(u-'0')));
  }
  return dp[n];
}

int main()
{
    fastio;
    ll n;
    cin>>n;
    dp.assign(n+5,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
      for(auto u:to_string(i)){
        if(i-(u-'0')>=0){
          dp[i]=min(dp[i],dp[i-(u-'0')]);
        }
      }
    }
    cout<<dp[n]<<endl;
    return 0;
}