/*
Coding Ninjas
Given a number N, find the total number
of divisors of the factorial of that number.

Since the answer can be very large
print it to modulo 10^9+7

Input:

The first line contains T, the number of test cases.
T lines follow each containing the number N.

Constraints
1<=T<=500
0<=N<=50000

Output:

Print T lines of output each containing the answer.

Test Case#1

Input: 
3
2
3 
4

Output:

2
4
8
*/

#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define N 50005
#define MOD 1000000007
using namespace std;

vector<int>primeList;
 bool isPrime[N+1];

void sieve(){
    memset(isPrime, false, sizeof(isPrime));
    isPrime[2]=true;//mark 2 as prime

    for(int i=3;i<=N;i+=2)isPrime[i]=true;//mark 3 and all odd numbers from 3 onwards as prime excluding the even numbers in the process
    for(int i=3;i*i<=N;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=N;j+=2*i)isPrime[j]=false;//this marks all odd multiples as not prime, since the even multiples are already marked as not prime, its not needed
	    //to repeat the process, thus making the algorithm more efficient.
        }
    }
}

long long factorial(long long n){
    if(n==0)return 1;
    else if(n==1)return 1;
    else return n*factorial(n-1);
}

int main()
{
    fastio;
    sieve();
    int t;
    cin >> t;
    
    while(t--)
    {
       long long n;cin>>n;
       long long val=factorial(n);
       long long res=1;
       for(long long i=1;i<=n;i++){
           if(isPrime[i]){
               long long k=i;
               long long cnt=0;
               while(n/k>0){
                   cnt=(cnt+(n/k))%MOD;
                   k*=i;
               }
               res=(res*(cnt+1)%MOD)%MOD;
           }
       }
       cout<<res<<endl;

    }
    return 0;
}
