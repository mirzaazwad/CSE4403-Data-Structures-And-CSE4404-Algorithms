#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int n;
    cin>>n;
    while(n>0){
        long long sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                sum+=__gcd(i,j);
            }
        }
        cout<<sum<<endl;
        cin>>n;
    }
    return 0;
}