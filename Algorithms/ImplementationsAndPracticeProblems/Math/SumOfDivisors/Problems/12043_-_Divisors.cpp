/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
*/
#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"
#define N 100000

ll arr_d[N+5],arr_h[N+5];

void divisors(){
    arr_d[1]=1;
    arr_h[1]=1;
    for(int i=2;i<=N;i++){
        ll tmp_h(0LL),tmp_d(0LL);
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                if(j==(i/j)){
                    tmp_d+=1;
                    tmp_h+=j;
                }
                else{
                    tmp_d+=2;
                    tmp_h+=(j+i/j);
                }
            }
        }
        arr_d[i]=tmp_d;
        arr_h[i]=tmp_h;
    }
}

void solve(){
    ll a,b,k;
    cin>>a>>b>>k;
    ll sum_d(0LL),sum_h(0LL);
    if(a%k!=0){
        a=a+k-a%k;
    }
    for(int i=a;i<=b;i+=k){
        sum_d+=arr_d[i];
        sum_h+=arr_h[i];
    }
    cout<<sum_d<<" "<<sum_h<<endl;
}
int main()
{
    fastio;
    divisors();
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}