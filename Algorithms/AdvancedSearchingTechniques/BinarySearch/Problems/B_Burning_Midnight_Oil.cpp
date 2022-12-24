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
 

class Solution{
    public:
    ll n,m;
    Solution(){
        cin>>n>>m;
    }

    bool isFound(ll mid){
        ll ans=0;
        ans+=mid;
        while(mid>0){
            mid/=m;
            ans+=mid;
        }
        return ans>=n;
    }

    void runner(){
        ll high=1e9+1;
        ll low=0;
        ll mid;
        while(high-low>1){
            mid=(high+low)/2;
            if(isFound(mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        if(isFound(low)){
            cout<<low<<endl;
        }
        else{
            cout<<high<<endl;
        }
    }

};

int main(void){
    Solution solve;
    solve.runner();
}
