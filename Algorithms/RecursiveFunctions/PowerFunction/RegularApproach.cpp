#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int pow(int x, int n){
    return n==0 ? 1:x*pow(x,n-1);
}

int main(){
    int x, n;
    cin>>x>>n;
    cout<<pow(x,n)<<endl;
}
