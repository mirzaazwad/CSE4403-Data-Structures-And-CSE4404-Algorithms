#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long

using namespace std;

ll factorize(int n){
    if(n==0 || n==1){
        return 1;
    }
    else if(n==2){
        return 2;
    }
    else return n*(n-1)*factorize(n-2);
}

int main()
{
    fastio;
    int n;
    while(cin>>n){
        if(n>7 && n<=13)cout<<factorize(n)<<endl;
        else{
            if((n<0 && n%2==0)||(n>=0 && n<=7)){ //this solution is dervied using udebug to check for cases of negative numbers, 
            //check the results in udebug for different constraints in UVA problems
            //for instance you would observe that using udebug for n<0 && n is even you get underflow and for n is odd you get overflow
                cout<<"Underflow!"<<endl;
            }
            else cout<<"Overflow!"<<endl;
        }
    }
    return 0;
}