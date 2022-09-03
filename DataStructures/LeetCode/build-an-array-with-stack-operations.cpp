class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        queue<string>q;
        int count=1;
        for(int i=0;i<target.size();i++){
            if(target[i]==count){
                q.push("Push");
            }
            else{
                while(target[i]!=count){
                    q.push("Push");
                    q.push("Pop");
                    count++;
                }
                if(target[i]==count){
                    q.push("Push");
                }
            }
            count++;
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
