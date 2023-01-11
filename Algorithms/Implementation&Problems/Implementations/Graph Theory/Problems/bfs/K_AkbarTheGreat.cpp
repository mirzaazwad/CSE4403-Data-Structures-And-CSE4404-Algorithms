//This problem took me a while to get, so try it out, link: https://www.spoj.com/problems/AKBAR/en/
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define SIZE 1000002

using namespace std;
int troops[SIZE];
bool visited[SIZE];
vector<int>adj[SIZE];
queue<pair<int,int>>bfsq;

bool trooper(int a){
    if(troops[a]!=1)return true;
    else return false;
}

void memory_clear(int n){
    memset(troops,0,(n+2)*sizeof(int));
    for(int i=1;i<=n;i++)adj[i].clear();
}

void bfs(const pair<int,int>&p){
    if(!p.second){
        while(!bfsq.empty())bfsq.pop();
        return;
    }
        for(auto u:adj[p.first]){
            if(!visited[u]){
                visited[u]=true;
                bfsq.push({u,p.second-1});
                troops[u]++;
            }
        }
        bfsq.pop();
        if(!bfsq.empty())bfs(bfsq.front());
}





int main()
{
    fastio;
    int t;
    cin >> t;
    
    while(t--)
    {
       int n,r,m;cin>>n>>r>>m;
       for(int i=0;i<r;i++){
           int a,b;cin>>a>>b;
           adj[a].push_back(b);
           adj[b].push_back(a);
       }
       for(int i=0;i<m;i++){
           int k,s;cin>>k>>s;
            bfsq.push({k,s});
            visited[k]=true;
            troops[k]++;
            bfs(bfsq.front());
            memset(visited,false,(n+2));
       }
       if(any_of(troops+1,troops+n+1,trooper))cout<<"No"<<"\n";
       else cout<<"Yes"<<"\n";

        memory_clear(n);

    }
    return 0;
}
