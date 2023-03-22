#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int nums[16][16];
int n;
int dp[1<<16][16];
int maxPriority(int mask,int row){
  if(mask==((1<<n)-1)){
    return 0;
  
  }
  if(dp[mask][row]!=-1){
    return dp[mask][row];
  }
  dp[mask][row]=0;

  for(int i=0;i<n;i++){
    if(!(mask&(1<<i)))dp[mask][row]=max(dp[mask][row],nums[row][i]+maxPriority(mask|(1<<i),row+1));
  }
  return dp[mask][row];
}

int main()
{
    fastio;
    cin>>n;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin>>nums[i][j];
      }
    }
    memset(dp,-1,sizeof(dp));
    cout<<maxPriority(0,0)<<endl;
    return 0;
}