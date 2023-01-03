#include <bits/stdc++.h>
//Codeforces 1650B
//Author: Mirza Mohammad Azwad
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
       long long l,r,a;
       cin>>l>>r>>a;
       long long val=r;
       int num;
       if(r%a < a-1){
            num=r-(r%a)-1;
       }
       if(num>=l && num<=r)cout<<max(r/a+r%a,num/a+num%a)<<endl;
       else cout<<r/a+r%a<<endl;
    }
    return 0;
}
