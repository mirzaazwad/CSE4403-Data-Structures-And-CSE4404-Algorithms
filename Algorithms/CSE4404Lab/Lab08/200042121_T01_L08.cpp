#include <bits/stdc++.h>
using namespace std;
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define N 105
#define endl "\n"
#define ll long long
ll color[N][N];
ll smoke[N][N];

ll MCM(int i, int j)
{
  if (i == j)
  {
    return 0;
  }
  if (smoke[i][j] != -1)
  {
    return smoke[i][j];
  }
  smoke[i][j] = INT_MAX;
  for (int k = i; k < j; k++)
  {
    smoke[i][j] = min(smoke[i][j], color[i][k] * color[k + 1][j] + MCM(i, k) + MCM(k + 1, j));
  }
  return smoke[i][j];
}

int main(void)
{
  fastio;
  int n;
  cin >> n;
  memset(color, 0, sizeof(color));
  memset(smoke, -1, sizeof(smoke));
  vector<ll> colors(n);
  for (ll &i : colors)
    cin >> i;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        color[i][i] = colors[i];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      color[i][j] = color[i][j - 1] + colors[j];
      color[i][j] = color[i][j] % 100;
    }
  }
  cout << MCM(0, n - 1) << endl;
}