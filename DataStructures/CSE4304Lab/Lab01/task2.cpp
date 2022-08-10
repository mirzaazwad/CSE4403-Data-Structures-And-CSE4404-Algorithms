#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int factorial(int n){
    if(n==0)return 1;
    else return n*factorial(n-1);

}

int main()
{
    fastio;
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}
