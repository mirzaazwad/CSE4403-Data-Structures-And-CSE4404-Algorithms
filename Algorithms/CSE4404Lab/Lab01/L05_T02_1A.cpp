#include<iostream>
#include<vector>
using namespace std;


void dfs(int start,vector<vector<int>>v,vector<bool>&visited){
  visited[start]=true;
  for (int i = 0; i < v[start].size(); i++) {
        if (v[start][i] == 1 && (!visited[i])) {
            dfs(i,v, visited);
        }
    }
}



int findNumberOfConnectedComponents(vector<int>nodes,vector<vector<int>>v){
  int count=0;
  vector<bool>flag(nodes.size(),false);
  for(int i:nodes){
    if(!flag[i]){
      dfs(i,v,flag);
      count++;
    }
  }
  return count;
}


int main(void){
  int n;
  cin>>n;
  vector<vector<int>>v;
  for(int i=0;i<n;i++){
    vector<int>temp(n);
    for(int j=0;j<n;j++){
      cin>>temp[j];
    }
    v.push_back(temp);
  }
  vector<int>nodes;
  for(int i=0;i<n;i++){
    nodes.push_back(i);
  }
  cout<<findNumberOfConnectedComponents(nodes,v)<<endl;
  
}