/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
*/
#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"
#define N 1001
map<int,int>mp;


void divisors(){
    mp[1]=1;
    for(int i=2;i<=N;i++){
        ll tmp_h(0LL),tmp_d(0LL);
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                if(j==(i/j)){
                    tmp_h+=j;
                }
                else{
                    tmp_h+=(j+i/j);
                }
            }
        }
        mp[tmp_h]=i;
    }
}

 

void solve(int num){
    if(mp.find(num)!=mp.end())cout<<mp[num]<<endl;
    else cout<<-1<<endl;
}
int main()
{
    divisors();
    fastio;
    int S;
    int i=1;
    while(cin>>S,S>0){
        cout<<"Case "<<i<<": ";
        solve(S);
        i++;
    }
    return 0;
}
