#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
vector<ll>a_arr,b_arr,c_arr;
int n;
ll dp[100005][3][3][3];

ll vacation(int i,int a,int b,int c){
  if(a>=2 || b>=2 || c>=2){
    return INT_MIN;
  }
  if(i==n){
    return 0;
  }
  if(dp[i][a][b][c]!=-1){
    return dp[i][a][b][c];
  }
  dp[i][a][b][c]=INT_MIN;
  dp[i][a][b][c]=max(dp[i][a][b][c],a_arr[i]+vacation(i+1,a+1,0,0));
  dp[i][a][b][c]=max(dp[i][a][b][c],b_arr[i]+vacation(i+1,0,b+1,0));
  dp[i][a][b][c]=max(dp[i][a][b][c],c_arr[i]+vacation(i+1,0,0,c+1));
  return dp[i][a][b][c];
}

int main()
{
    fastio;
    cin>>n;
    a_arr.resize(n);
    b_arr.resize(n);
    c_arr.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
      cin>>a_arr[i]>>b_arr[i]>>c_arr[i];
    }
    cout<<vacation(0,0,0,0)<<endl;
    return 0;
}