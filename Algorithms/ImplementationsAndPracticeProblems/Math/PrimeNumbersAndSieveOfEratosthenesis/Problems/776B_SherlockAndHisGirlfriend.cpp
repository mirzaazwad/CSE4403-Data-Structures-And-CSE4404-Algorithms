//Codeforces 776B
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

vector<bool>g_isPrime;
vector<int>primeList;

void sieve(int n){
    vector<bool>isPrime(n+1,false);
    isPrime[2]=true;
    for(int i=3;i<=n;i+=2)isPrime[i]=true;
    for(int i=3;i*i<=n;i++){
        if(isPrime[i])for(int j=i*i;j<=n;j+=2*i)isPrime[j]=false;
    }
    g_isPrime=isPrime;
    for(int i=2;i<=n;i++){
        if(isPrime[i])primeList.push_back(i);
    }
}


int main()
{
    fastio;
    int n;
    cin>>n;
    sieve(n+3);
    int cnt=0;
    vector<int>color;
    for(int i=2;i<=n+1;i++){
        if(g_isPrime[i]){
            color.push_back(1);
        }
        else{
            color.push_back(2);
        }
    }
    if(n<=2){
        cout<<1<<endl;
        for(int i=0;i<n;i++)cout<<1<<" ";
        cout<<endl;
        return 0;
    }
    cout<<2<<endl;
    int len=color.size();
    for(int i=0;i<len;i++)cout<<color[i]<<" ";
    cout<<endl;
    return 0;
}
