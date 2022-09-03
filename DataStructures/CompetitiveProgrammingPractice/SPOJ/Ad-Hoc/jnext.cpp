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

void clearStack(stack<int>s){
    while(!s.empty()){
        s.pop();
    }
}
 

void solve(){
    int n;
    cin>>n;
    int arr[n];
    ll num=0;
    for(int i=0;i<n;i++)cin>>arr[i];
    int i;
    for(i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1])break;
    }
    if(i==-1){
        cout<<-1<<endl;
        return;
    }
    int j;
    for(j=i+1;j<n;j++){
        if(arr[j]<=arr[i])break;
    }
    swap(arr[i],arr[j-1]);
    sort(arr+i+1,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
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
