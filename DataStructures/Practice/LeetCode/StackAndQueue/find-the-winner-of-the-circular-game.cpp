class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    int value=q.front();
    while(!q.empty()){
        for(int i=0;i<k-1;i++){
            int value=q.front();
            q.pop();
            q.push(value);
        }
        value=q.front();
        q.pop();
    }
    return value;
    }
};
