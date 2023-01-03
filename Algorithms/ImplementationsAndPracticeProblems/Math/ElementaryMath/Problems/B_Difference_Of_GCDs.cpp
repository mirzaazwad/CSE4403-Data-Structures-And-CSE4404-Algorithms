#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

void solve(){
    long long n,l,r;
    cin>>n>>l>>r;
    //gcd(ai,i)=i for all gcd(i,ai) distinct
    vector<long long>s;
    for(long long i=1;i<=n;i++){
        long long val=((l-1)/i+1)*i;
        if(val<=r && val>=l){
            s.push_back(val);
        }
    }
    if(s.size()==n){
        cout<<"YES"<<endl;
        for(auto u:s)cout<<u<<" ";
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main()
{
    fastio;
    int t;
    cin >> t;
    
    while(t--)
    {
       solve();
    }
    return 0;
}
