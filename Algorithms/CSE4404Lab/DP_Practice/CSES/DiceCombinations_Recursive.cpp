#include<bits/stdc++.h>
using namespace std;
#define N 1000007
#define ll long long
ll dp[N];
const ll mod=1e9+7;

ll diceCombinations(ll n){
  if(n==0){
    return 1;
  }
  if(n<0){
    return 0;
  }
  if(dp[n]!=-1){
    return dp[n];
  }
  dp[n]=0;
  for(int i=1;i<=6;i++){
    dp[n]+=(diceCombinations(n-i)%mod);
  }
  dp[n]=dp[n]%mod;
  return dp[n];
}

int main(void){
  ll n;
  cin>>n;
  memset(dp,-1,sizeof(dp));
  cout<<diceCombinations(n)<<endl;
}