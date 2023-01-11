#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define N 100009
using namespace std;

bool isPrime[N+1];
vector<int>primeList;
void sieve(){
    int n=N;
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

void solve(){
    int n;
    cin>>n;
    int c=0;
    int arr[101];
    memset(arr,0,sizeof(arr));
    for(int i=2;i<=n;i++){
        for(int j=0;primeList[j]<=n;j++){
            int tmp=i;
            int count;
            for(count=0;tmp%primeList[j]==0;count++){
                tmp/=primeList[j];
            }
            arr[primeList[j]]+=count;
            c=max(c,primeList[j]);
        }
        
    }
    cout<<n<<" = ";
    bool first_time=false;
    for(int i=1;i<=c;i++){
        if(arr[i]>0){
            if(first_time){
                cout<<"* ";
            }
            cout<<i<<" ("<<arr[i]<<")"<<" ";
            first_time=true;
        }
        
    }
    cout<<endl;
}

int main()
{
    fastio;
    sieve();
    int t;
    cin >> t;
    
    for(int i=1;i<=t;i++)
    {
       cout<<"Case "<<i<<": ";
       solve();
    }
    return 0;
}