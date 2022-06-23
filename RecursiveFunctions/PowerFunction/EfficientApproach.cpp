#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int pow(int x,int n){
    if((n&1)){
        return x*pow(x*x,(n-1)/2);
    }
    else{
        return n==0?1:pow(x*x,n/2);
    }
}

int main(){
    int x, n;
    cin>>x>>n;
    cout<<pow(x,n)<<endl;
}
