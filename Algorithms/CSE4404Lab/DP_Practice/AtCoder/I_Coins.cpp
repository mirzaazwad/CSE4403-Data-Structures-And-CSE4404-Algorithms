#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int n;
    cin>>n;
    vector<double>p(n);
    for(double &i:p)cin>>i;
    vector<vector<double>>dp(n+1,vector<double>(n+1,0.0));
    dp[0][0]=1-p.front();
    dp[1][0]=p.front();
    for(int i=0;i<=n;i++){
      for(int j=1;j<n;j++){
        if(i>0)dp[i][j]+=dp[i-1][j-1]*p[j];
        dp[i][j]+=dp[i][j-1]*(1-p[j]);
      }
    }
    double ans=0;
    for(int i=n/2+1;i<=n;i++){
      ans+=dp[i][n-1];
    }
    cout.precision(10);
    cout<<ans<<endl;
    return 0;
}