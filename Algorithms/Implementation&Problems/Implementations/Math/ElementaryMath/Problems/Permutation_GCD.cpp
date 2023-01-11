/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
In the name of Allah, the Lord of Mercy, the Giver of Mercy
*/
#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"
 

void solve(){
    int n,x;
    cin>>n>>x;
    if(x<n){
        cout<<-1<<endl;
        return;
    }
    int value=x-(n-1);
    cout<<value<<" ";
    for(int i=1;i<=n;i++){
        if(i!=value)cout<<i<<" ";
    }
    cout<<endl;

}
int main()
{
    fastio;
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}