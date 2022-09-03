/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
In the name of Allah, the Lord of Mercy, the Giver of Mercy
*/
#include<iostream>
#include<queue>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"

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
 

void solve(){
    vector<int>tickets;
    int n;
    cin>>n;
    while(n!=-1){
        tickets.push_back(n);
        cin>>n;
    }
    int k;
    cin>>k;
    cout<<timeRequiredToBuy(tickets,k)<<endl;
}
int main()
{
    fastio;
    solve();
    return 0;
}