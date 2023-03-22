#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
const ll mod=1e9+7;
char grid[1005][1005];
ll dp[1005][1005];
int n;

int main()
{
    fastio;
    cin>>n;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin>>grid[i][j];
      }
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
      dp[i][0]=grid[i][0]=='.'?dp[i-1][0]:0;
      dp[0][i]=grid[0][i]=='.'?dp[0][i-1]:0;
    }
    for(int i=1;i<n;i++){
      for(int j=1;j<n;j++){
        if(grid[i][j]=='.'){
          dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
        }
      }
    }
    cout<<(grid[n-1][n-1]!='*' && grid[0][0]!='*'?dp[n-1][n-1]:0)%mod<<endl;
    return 0;
}