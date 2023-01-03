#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
vector<int>primeList;
bool isPrime[1000006];

void sieve(){
    int n=1000006;
    memset(isPrime, false, sizeof(isPrime));
    isPrime[2]=true;//mark 2 as prime

    for(int i=3;i<=n;i+=2)isPrime[i]=true;//mark 3 and all odd numbers from 3 onwards as prime excluding the even numbers in the process
    for(int i=3;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=2*i)isPrime[j]=false;//this marks all odd multiples as not prime, since the even multiples are already marked as not prime, its not needed
	    //to repeat the process, thus making the algorithm more efficient.
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            primeList.push_back(i);//pushing all the prime numbers into a list on the basis of the colouring of the list. True means prime and false means not prime
        }
    }
}
long long reverseLong(long long N){
    string s;
    s=to_string(N);
    reverse(s.begin(),s.end());
    long long ans=0;
    int len=s.length();
    for(int i=0;i<len;i++){
        ans=ans*10+(s[i]-'0');
    }

    return ans;
}
int main()
{
    fastio;
    sieve();
    long long N;
    while(cin>>N){
        cout<<N<<" is ";
        if(isPrime[N]){
            long long rN=reverseLong(N);
            string ans=isPrime[rN] && rN!=N?"emirp":"prime";
            cout<<ans;
        }
        else{
            cout<<"not prime";
        }
        cout<<"."<<endl;
    }
    return 0;
}