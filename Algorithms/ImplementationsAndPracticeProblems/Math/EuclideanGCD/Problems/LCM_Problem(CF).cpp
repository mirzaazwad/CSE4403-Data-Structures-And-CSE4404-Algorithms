//Link: https://codeforces.com/problemset/problem/1389/A
//if the number l and r, the lcm can only exist if 2*l<=r, the answer would be x=l and y=2*l
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
       long long l,r;cin>>l>>r;
       if(2*l>r)cout<<-1<<" "<<-1<<endl;
       else cout<<l<<" "<<2*l<<endl;
    }
    return 0;
}
