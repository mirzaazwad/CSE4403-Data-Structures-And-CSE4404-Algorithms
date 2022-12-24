//The link: https://codeforces.com/gym/103150/problem/F is another problem I suffered a lot with
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

void palindrome(int n){
        if(n==1){
           cout<<"z";
           return;
       }
       if(n==0)return;
       int i=(-1+(int)sqrt(double(1+8*n)))/2;
       for(int j=0;j<i;j++){
           cout<<"z";
       }
       int rem=n-(i*(i+1))/2;
       if(rem==1){
           cout<<"a";
           return;
       }
       if(rem==2){
           cout<<"bc";
           return;
       }
       if(rem>0){
           cout<<"bc";
           palindrome(rem-2);
       }
       return;
}

int main()
{
    fastio;
    int t;
    cin >> t;
    
    while(t--)
    {
       int n;
       cin>>n;
       palindrome(n);
       cout<<endl;
    }
    return 0;
}
