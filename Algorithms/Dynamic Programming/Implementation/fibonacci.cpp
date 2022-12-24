#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==1 || n==0)return 1;
    else return fib(n-1)+fib(n-2);
}

int fib_dp(int n, int *arr){
    if(n==0 || n==1)return 1;
    if(arr[n]>0){
        return arr[n];
    }
    int output=fib_dp(n-1,arr)+fib_dp(n-2,arr);
    arr[n]=output;
    return output;
}

int fib_iterative(int n){
    int arr[n+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}

int main(void){
    int n;
    cin>>n;
    int arr[n+1]={0};
    cout<<fib_dp(n,arr)<<endl;
    cout<<fib_iterative(n)<<endl;
    cout<<fib(n)<<endl;
}
