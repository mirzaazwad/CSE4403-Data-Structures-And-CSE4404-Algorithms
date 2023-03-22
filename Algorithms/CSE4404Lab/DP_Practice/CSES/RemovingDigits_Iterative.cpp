#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
vector<ll>dp;

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
          dp[i]=min(dp[i],1+dp[i-(u-'0')]);
        }
      }
    }
    cout<<dp[n]<<endl;
    return 0;
}