#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
#define ll long long

//Although not required by given constraints the dp solution using memoization of recursive function
vector<vector<ll>>dp;

ll knapSack(ll W, vector<ll>weight, vector<ll>value, ll N)
{
    if (N == 0 || W == 0)
        return 0;
    if (weight[N - 1] > W)
        return knapSack(W, weight, value, N - 1);
    else if(dp[N][W]!=-1){
        return dp[N][W];
    }
    else
        dp[N][W]=max(value[N - 1]+knapSack(W - weight[N - 1],weight, value, N - 1),knapSack(W, weight, value, N - 1));
        return dp[N][W];
}
 

int main()
{
    fastio;
    ll N,W;
    cin>>N>>W;
    vector<ll>weight(N),value(N),temp(W+1,-1);
    for(int i=0;i<=N;i++){
        dp.push_back(temp);
    }
    for(int i=0;i<N;i++){
        cin>>weight[i]>>value[i];
    }
    cout<<knapSack(W,weight,value,N)<<endl;
    dp.clear();

    return 0;
}