#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long
using namespace std;
string s;
string t;
int s_len,t_len;
ll dp[3005][3005];

int LCS(int x,int y){
  if(x==s_len || y==t_len){
    return 0;
  }
  if(dp[x][y]!=-1){
    return dp[x][y];
  }
  if(s[x]==t[y]){
    return dp[x][y]=1+LCS(x+1,y+1);
  }
  else return dp[x][y]=max(LCS(x+1,y),LCS(x,y+1));
}

int main()
{
    fastio;
    cin>>s>>t;
    s_len=s.length();
    t_len=t.length();
    memset(dp,-1,sizeof(dp));
    int i=0;
    int j=0;
    LCS(0,0);
    string ans;
    while(i<s_len && j<t_len){
      if(s[i]==t[j]){
        ans.push_back(s[i]);
        i++;
        j++;
      }
      else if(dp[i+1][j]>dp[i][j+1]){
        i++;
      }
      else{
        j++;
      }
    }
    cout<<ans<<endl;
    return 0;
}