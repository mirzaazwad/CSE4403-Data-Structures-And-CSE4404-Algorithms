#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int sum(int n){
    if(n==0) return 0;
    else return sum(n-1)+n;
}

int main(){
    int n;//where n indicates the number of natural numbers to be summed
    cin>>n;
    cout<<sum(n)<<endl;
    return 0;
}
