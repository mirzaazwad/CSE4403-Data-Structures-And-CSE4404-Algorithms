//Problem Link: https://www.codechef.com/problems/COPR16G
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int t;
    cin >> t;
    
    while(t--)
    {
        long a,b;
       cin>>a>>b;
       if(__gcd(a,b)==1){
           cout<<a*b-a-b+1<<endl;
       }
       else cout<<-1<<endl;
    }
    return 0;
}
