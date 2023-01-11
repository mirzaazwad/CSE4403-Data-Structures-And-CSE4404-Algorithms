#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

//this version is with memoization, not required as per problem statement but is more efficient

vector<int>dp;

int countNumberOfWays(int n){
    if(n==0){
        return 1;
    }
    else if(n<0){
        return 0;
    }
    else{
        if(dp[n]!=-1){
            return dp[n];
        }
        else{
            dp[n]=countNumberOfWays(n-1)+countNumberOfWays(n-2)+countNumberOfWays(n-3);
            return countNumberOfWays(n-1)+countNumberOfWays(n-2)+countNumberOfWays(n-3);
        }
    }
}
int main()
{
    fastio;
    int s,e;
    cin>>s>>e;
    vector<int>temp(e-s+1,-1);
    dp=temp;
    cout<<countNumberOfWays(e-s)<<endl;
    return 0;
}