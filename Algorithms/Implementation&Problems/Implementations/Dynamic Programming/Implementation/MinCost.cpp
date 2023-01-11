#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;



int min_cost_dp(vector<vector<int>>input,int m,int n){
    int dp[m][n];
    memset(dp,-1,sizeof(dp));
    dp[m-1][n-1]=input[m-1][n-1];
    for(int j=n-2;j>=0;j--){//row last
        dp[m-1][j]=dp[m-1][j+1]+input[m-1][j];
    }
    for(int i=m-2;i>=0;i--){//column last
        dp[i][n-1]=dp[i+1][n-1]+input[i][n-1];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            dp[i][j]=input[i][j]+min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
        }
    }
    return dp[0][0];

}

int min_cost_naive(vector<vector<int>>nodes,int si, int sj,int ei,int ej){
    if(si==ei && sj==ej){
        return nodes[ei][ej];
    }
    if(si>ei || sj>ej){
        return INT_MAX;
    }
    int output1=min_cost_naive(nodes,si+1,sj,ei,ej);
    int output2=min_cost_naive(nodes,si+1,sj+1,ei,ej);
    int output3=min_cost_naive(nodes,si,sj+1,ei,ej);
    return nodes[si][sj]+min(output1,min(output2,output3));
}



int main()
{
    fastio;
    vector<vector<int>>v;
    for(int i=0;i<3;i++){
        vector<int>temp;
        for(int j=0;j<3;j++){
            int value;
            cin>>value;
            temp.push_back(value);
        }
        v.push_back(temp);
    }
    cout<<min_cost_naive(v,0,0,2,2)<<endl;
    cout<<min_cost_dp(v,3,3)<<endl;

    return 0;
}