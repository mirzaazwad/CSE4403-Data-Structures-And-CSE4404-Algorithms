#include<iostream>
#include<vector>
using namespace std;
#define ll long long

ll sum(vector<ll>v,ll n){
    if(n-1==0){
        return v[0];
    }
    else return v[n-1]+sum(v,n-1);
}

void solve(){
    int n;
    cin>>n;
    vector<ll>nums(n);
    for(ll& i:nums)cin>>i;
    cout<<sum(nums,n)<<endl;

}

int main(void){
    int t;
    cin >> t;
    
    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<": ";
       solve();
    }
}