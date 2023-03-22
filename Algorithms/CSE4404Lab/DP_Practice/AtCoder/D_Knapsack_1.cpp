#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
int n, m;
ll dp[100005][105];
vector<ll> v, w;

ll knapsack(int i, ll m)
{
  if (m == 0)
  {
    return 0;
  }
  if(i==n){
    return 0;
  }
  if(dp[m][i]!=-1){
    return dp[m][i];
  }
  if (m - w[i] >= 0)
  {
    return dp[m][i]=max(knapsack(i + 1, m), v[i] + knapsack(i + 1, m - w[i]));
  }
  return dp[m][i]=knapsack(i+1,m);
}

int main()
{
  fastio;
  cin >> n >> m;
  v.resize(n);
  w.resize(n);
  memset(dp,-1,sizeof(dp));
  for (int i = 0; i < n; i++)
  {
    cin >> w[i] >> v[i];
  }
  cout << knapsack(0,m) << endl;
  return 0;
}