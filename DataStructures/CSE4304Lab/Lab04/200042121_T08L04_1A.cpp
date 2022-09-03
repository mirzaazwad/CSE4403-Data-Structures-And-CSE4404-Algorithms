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
 

void solve(){
    queue<int>q;
    int n;
    cin>>n;
    int k;
    cin>>k;
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
    cout<<value<<endl;
}
int main()
{
    fastio;
    solve();
    return 0;
}