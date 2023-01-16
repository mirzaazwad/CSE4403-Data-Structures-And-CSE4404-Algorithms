#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define N 100005
vector<int>adj[N];
vector<int>indegree(N,0);
queue<int>q;

vector<int> topological_sort(int m){
    
    vector<int>ans;
    for(int i=0;i<m;i++){
      if(indegree[i]==0){
        q.push(i);
      }
    }
    while(!q.empty()){
      int tmp=q.front();
      q.pop();
      ans.push_back(tmp);
      for(auto u:adj[tmp]){
        indegree[u]--;
        if(!indegree[u]){
          q.push(u);
        }
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(void){
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    adj[b].push_back(a);
  }
  vector<int>ans=topological_sort(m);
  for(auto u:ans){
    cout<<u<<" ";
  }
}