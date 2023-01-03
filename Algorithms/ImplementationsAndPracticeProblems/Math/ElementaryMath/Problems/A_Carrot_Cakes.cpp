#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,t,d;
    cin>>n>>t>>k>>d;
    int t1=0,t2=d;
     int totalTime=(n+k-1)/(k);
    totalTime*=t;
       for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            if(i*k+j*k>=n){
                int efficientTime=max(t1+i*t,t2+j*t);
                if(efficientTime<totalTime){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
