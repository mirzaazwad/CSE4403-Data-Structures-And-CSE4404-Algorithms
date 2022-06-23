#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int pow(int m,int n){
    int i=1;
    while(n>=1){
        if((n&1)){
            i=i*m;
            m=m*m;
            n=(n-1)/2;
        }
        else{
            m=m*m;
            n=n/2;
        }
    }
    return i;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    cout<<pow(n,m)<<endl;
}
