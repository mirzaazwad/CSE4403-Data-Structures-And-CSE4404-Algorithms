#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution
{
public:

  vector<int> eventualSafeNodes(vector<vector<int>> &graph)
  {
    vector<int>indegree(graph.size(),0);
    vector<int>adj[graph.size()];
    for(int i=0;i<graph.size();i++){
      for(auto u:graph[i]){
        adj[u].push_back(i);
        indegree[i]++;
      }
    }
    queue<int>q;
    vector<int>ans;
    for(int i=0;i<graph.size();i++){
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
};

int main()
{
  fastio;
  vector<vector<int>> adj(7);
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(5);
  adj[3].push_back(0);
  adj[4].push_back(5);
  adj[5].push_back(5);
  adj[6].push_back(6);
  Solution *solve=new Solution();
  solve->eventualSafeNodes(adj);
  return 0;
}