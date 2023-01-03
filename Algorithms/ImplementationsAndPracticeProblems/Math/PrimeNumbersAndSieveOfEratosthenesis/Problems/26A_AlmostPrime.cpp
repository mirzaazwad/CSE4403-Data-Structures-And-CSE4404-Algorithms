//This is a codeforces problem 26A Almost prime
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




int main()
{
    fastio;
    int n;
    cin>>n;
    int cnt=0;
    sieve_of_eratosthenesis(n);
    int ans=0;
    for(int i=5;i<=n;i++){
        int val=i;
        int cnt=0;
        for(auto u:primeList){
            if(val%u==0){
                while(val%u==0){
                    val/=u;
                }
                cnt++;
            }
            if(val==1)break;
            if(val!=1 && cnt==2){
                cnt++;
                break;
            }
        }
        if(cnt==2){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
