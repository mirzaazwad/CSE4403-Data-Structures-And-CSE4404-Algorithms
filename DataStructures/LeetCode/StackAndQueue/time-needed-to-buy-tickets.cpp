class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        for(int i=0;i<tickets.size();i++)q.push(i);
        int time=0;
        vector<int>times(tickets.size());
        while(!q.empty()){
            if(tickets[q.front()]>0){
                tickets[q.front()]--;
                time++;
                times[q.front()]=time;
                int ix=q.front();
                q.pop();
                q.push(ix);
            }
            else q.pop();
        }
        return times[k];
        
    }
};
