#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;

ll nums[16][16];
int n;
ll dp[1<<16][16];
const ll mod=1e9+7;

ll PossibleComb(int mask,int row){
  if(mask==((1<<n)-1)){
    return 1;
  
  }
  if(dp[mask][row]!=-1){
    return dp[mask][row];
  }
  dp[mask][row]=0;
  for(int i=0;i<n;i++){
    if(!(mask&(1<<i)) && nums[i][row]==1)dp[mask][row]+=(PossibleComb(mask|(1<<i),row+1)%mod);
  }
  return dp[mask][row]%mod;
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
    cout<<PossibleComb(0,0)<<endl;
    return 0;
}