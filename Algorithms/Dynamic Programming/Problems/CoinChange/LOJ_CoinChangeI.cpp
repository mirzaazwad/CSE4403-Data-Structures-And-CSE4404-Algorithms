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
ll n,k;
ll coin[55];
ll times[55];
ll dp[55][1010];

ll number_of_ways(ll i,ll j)
{
    if(j==0)
        return 1;
    if(i==n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=0;
    for(int d=0; d<=times[i] && j-d*coin[i]>=0; d++)
        dp[i][j]+=number_of_ways(i+1,j-d*coin[i])%100000007;
    return dp[i][j]%100000007;
}


void solve(){
    cin>>n>>k;
    memset(coin,0,sizeof(coin));
    memset(times,0,sizeof(times));
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)cin>>coin[i];
    for(int i=0;i<n;i++)cin>>times[i];
    cout<<number_of_ways(0,k)<<endl;

}

int main()
{
    fastio;
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
