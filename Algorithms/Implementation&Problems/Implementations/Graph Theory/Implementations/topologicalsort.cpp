#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define N 100005
vector<int> adj[N];
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

void topologicalSort()
{
  for (int i = 0; i < 6; i++)
  {
    if (!visited[i])
    {
      dfs(i);
    }
  }
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

void topological_sort()//Sir's Algorithm
{
  vector<int>v[6];
  vector<int> indegree(N, 0);
  for (int i = 0; i < 6; i++)
  {
    for (auto u : adj[i])
    {
      v[u].push_back(i);
      indegree[u]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < 6; i++)
  {
    if (!indegree[i])
    {
      q.push(i);
    }
  }
  vector<int> ans;
  while (!q.empty())
  {
    int tmp = q.front();
    q.pop();
    ans.push_back(tmp);
    for (auto u : adj[tmp])
    {
      indegree[u]--;
      if (!indegree[u])
      {
        q.push(u);
      }
    }
  }
  for (auto u : ans)
  {
    cout << u << " ";
  }
  cout << endl;
}

int main()
{
  adj[5].push_back(2);
  adj[5].push_back(0);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(1);

  cout << "Following is a Topological Sort of the given "
          "graph \n";
  topologicalSort();
  // Function Call
  topological_sort();
  return 0;
}
