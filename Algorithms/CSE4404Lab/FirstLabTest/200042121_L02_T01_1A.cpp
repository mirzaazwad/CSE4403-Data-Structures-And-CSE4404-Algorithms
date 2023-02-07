#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
#define N 105
#define ll long long
int graph[N][N];
int dist[N][N];


int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      graph[a][b]=c;
      graph[b][a]=c;
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(i==j)continue;
        if(graph[i][j]!=0){
          dist[i][j]=graph[i][j];
        }
        else dist[i][j]=10005;
      }
    }
    for(int k=1;k<=n;k++){
      for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
          dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
      }
    }
    map<int,vector<ll>>mp;
    int Min=INT_MAX;
    for(int i=1;i<=n;i++){
      int sum=0;
      for(int j=1;j<=n;j++){
        sum+=dist[i][j];
      }
      mp[sum].push_back(i);
      Min=min(sum,Min);
    }
    for(auto u:mp[Min]){
      cout<<u<<" ";
    }
    cout<<endl;

    

    return 0;
}