//this problem is from SPOJ and is titled ABCPath
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
    memset(visited, false, sizeof(visited));
    memset(dis, 0, sizeof(dis));
    while(!q.empty())q.pop();
}

void bfs(int node){
    dis[node]=0;
    visited[node]=true;
    q.push(node);
    while(!q.empty()){
        int root=q.front();
        for(auto u:adj){

        }
    }
}

int main()
{
    fastio;
    int 
 return 0;
}
