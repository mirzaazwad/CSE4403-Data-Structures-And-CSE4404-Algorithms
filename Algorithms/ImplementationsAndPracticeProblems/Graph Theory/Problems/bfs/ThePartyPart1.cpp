//this problem is from UVA and is UVA-10959
//UVA for some reason does not support iterating using auto
#include<bits/stdc++.h>

using namespace std;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define el "\n"

queue<int>q;
bool visited[1001];
int dis[1001];
vector<int>adj[1001];

void memory_clear(){
    for(int i=0;i<1001;i++)adj[i].clear();
    memset(visited, false, sizeof(visited));
    memset(dis, 0, sizeof(dis));
}

void bfs(int node){
    dis[node]=0;
    visited[node]=true;
    q.push(node);
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(auto u:adj[node]){
            if(!visited[u]){
                visited[u]=true;
                q.push(u);
                dis[u]=dis[node]+1;
            }
        }
    }
}

int main()
{
    fastio;
    int t;
    cin >> t;
    
    while(t--)
    {
       int D,P;
        cin>>D>>P;
        for(int i=0;i<P;i++){
            int a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs(0);
        for(int i=1;i<D;i++)cout<<dis[i]<<'\n';
        memory_clear();
        if(t)cout<<'\n';
    }
 return 0;
}
