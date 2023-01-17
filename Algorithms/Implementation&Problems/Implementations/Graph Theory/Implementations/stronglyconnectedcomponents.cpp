#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define N 100005
vector<int> adj[N];
vector<int>adjT[N];
stack<int> s;
vector<bool> visited(N, false);

void dfs(int node)
{
  visited[node] = true;
  for (auto u : adj[node])
  {
    if (!visited[u])
    {
      dfs(u);
    }
  }
  s.push(node);
}

void getConnectedComponent(int node){
  visited[node] = true;
  cout<<node<<" ";
  for (auto u : adjT[node])
  {
    if (!visited[u])
    {
      getConnectedComponent(u);
    }
  }

}

void getTranspose(int m){//yeilds reverse graph
  for(int i=0;i<m;i++){
    for(auto u:adj[i]){
      adjT[u].push_back(i);
    }
  }
}

void getSCC(){
  for(int i=0;i<5;i++){
    if(!visited[i])dfs(i);
  }
  getTranspose(5);
  for(int i=0;i<5;i++){
    visited[i]=false;
  }
  while(!s.empty()){
    int v=s.top();
    s.pop();
    if(!visited[v]){
      getConnectedComponent(v);
      cout<<endl;
    }
  }
}

void addEdge(int u,int v){
  adj[u].push_back(v);
}



int main()
{
  addEdge(1, 0);
  addEdge(0, 2);
  addEdge(2, 1);
  addEdge(0, 3);
  addEdge(3, 4);
  getSCC();
  return 0;
}
