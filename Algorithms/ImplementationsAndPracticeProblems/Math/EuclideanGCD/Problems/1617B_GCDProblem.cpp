//This is from codeforces 1617B
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int gcd(int a, int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

void solve(){
    long long n;
    cin>>n;
    cout<<n-3<<" "<<2<<" "<<1<<endl;
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
