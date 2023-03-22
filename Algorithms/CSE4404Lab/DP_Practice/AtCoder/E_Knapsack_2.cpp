#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
int n, m;
vector<ll> v, w;

int main()
{
  fastio;
  cin >> n >> m;
  v.resize(n + 1);
  w.resize(n + 1);
  v[0] = w[0] = 0;
  for (int i = 1; i < n + 1; i++)
  {
    cin >> w[i] >> v[i];
  }
  int N = 1e5 + 5;
  vector<vector<ll>> dp(n + 5, vector<ll>(N + 5, 1LL<<60));
  dp[0][0]=0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<N;j++){
      dp[i][j]=dp[i-1][j];
      if(j-v[i]>=0){
        dp[i][j]=min(dp[i][j],w[i]+dp[i-1][j-v[i]]);
      }
    }
  }
  for(int i=N;i>=1;i--){
    if(dp[n][i]<=m){
      cout<<i<<endl;
      return 0;
    }
  }
  return 0;
}