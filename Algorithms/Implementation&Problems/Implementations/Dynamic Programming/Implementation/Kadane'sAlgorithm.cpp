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

ll kadanesAlgorithm(vector<ll>array, int n){
    ll currentMaximum=array.front();
    ll maxSoFar=array.front();
    for(int i=0;i<n;i++){
        currentMaximum=max(array[i],currentMaximum+array[i]);
        maxSoFar=max(maxSoFar,currentMaximum);
    }
    return maxSoFar;
}

vector<ll> kadanesAlgorithmSubArray(vector<ll>a, int size)
{
    int max_so_far = a.front(), currentMaximum = a.front(),
       start =0, end = 0, s=0;
  
    for (int i=1; i< size; i++ )
    {
        currentMaximum += a[i];
  
        if (max_so_far < currentMaximum)
        {
            max_so_far = currentMaximum;
            start = s;
            end = i;
        }
  
        if (currentMaximum < a[i])
        {
            currentMaximum = a[i];
            s = i ;
        }
    }
    vector<ll>ans;
    for(int i=start;i<=end;i++)ans.push_back(a[i]);
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<kadanesAlgorithm(arr,n)<<endl;
    vector<ll>ans=kadanesAlgorithmSubArray(arr,n);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<endl;
}
int main()
{
    fastio;
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}