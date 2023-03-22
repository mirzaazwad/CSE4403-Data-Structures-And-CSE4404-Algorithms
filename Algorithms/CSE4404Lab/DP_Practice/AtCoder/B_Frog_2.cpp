#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
int n,k;
vector<ll>dp;
vector<ll>arr;
ll frog(int i){
  if(i<=0){
    return 0;
  }
  if(dp[i]!=-1){
    return dp[i];
  }
  dp[i]=INT_MAX;
  for(int j=1;j<=k;j++){
    if(i-j>=0){
      dp[i]=min(dp[i],abs(arr[i]-arr[i-j])+frog(i-j));
    }
  }
  return dp[i];
}

int main()
{
    fastio;
    cin>>n>>k;
    arr.resize(n);
    dp.assign(n+5,-1);
    for(ll &i:arr)cin>>i;
    cout<<frog(n-1)<<endl;
    return 0;
}