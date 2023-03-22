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


int main(void)
{
    fastio;
    cin>>n>>m;
    coins.resize(n);
    for(ll &i:coins){
      cin>>i;
    }
    dp.assign(m+5,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=m;i++){
      for(int j=0;j<n;j++){
        if(i-coins[j]>=0){
          dp[i]=min(dp[i],dp[i-coins[j]]+1);
        }
      }
    }
    cout<<(dp[m]>=INT_MAX?-1:dp[m])<<endl;
    return 0;
}