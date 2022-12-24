/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
*/
#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"
 #define N 1000000


long long result[N+5];
long long phi[N+5];

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
        for(int j=i;j<=N;j+=i)result[j]+=phi[i]*i; //for all multiples of d phi[d]*d is added to result allowing us prefix phi[d]*d
        //this allows us to find the sum of all divisors multiplied with phi[d] for any particular n 
    }
}

int main()
{
    fastio;
    eulerTotient();
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
       cin>>n;
		cout<<((result[n]+1)*n)/2<< endl;
    }
    return 0;
}
