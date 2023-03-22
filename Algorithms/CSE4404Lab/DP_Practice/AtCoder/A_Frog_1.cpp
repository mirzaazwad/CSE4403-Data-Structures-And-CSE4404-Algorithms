#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
int n;
vector<ll>dp;
vector<ll>arr;
ll frog(int i){
  if(i<=0){
    return 0;
  }
  if(dp[i]!=-1){
    return dp[i];
  }
  if(i-1>=0 && i-2<0){
    return dp[i]=abs(arr[i]-arr[i-1])+frog(i-1);
  }
  return dp[i]=min(abs(arr[i]-arr[i-1])+frog(i-1),abs(arr[i]-arr[i-2])+frog(i-2));
}

int main()
{
    fastio;
    cin>>n;
    arr.resize(n);
    dp.assign(n+5,-1);
    for(ll &i:arr)cin>>i;
    cout<<frog(n-1)<<endl;
    return 0;
}