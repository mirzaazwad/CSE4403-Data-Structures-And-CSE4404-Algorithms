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

ll gridPath(int sx,int sy){
  if(sx==n-1 && sy == n-1 && grid[sx][sy]!='*'){
    return 1;
  }
  if(sx<0 || sx>=n || sy<0 || sy>=n || grid[sx][sy]=='*'){
    return 0;
  }
  if(dp[sx][sy]!=-1){
    return dp[sx][sy];
  }
  return dp[sx][sy]=(gridPath(sx+1,sy)%mod+gridPath(sx,sy+1)%mod)%mod;
}

int main()
{
    fastio;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin>>grid[i][j];
      }
    }
    cout<<gridPath(0,0)<<endl;
    return 0;
}