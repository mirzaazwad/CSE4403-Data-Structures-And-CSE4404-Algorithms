#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

double e(int x, int n){
    static double sum=1;
    for(int i=n;i>0;i--){
        sum=1+((double)x/(double)i)*sum;
    }
    return sum;
}

int main(){
    int x,n;
    cin>>x>>n;
    cout<<e(x,n)<<endl;
    return 0;
}
