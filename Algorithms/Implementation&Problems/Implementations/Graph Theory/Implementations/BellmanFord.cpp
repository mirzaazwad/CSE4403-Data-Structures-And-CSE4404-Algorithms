#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define N 2505
ll dist[N];
vector<tuple<ll, ll, ll>> edges;
vector<ll>adj[N];
int n, m;
#define INF 1e18

bool bellman_ford(int x)
{
  for (int i = 1; i <= n; i++)
  {
    dist[i] = INF;
  }
  dist[1] = 0;
  for (int i = 0; i < n-1; i++)
  {
    for (auto u : edges)
    {
      int a, b, w;
      tie(a, b, w) = u;
      if (dist[b] > dist[a] + w)
      {
        dist[b] = dist[a] + w;
      }
    }
  }
  return true;
}

void build_graph()
{
  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    edges.emplace_back(a, b, -w);
    adj[a].push_back(b);
  }
}

int main(void)
{
  fastio;
  cin >> n >> m;
  build_graph();
  bellman_ford(1);
  for(int i=0;i<n;i++){
    cout<<dist[i]<<" ";
  }
  cout<<endl;
  return 0;
}