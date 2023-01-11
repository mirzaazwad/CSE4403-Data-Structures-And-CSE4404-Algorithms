/*
Coin Change Problem
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.
Output Format
Print the total total number of ways i.e. W.
Constraints :
1 <= n <= 10
1 <= V <= 1000

Time Limit: 1sec
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903
*/
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long

using namespace std;

int dp[1001][11];

int CoinChange(int value,ll *coins,int len){
    if(value==0){
        return 1;
    }
    if(value<0){
        return 0;
    }
    if(len==0){
        return 0;
    }
    if(dp[value][len]!=-1){
        return dp[value][len];
    }
    int first=CoinChange(value-coins[0],coins,len);
    int second=CoinChange(value,coins+1,len-1);
    dp[value][len]=first+second;
    return dp[value][len];
}

// This code is
ll CoinChangeIterative(ll coins[], int n, ll sum)
{
	// table[i] will be storing the number of solutions for
	// value i. We need sum+1 rows as the table is
	// constructed in bottom up manner using the base case
	// (sum = 0)
	ll table[sum + 1];

	// Initialize all table values as 0
	memset(table, 0, sizeof(table));

	// Base case (If given value is 0)
	table[0] = 1;//when value is 0 there is only one option no coins and we are counting the number of options

	// Pick all coins one by one and update the table[] values after the index greater than or equal to the value of the picked coin
	for (int i = 0; i < n; i++){
		for (int j = coins[i]; j <= sum; j++){
			table[j] += table[j - coins[i]];//first option v
        }
	}
	return table[sum];
}

int main()
{
    fastio;
    int amount,numberOfCoinTypes;

    cin>>numberOfCoinTypes;
    cin>>amount;

    ll coinDenominations[numberOfCoinTypes];

    for(int i=0;i<numberOfCoinTypes;i++)cin>>coinDenominations[i];

    

    memset(dp,-1,sizeof(dp));

    cout<<CoinChange(amount,coinDenominations,numberOfCoinTypes)<<endl;
    for(int i=0;i<=amount;i++){
        for(int j=0;j<=numberOfCoinTypes;j++)cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<CoinChangeIterative(coinDenominations,numberOfCoinTypes,amount);

    return 0;
}