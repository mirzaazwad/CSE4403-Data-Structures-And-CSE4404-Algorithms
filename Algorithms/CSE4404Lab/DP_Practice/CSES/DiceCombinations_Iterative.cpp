#include<bits/stdc++.h>
using namespace std;
#define N 1000007
#define ll long long
const ll mod=1e9+7;

int main(void){
  ll n;
  cin>>n;
  vector<ll>dp(n+5,0);
  dp[0]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=6;j++){
      if(i-j>=0){
        dp[i]+=((dp[i-j])%mod);
      }
    }
  }
  cout<<dp[n]%mod<<endl;
}