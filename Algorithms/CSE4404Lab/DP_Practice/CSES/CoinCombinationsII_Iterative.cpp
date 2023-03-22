#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
ll n, m;
vector<ll> coins, dp;

int main()
{
  fastio;
  cin >> n >> m;
  coins.resize(n);
  for (ll &i : coins)
    cin >> i;
  dp.assign(m + 5, 0);
  dp[0] = 1;
  for (int j = 0; j < n; j++)
  {
    for (int i = 1; i <= m; i++)
    {
      if (i - coins[j] >= 0)
      {
        dp[i] += (dp[i - coins[j]] % mod);
      }
    }
  }
  cout << dp[m]%mod << endl;
  return 0;
}