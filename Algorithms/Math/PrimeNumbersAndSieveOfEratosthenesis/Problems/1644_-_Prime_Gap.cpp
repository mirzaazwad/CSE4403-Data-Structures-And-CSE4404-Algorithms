#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define N 1299709
using namespace std;

vector<int>primeList;
bool isPrime[N+1]={false};

void sieve(){
    int n=N;
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

int main()
{
    fastio;
    sieve();
    int n;
    while(cin>>n){
        if(!n)break;
        int UB,LB;
        if(isPrime[n]){
            cout<<0<<endl;
            continue;
        }
        UB=n+1;
        LB=n-1;
        while(!isPrime[UB]){
            UB++;
        }
        while(!isPrime[LB]){
            LB--;
        }
        cout<<UB-LB<<endl;

    }
    return 0;
}