//This is Codeforces 17A
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
vector<bool>g_isPrime;//global flag array for prime numbers, if g_isPrime[i]=false then it is not prime, else its prime
vector<int>primeList;
void sieve_of_eratosthenesis(int n){
    vector<bool>isPrime(n+1,false);
    isPrime[2]=true;

    for(int i=3;i<=n;i+=2)isPrime[i]=true;
    for(int i=3;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=2*i)isPrime[j]=false;
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            primeList.push_back(i);
        }
    }
    g_isPrime=isPrime;
}

bool isPrime(int n){
    for(int i=2;i*i<n;i++){
        if(n%i==0)return false;
    }
    return true;
}

int main()
{
    fastio;
    int n,k;
    cin>>n>>k;//taking inputs for n and k
    //generating prime Array
    sieve_of_eratosthenesis(n);
    int len=primeList.size();//finding length of primeList
    int cnt=0;
    for(int i=1;i<len;i++){
        if(primeList[i]+primeList[i-1]+1<=n && g_isPrime[primeList[i]+primeList[i-1]+1]){
            // cout<<primeList[i]+primeList[i-1]+1<<endl;just for checking
            // cout<<primeList[i]<<" "<<primeList[i-1]<<endl;just for checking
            cnt++;
        }
    }
    if(cnt>=k)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
