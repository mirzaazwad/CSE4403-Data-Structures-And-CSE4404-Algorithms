#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
#define N 10005
using namespace std;
vector<ll>adj[N];
vector<int>color(N,-1);

bool bipartite(int node,int parent){
  color[node]=!color[parent];
  for(auto u:adj[node]){
    if(color[u]!=-1){
      if(color[u]==color[node])
      {
        return false;
      }
    }
    else return bipartite(u,node);
  }
  return true;
}

int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    color[0]=1;
    if(bipartite(0,0)){
      cout<<"BICOLORABLE."<<endl;
    }
    else{
      cout<<"NOT BICOLORABLE."<<endl;
    }
    return 0;
}