#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

double e(int x, int n){
    static double sum=1;
    if(n==0){
        return sum;
    }
    sum=1+((double)x/(double)n)*sum;
    return e(x,n-1);
}

int main(){
    int x,n;
    cin>>x>>n;
    cout<<e(x,n)<<endl;
    return 0;
}
