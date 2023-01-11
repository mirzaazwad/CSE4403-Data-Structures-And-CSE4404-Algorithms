//This is a codeforces gym problem I struggled a lot with understanding: The link, https://codeforces.com/gym/100637/problem/J
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
       long long p,q;cin>>p>>q;
           for(long long i=1;;i++){
               p*=i;
               cout<<p/q<<" ";
               p=p%q;
               if(p==0)break;
           }
    return 0;
}
