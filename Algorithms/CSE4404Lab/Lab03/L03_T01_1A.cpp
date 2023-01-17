class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto u:prerequisites){
            adj[u[1]].push_back(u[0]);
            indegree[u[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }

        vector<int>ans;
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
        if(ans.size()==numCourses)return ans;
        else return {};
    }
};