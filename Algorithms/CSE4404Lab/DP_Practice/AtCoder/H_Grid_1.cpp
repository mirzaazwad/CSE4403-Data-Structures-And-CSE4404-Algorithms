#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
const ll mod=1e9+7;
int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    string grid[n+9];
    for(int i=0;i<n;i++){
      cin>>grid[i];
    }
    vector<vector<ll>>dp(n+9,vector<ll>(m+9,0));
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
      dp[0][i]=grid[0][i]=='.'?dp[0][i-1]:0;
    }
    for(int i=1;i<=n;i++){
      dp[i][0]=grid[i][0]=='.'?dp[i-1][0]:0;
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(grid[i][j]=='.'){
          dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
        }
      }
    }
    cout<<dp[n-1][m-1]<<endl;
    return 0;
}