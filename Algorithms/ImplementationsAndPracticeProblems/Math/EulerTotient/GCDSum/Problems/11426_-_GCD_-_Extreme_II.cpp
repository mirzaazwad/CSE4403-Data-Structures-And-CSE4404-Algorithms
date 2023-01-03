/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
*/
#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"
 #define N 4000001


ll result[N+5];
ll phi[N+5];
ll pgcd[N+5];

void eulerTotient(){
    
    for(int i=0;i<=N;i++){
        phi[i]=i;
    }
    for(int i=2;i<=N;i++){
        if(phi[i]==i){
            for(int j=i+i;j<=N;j=j+i)phi[j]=(phi[j]*(i-1))/i;
            phi[i]=i-1;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=i<<1;j<=N;j+=i)result[j]+=(ll)phi[j/i]*i; //phi[1] for i<n should not be present so i+i
    }
    //G(n) = G(n-1) + S(n)
    for(int i=1;i<=N;i++){
        result[i]=result[i-1]+result[i]; 
    }

}

int main()
{
    fastio;
    eulerTotient();
    int n;
    cin>>n;
    while(n>0){
        cout<<result[n]<<endl;
       cin>>n;
    }
    return 0;
}
