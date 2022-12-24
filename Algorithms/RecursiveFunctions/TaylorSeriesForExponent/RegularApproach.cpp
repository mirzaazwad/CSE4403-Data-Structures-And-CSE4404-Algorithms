#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

double exp(int x,int n){
    static double p=1,f=1;
    double r;
    if(n==0)return 1;
    r  = exp(x,n-1);
    p=p*x;
    f=f*n;
    return r+p/f;

}

int main(){
    int x,n;
    cin>>x>>n;
    cout<<exp(x,n)<<endl;
    return 0;
}
