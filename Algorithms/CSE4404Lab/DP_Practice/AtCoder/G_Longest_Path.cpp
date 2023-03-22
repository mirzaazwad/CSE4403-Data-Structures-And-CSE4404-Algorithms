#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
const ll N=1e5+5;
vector<ll>adj[N],traversal_sequence;
bool visited[N];

void dfs(ll node){
  visited[node]=true;
  for(auto u:adj[node]){
    if(!visited[u]){
      dfs(u);
    }
  }
  traversal_sequence.push_back(node);
}


int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    ll start=LLONG_MAX;
    for(int i=0;i<m;i++){
      ll a,b;
      cin>>a>>b;
      adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
      if(!visited[i]){
        dfs(i);
      }
    }
    reverse(traversal_sequence.begin(),traversal_sequence.end());
    vector<ll>dp(n+1,0);
     for (auto i: traversal_sequence) {
        for (auto j: adj[i])
        {
          dp[j] = max(dp[j], dp[i] + 1);
        }
    }
    cout<<*max_element(dp.begin(), dp.end());
    return 0;
}