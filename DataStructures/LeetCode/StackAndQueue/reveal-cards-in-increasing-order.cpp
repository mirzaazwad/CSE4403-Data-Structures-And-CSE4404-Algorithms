class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int>q;
        int n=deck.size();
        for(int i=0;i<n;i++)q.push(i);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[q.front()]=deck[i];
            q.pop();
            int ix=q.front();
            q.pop();
            q.push(ix);
        }
        return ans;
    }
};
