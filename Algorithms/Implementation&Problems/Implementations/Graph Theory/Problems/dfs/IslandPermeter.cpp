class Solution {
public:
    int bfs(int n){
        vector<int>sqList;
        queue<int>q;
        vector<int>dis(n+1,INT_MAX);
        for(int i=1;i*i<=n;i++){
            sqList.push_back(i*i);
            q.push(i*i);
            dis[i*i]=1;
        }
        while(!q.empty()){
            int tmp=q.front();
            q.pop();
            for(auto u:sqList){
                int nextVal=tmp+u;
                if(nextVal>n)continue;
                if(dis[tmp]+1<dis[nextVal]){
                    dis[nextVal]=dis[tmp]+1;
                    q.push(nextVal);
                }
            }
            
        }
        return dis[n];

    }

    int numSquares(int n) {
        return bfs(n);
    }
};