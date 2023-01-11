#include<bits/stdc++.h>
using namespace std;


bool vis[12]={false};
vector<int>v[12];
vector<int>dis(12,-1);
queue<int>q;

void bfs(int node){
    q.push(node);
    vis[node]=true;
    dis[node]=0;
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(auto u:v[node]){
            if(!vis[u]){
                q.push(u);
                vis[u]=true;
                dis[u]=dis[node]+1;
            }
        }
    }
}
int main(){

    int a,b;
    for(int i=0;i<9;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(6);
    for(int i=0;i<12;i++){
        cout<<i<<" "<<dis[i]<<"\n";
    }
}